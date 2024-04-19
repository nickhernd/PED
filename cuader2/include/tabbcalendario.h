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
        TNodoABB(); //HACHO
        TNodoABB(const TNodoABB& nodo); // HECHO
        ~TNodoABB(); // HECHO
        TNodoABB & operator=(TNodoABB & const); // HECHO
};

class TABBCalendario {
    friend class TNodoABB;
    friend ostream & operator<<(ostream &, TABBCalendario &);

    private:
        TNodoABB *raiz;
        void InordenAux(TVectorCalendario& v, int& pos) const;
        void PreordenAux(TVectorCalendario& v, int& pos) const;
        void PostordenAux(TVectorCalendario& v, int& pos) const;
        TNodoABB* CopiarSubarbol(TNodoABB* nodo) const;
        void BorrarSubarbol(TNodoABB* nodo);

    public:
        //FORMA CANONICA
        TABBCalendario();
        TABBCalendario(TABBCalendario &abb);
        ~TABBCalendario();
        TABBCalendario & operator=(TABBCalendario & const);

        //OPERADORES
        bool operator==(const TABBCalendario& abb) const;
        TABBCalendario operator+(const TABBCalendario& abb) const;
        TABBCalendario operator-(const TABBCalendario& abb) const;
        friend std::ostream& operator<<(std::ostream& os, const TABBCalendario& abb);

        //METODDOS
        bool EsVacio() const { return raiz == nullptr; }
        bool Insertar(const TCalendario& c);
        bool Borrar(const TCalendario& c);
        bool Buscar(const TCalendario& c) const;
        TCalendario Raiz() const;
        int Altura() const;
        int Nodos() const;
        int NodosHoja() const;
        TVectorCalendario Inorden() const;
        TVectorCalendario Preorden() const;
        TVectorCalendario Postorden() const;
        TVectorCalendario Niveles() const;
};

#endif
