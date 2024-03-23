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
    bool esBisiesto(int) const;
    bool comprobarFecha(int, int, int) const;

public:
    // CONSTRUCTORES
    TVectorCalendario();
    TVectorCalendario(int);
    TVectorCalendario(const TVectorCalendario &);
    ~TVectorCalendario();       
    TVectorCalendario &operator=(const TVectorCalendario &);

    // MÉTODOS
    int Tamano() const;
    int Ocupadas() const;
    bool ExisteCal(const TCalendario &) const;
    void MostrarMensajes(int, int, int) const;
    bool Redimensionar(int);

    // OPERADORES
    bool operator==(const TVectorCalendario &) const;
    bool operator!=(const TVectorCalendario &) const;
    TCalendario &operator[](int);
    TCalendario operator[](int) const;

    // FUNCIONES AMIGAS
    friend ostream &operator<<(ostream &, TVectorCalendario &);
};

#endif


