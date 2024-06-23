#ifndef _TABBCALENDARIO_H_
#define _TABBCALENDARIO_H_

#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

class TNodoABB;

class TABBCalendario {
    friend class TNodoABB;

private:
    TNodoABB *raiz;
    void InordenAux(TVectorCalendario &, int &) const;
    void PreordenAux(TVectorCalendario &, int &) const;
    void PostordenAux(TVectorCalendario &, int &) const;
    void CopiarArbol(const TABBCalendario &);
    TNodoABB* MayorIzda();

public:
    TABBCalendario();
    TABBCalendario(const TABBCalendario &);
    ~TABBCalendario();
    TABBCalendario & operator=(const TABBCalendario &);
    bool operator==(const TABBCalendario &) const;
    bool EsVacio() const;
    bool Insertar(TCalendario &);
    bool Borrar(const TCalendario &);
    bool Buscar(const TCalendario &) const;
    TCalendario Raiz() const;
    int Altura() const;
    int Nodos() const;
    int NodosHoja() const;
    TVectorCalendario Inorden() const;
    TVectorCalendario Preorden() const;
    TVectorCalendario Postorden() const;
    TVectorCalendario Niveles() const;
    TABBCalendario operator+(const TABBCalendario &) const;
    TABBCalendario operator-(const TABBCalendario &) const;
    friend ostream & operator<<(ostream &, const TABBCalendario &);
};

class TNodoABB {
    friend class TABBCalendario;

private:
    TCalendario item;
    TABBCalendario iz, de;
    bool EsHoja();

public:
    TNodoABB();
    TNodoABB(const TNodoABB &);
    ~TNodoABB();
    TNodoABB & operator=(const TNodoABB &);
};

#endif