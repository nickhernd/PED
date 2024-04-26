#ifndef _TABBCALENDARIO_H_
#define _TABBCALENDARIO_H_

#include <iostream>
#include <queue>
using namespace std;

#include "tcalendario.h"
#include "tvectorcalendario.h"

class TNodoABB;

class TABBCalendario {
    friend class TNodoABB;
    
    private:
        TNodoABB *raiz;
        void InordenAux(TVectorCalendario& v, int& pos) const;
        void PreordenAux(TVectorCalendario& v, int& pos) const;
        void PostordenAux(TVectorCalendario& v, int& pos) const;

        void CopiaArbol(const TABBCalendario &abb);
        TCalendario Ordenar() const;

    public:
        //FORMA CANONICA
        TABBCalendario();
        TABBCalendario(const TABBCalendario &abb);
        ~TABBCalendario();
        TABBCalendario & operator=(const TABBCalendario &);

        //OPERADORES
        bool operator==( TABBCalendario& abb) ;
        TABBCalendario operator+(const TABBCalendario& abb) const;
        TABBCalendario operator-(const TABBCalendario& abb) const;
        friend ostream& operator<<(ostream& os, const TABBCalendario& abb);

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

        TABBCalendario operator+(TABBCalendario &);
        TABBCalendario operator-(TABBCalendario &);
};

class TNodoABB {
    friend class TABBCalendario;
    private:
        TCalendario item;
        TABBCalendario iz; 
        TABBCalendario de;
        void CopiaNodo(const TNodoABB &nodo);

    public:
        TNodoABB(); //HACHO
        TNodoABB(const TNodoABB& nodo); // HECHO
        ~TNodoABB(); // HECHO
        TNodoABB & operator=(const TNodoABB &); // HECHO
};

#endif
