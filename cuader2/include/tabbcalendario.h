#ifndef _TABBCALENDARIO_H_
#define _TABBCALENDARIO_H_

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"

using namespace std;

class TNodoABB {
    friend class TABBCalendario;
    private:
        TCalendario item;
        TABBCalendario iz, de;

    public:
        TNodoABB();
        TNodoABB(TNodoABB &);
        ~TNodoABB();
        TNodoABB & operator=(TNodoABB & const) const;
};

class TABBCalendario {
    friend class TNodoABB;
    friend ostream & operator<<(ostream &, TABBCalendario &);

    private:
        TNodoABB *raiz;
        void InordenAux(TVectorCalendario &, int &);
        void PreordenAux(TVectorCalendario &, int &);
        void PostordenAux(TVectorCalendario &, int &);

    public:
        //FORMA CANONICA
        TABBCalendario();
        TABBCalendario(TABBCalendario &);
        ~TABBCalendario();
        TABBCalendario & operator=(TABBCalendario & const) const;

        bool operator==( TABBCalendario &);
        bool EsVacio();
        bool Insertar(TCalendario &);
        bool Borrar(TCalendario &);
        bool Buscar(TCalendario &);
        TCalendario Raiz();
        int Altura();
        int Nodos();
        int NodosHoja();
        TVectorCalendario Inorden();
        TVectorCalendario Preorden();
        TVectorCalendario Postorden();
        TVectorCalendario Niveles();
        TABBCalendario operator+( TABBCalendario &);
        TABBCalendario operator-( TABBCalendario &);

};

#endif
