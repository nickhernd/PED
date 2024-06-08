#ifndef _tavlcalendario_ 
#define _tavlcalendario_

#include <iostream>
#include <queue>
using namespace std;

#include "tcalendario.h"
#include "tvectorcalendario.h"

class TNodoAVL;

class TAVLCalendario{
    friend class TNodoAVL;
    friend ostream & operator<< (ostream &, const TAVLCalendario &);

    private:
        TNodoAVL *raiz;

        void Copia(const TAVLCalendario &);

        void InordenAux(TVectorCalendario &, int &) const;
        void PreordenAux(TVectorCalendario &, int &) const;
        void PostordenAux(TVectorCalendario &, int &) const;
        
        TCalendario Ordenar() const;
        void Equilibrar();
        void ActualizarFE();
        int CalcularFE();

    public:
        TAVLCalendario();
        TAVLCalendario(const TAVLCalendario &);
        ~TAVLCalendario();
        TAVLCalendario & operator= (const TAVLCalendario &);

        bool operator==(const TAVLCalendario &) const;
        bool operator!=(const TAVLCalendario &) const;

        bool EsVacio() const ;
        bool Insertar(const TCalendario &);
        bool Borrar(const TCalendario &);

        bool Buscar(const TCalendario &) const ;

        TCalendario Raiz() const ;
        int Altura() const ;
        int Nodos() const ;
        int NodosHoja() const ;

        TVectorCalendario Inorden() const;
        TVectorCalendario Preorden() const;
        TVectorCalendario Postorden() const;
};

class TNodoAVL{
    friend class TAVLCalendario;
    
    private:
        TCalendario item;
        TAVLCalendario iz, de;

        int fe;

        void Copia(const TNodoAVL &);

    public:
        TNodoAVL();
        TNodoAVL(const TNodoAVL &);
        ~TNodoAVL();

        TNodoAVL & operator= (const TNodoAVL &);
};

#endif