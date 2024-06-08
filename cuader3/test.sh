#!/bin/bash
clear

# Directorios de prueba y salida
directorio_pruebas=$1
directorio_salidas="salidas_pruebas"
directorio_src="src"

# Contadores para pruebas superadas y totales
tests_superados=0
tests_totales=0
test_number=0

# Función para ejecutar las pruebas en un directorio específico
run_tests() {
    local directorio=$1
    local tipo_de_prueba=$2
    
    for test_file in "$directorio"/tad*.cpp; do
        # Obtener el número de test
        ((test_number+=1))
        
        formatted_test_number=$(printf "%02d" "$test_number")
        echo "Prueba $tipo_de_prueba $formatted_test_number"
        
        # Construir rutas de archivos
        main_file="$directorio_src/main.cpp"
        salida_esperada="$directorio/tad$formatted_test_number.cpp.sal"
        output_file="output.txt"
        
        # Verificar si el archivo de salida esperada existe
        if [ ! -f "$salida_esperada" ]; then
            echo "El archivo de salida esperada $salida_esperada no existe. Saltando prueba."
            continue
        fi
        
        cp "$salida_esperada" "salida_esperada.cpp.sal"
        
        # Copiar el archivo de prueba a un archivo temporal
        cp "$test_file" "$directorio_src/main.cpp"
        
        # Compilar el programa
        make
        
        # Verificar si la compilación fue exitosa
        if [ $? -ne 0 ]; then
            echo "Error en la compilación para la prueba $formatted_test_number"
            continue
        fi
        
        # Ejecutar el programa y almacenar la salida en un archivo temporal
        ./tad > "$output_file"
        ((tests_totales+=1))
        
        echo "Comprobando: $test_file"
        diff -b -B -i "$output_file" "salida_esperada.cpp.sal"
        if [ "$?" == "0" ]; then
            echo "OK"
            ((tests_superados+=1))
        else
            echo "ERROR"
        fi
        
        echo "************************************************************************************"
    done
}

# Ejecutar pruebas en el directorio tavlcalendarioC
run_tests "tavlcalendarioC" "Correctas"

# Reiniciar contadores para las pruebas en tavlcalendarioP
test_number=0

# Ejecutar pruebas en el directorio tavlcalendarioP
run_tests "tavlcalendarioP" "Patológicas"

# Mostrar el resumen final
echo "Resumen Final: Se superaron $tests_superados de $tests_totales pruebas."