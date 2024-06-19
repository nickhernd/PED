#ifndef _tabbcalendario_ 
#define _tabbcalendario_

#include <iostream>
#include <queue>
using namespace std;

#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"   //Añadimos el include

class TNodoABB;

class TABBCalendario{
    friend class TNodoABB;
    friend ostream & operator<< (ostream &,const TABBCalendario &);

    private:
        TNodoABB *raiz;

        void Copia(const TABBCalendario &);

        void InordenAux(TVectorCalendario &, int &) const;
        void PreordenAux(TVectorCalendario &, int &) const;
        void PostordenAux(TVectorCalendario &, int &) const;
        
        TCalendario Ordenar() const;

        //EXAMEN!!: Método auxiliar para la selección del camino hacia un TCalendario                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
        void ElegirSubarbol(TCalendario &, TVectorCalendario &v);


    public:
        TABBCalendario();
        TABBCalendario(const TABBCalendario &);
        ~TABBCalendario();
        TABBCalendario & operator= (const TABBCalendario &);

        bool operator==(const TABBCalendario &) const;

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

        TVectorCalendario Niveles() const;

        TABBCalendario operator+ (TABBCalendario &);
        TABBCalendario operator- (TABBCalendario &);

        //EXAMEN!!: Método principal para inserción de Nodos en el ABB (consultar enunciado)
        TVectorCalendario ABBCamino(TListaCalendario &);
};

class TNodoABB{
    friend class TABBCalendario;
    
    private:
        TCalendario item;
        TABBCalendario iz, de;
        void Copia(const TNodoABB &);

    public:
        TNodoABB();
        TNodoABB(const TNodoABB &);
        ~TNodoABB();

        TNodoABB & operator= (const TNodoABB &);
};

#endif