#define _TVECTORCALENDARIO_H_
#ifdef _TVECTORCALENDARIO_H_

#include "tcalendario.h"
#include <iostream>

using namespace std;

class TVectorCalendario {
    private:
        TCalendario *c;
        int tamano;
        TCalendario error;
        bool esBisiesto(int);
        bool comprobarFecha(int, int, int);

    public:
        // CONSTRUCTORES
        TVectorCalendario();
        TVectorCalendario(int);
        TVectorCalendario(TVectorCalendario &);
        ~TVectorCalendario();
        TVectorCalendario & operator=(const TVectorCalendario &);

        // MÉTODOS
        // Sobrecarga del operador igualdad
        bool operator==(TVectorCalendario &);
        // Sobrecarga del operador desigualdad
        bool operator!=(TVectorCalendario &);
        // Sobrecarga del operador corchete (parte IZQUIERDA)
        TCalendario & operator[](int);
        // Sobrecarga del operador corchete (parte DERECHA)
        TCalendario operator[](int) const;
        // Tamaño del vector (posiciones TOTALES)
        int Tamano() {return this->tamano;};
        // Cantidad de posiciones OCUPADAS (no vacías) en el vector
        int Ocupadas();
        // Devuelve TRUE si existe el calendario en el vector
        bool ExisteCal(TCalendario &);
        // Mostrar por pantalla mensajes de TCalendario en el vector, de fecha IGUAL O
        void MostrarMensajes(int,int,int);
        // REDIMENSIONAR el vectorde TCalendario
        bool Redimensionar(int);

        //FUNCIONES AMIGAS
        // Sobrecarga del operador salida
        friend ostream & operator<<(ostream &, TVectorCalendario &);

};

#endif

