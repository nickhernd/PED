#ifndef _TVECTORCALENDARIO_H_
#define _TVECTORCALENDARIO_H_

#include "tcalendario.h"
#include <iostream>

using namespace std;

class TVectorCalendario {
private:
    TCalendario *c;
    int tamano;
    TCalendario error;
    bool esBisiesto(int) ;
    bool comprobarFecha(int, int, int) ;

public:
    // CONSTRUCTORES
    TVectorCalendario();
    TVectorCalendario(int);
    TVectorCalendario(const TVectorCalendario &);
    ~TVectorCalendario();       
    TVectorCalendario &operator=(const TVectorCalendario &);

    // MÉTODOS
    int Tamano() const;
    int Ocupadas();
    bool ExisteCal(TCalendario &);
    void MostrarMensajes(int, int, int);
    bool Redimensionar(int);

    // OPERADORES
    bool operator==(TVectorCalendario &);
    bool operator!=(TVectorCalendario &);
    TCalendario &operator[](int);
    TCalendario operator[](int) const;

    // FUNCIONES AMIGAS
    friend ostream &operator<<(ostream &, TVectorCalendario &);
};

#endif


