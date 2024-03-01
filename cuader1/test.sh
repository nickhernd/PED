#!/bin/bash
clear

# Directorios de prueba y salida
directorio_pruebas="Ficheros de prueba cuadernillo 1"
directorio_salidas="salidas_pruebas"
directorio_src="src"

# Tipo de prueba
tipo_de_prueba="tcalendario"
# Puedes cambiar el tipo de prueba según tus necesidades

# Contadores para pruebas superadas y totales
tests_superados=0
tests_totales=0
test_number=0
<< HOLA
# Compilar y ejecutar cada archivo .cpp en src
for test_file in "$directorio_pruebas/$tipo_de_prueba"/tad*.cpp; do
    # Obtener el número de test
    ((test_number+=1))
    
    formatted_test_number=$(printf "%02d" "$test_number")

    # Construir rutas de archivos
    main_file="$directorio_src/main.cpp"
    cp "$directorio_pruebas/$tipo_de_prueba/tad$formatted_test_number.cpp.sal" "salida_esperada.cpp.sal"
    output_file="output.txt"

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
    #valgrind ./tad
    ./tad > "$output_file"
    ((tests_totales+=1))

    echo "Comprobando: " "$testfile"
    diff -b -B -i "$output_file" "salida_esperada.cpp.sal"
    if [ "$?" == "0" ]; then
		echo "OK"
        ((tests_superados+=1))
	else
		echo "ERROR"
	fi
    
    echo "************************************************************************************"
done
HOLA
tipo_de_prueba="tvectorcalendario"

# Compilar y ejecutar cada archivo .cpp en src
for test_file in "$directorio_pruebas/$tipo_de_prueba"/tad*.cpp; do
    # Obtener el número de test
    ((test_number+=1))
    
    formatted_test_number=$(printf "%02d" "$test_number")

    # Construir rutas de archivos
    main_file="$directorio_src/main.cpp"
    cp "$directorio_pruebas/$tipo_de_prueba/tad$formatted_test_number.cpp.sal" "salida_esperada.cpp.sal"
    output_file="output.txt"

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
    #valgrind ./tad
    ./tad > "$output_file"
    ((tests_totales+=1))

    echo "Comprobando: " "$testfile"
    diff -b -B -i "$output_file" "salida_esperada.cpp.sal"
    if [ "$?" == "0" ]; then
		echo "OK"
        ((tests_superados+=1))
	else
		echo "ERROR"
	fi
    
    echo "************************************************************************************"
done

<< 'HOLA'
tipo_de_prueba="tlistcalendario"
# Compilar y ejecutar cada archivo .cpp en src
for test_file in "$directorio_pruebas/$tipo_de_prueba"/tad*.cpp; do
    # Obtener el número de test
    ((test_number+=1))
    
    formatted_test_number=$(printf "%02d" "$test_number")

    # Construir rutas de archivos
    main_file="$directorio_src/main.cpp"
    cp "$directorio_pruebas/$tipo_de_prueba/tad$formatted_test_number.cpp.sal" "salida_esperada.cpp.sal"
    output_file="output.txt"

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
    valgrind ./tad
    ./tad > "$output_file"
    ((tests_totales+=1))

    echo "Comprobando: " "$testfile"
    diff -b -B -i "$output_file" "salida_esperada.cpp.sal"
    if [ "$?" == "0" ]; then
		echo "OK"
        ((tests_superados+=1))
	else
		echo "ERROR"
	fi
    
    echo "************************************************************************************"
done
HOLA


# Mostrar el resumen final
echo "Resumen Final: Gilipollas que vas a suspender. Superados " "$tests_superados" "/" "$tests_totales"
