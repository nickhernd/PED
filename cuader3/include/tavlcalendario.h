#ifndef _TAVLCALENDARIO_H_
#define _TAVLCALENDARIO_H_

#include <iostream>
#include <string.h>
#include "tvectorcalendario.h"

class TNodoABB;

class TAVLCalendario {
    friend ostream & operator<<(ostream &,const TAVLCalendario);

    private:

        // Puntero al nodo
        TNodoABB *raiz;

        void InordenAux(TVectorCalendario &, int &) const;
        void PreordenAux(TVectorCalendario &, int &) const;
        void PostordenAux(TVectorCalendario &, int &) const;

        void Copiar(const TAVLCalendario &);
        bool Iguales(const TAVLCalendario &);
        TCalendario mayorIz();

    public:

        TAVLCalendario();
        TAVLCalendario(const TAVLCalendario &);
        ~TAVLCalendario();
        TAVLCalendario & operator=(const TAVLCalendario &);

        bool operator==(const TAVLCalendario &);
        bool EsVacio() const;
        bool Insertar(TCalendario &);
        bool Borrar( TCalendario &);

        bool Buscar(const TCalendario &) const;
        TCalendario Raiz() const;
        int Altura() const;
        int Nodos() const;
        int NodosHoja() const;

        TVectorCalendario Inorden() const;
        TVectorCalendario Preorden() const;
        TVectorCalendario Postorden() const;
        TVectorCalendario Niveles() const;

        TAVLCalendario operator+(const TAVLCalendario &);
        TAVLCalendario operator-(const TAVLCalendario &);
};

class TNodoABB
{
    friend class TAVLCalendario;

    private:

        TCalendario item;
        TAVLCalendario iz, de;

    public:

        TNodoABB();
        TNodoABB(const TNodoABB &);
        ~TNodoABB();
        TNodoABB & operator=(const TNodoABB &);
};

#endif