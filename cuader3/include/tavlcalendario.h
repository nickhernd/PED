#ifndef _TAVLCALENDARIO_H_
#define _TAVLCALENDARIO_H_

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

using namespace std;

class TNodoAVL;
class TColaAVLCalendario;

//! Clase TAVLCalendario
/*! Clase que representa el un arbol avl*/
class TAVLCalendario {
    private:
        //! raiz
        /*! Variable de tipo puntero a TNodoAVL que apunta al arbol */
        TNodoAVL *raiz;
        //! InordenAux
        /*! Funcion privada InordenAux */
        void InordenAux(TVectorCalendario &, int &)const;
        //! PreordenAux
        /*! Funcion privada PreordenAux */
        void PreordenAux(TVectorCalendario &, int &)const;
        //! PostordenAux
        /*! Funcion privada PostordenAux */
        void PostordenAux(TVectorCalendario &, int &)const;
        //! MayorIzda
        /*! Funcion privada MayorIzda */
        TNodoAVL * MayorIzda() const;
        //! NivelesAux
        /*! Funcion privada NivelesAux */
        void NivelesAux(TColaAVLCalendario &);
        //! Copiar
        /*! Funcion privada Copiar */
        void Copiar(const TAVLCalendario &);

        int BuscarYClasificar(TCalendario &) const;
        TListaCalendario ConstruirCamino(const TCalendario &);

    public:
        //! Constructor
        /*! Constructor por defecto de la clase TAVLCalendario */
        TAVLCalendario ();
        //! Constructor de copia
        /*! Constructor por copia de la clase TAVLCalendario */
        TAVLCalendario (const TAVLCalendario &);
        //! Destructor
        /*! Destructor de la clase TAVLCalendario */
        ~ TAVLCalendario ();
        //! Operador asignacion
        /*! Operador asignacion de la clase TAVLCalendario */
        TAVLCalendario & operator=(const TAVLCalendario &);
        //! Operador igualdad
        /*! Operador igualdad de la clase TAVLCalendario */
        bool operator==(const TAVLCalendario &)const;
        //! Operador desigualdad
        /*! Operador desigualdad de la clase TAVLCalendario */
        bool operator!=(const TAVLCalendario &)const;
        //! Funcion EsVacio
        /*! Funcion EsVacio de la clase TAVLCalendario */
        bool EsVacio()const;
        //! Funcion Insertar
        /*! Funcion Insertar de la clase TAVLCalendario */
        bool Insertar(TCalendario &);
        //! Funcion Buscar
        /*! Funcion Buscar de la clase TAVLCalendario */
        bool Buscar(const TCalendario &);
        //! Funcion Altura
        /*! Funcion Altura de la clase TAVLCalendario */
        int Altura()const;
        //! Funcion Nodos
        /*! Funcion Nodos de la clase TAVLCalendario */
        int Nodos()const;
        //! Funcion NodosHoja
        /*! Funcion NodosHoja de la clase TAVLCalendario */
        int NodosHoja()const;
        //! Funcion Inorden
        /*! Funcion Inorden de la clase TAVLCalendario */
        TVectorCalendario Inorden()const;
        //! Funcion Preorden
        /*! Funcion Preorden de la clase TAVLCalendario */
        TVectorCalendario Preorden()const;
        //! Funcion Postorden
        /*! Funcion Postorden de la clase TAVLCalendario */
        TVectorCalendario Postorden()const;
        //! Funcion Borrar
        /*! Funcion Borrar de la clase TAVLCalendario */
        bool Borrar(const TCalendario &);
        //! Funcion Niveles
        /*! Funcion Niveles de la clase TAVLCalendario */
        TVectorCalendario Niveles();
        //! Funcion Raiz
        /*! Funcion Raiz de la clase TAVLCalendario */
        TCalendario Raiz() const;

        int* BuscaAVL (TListaCalendario &);
        TListaCalendario Caminos_AVL(TVectorCalendario &);

        friend ostream& operator<<(ostream &,const TAVLCalendario &);
};

//! Clase TNodoAVL
/*! Clase que representa el nodo de un arbol avl */
class TNodoAVL {
    friend class TAVLCalendario;

    private:
        //! item
        /*! Variable de tipo TCalendario */
        TCalendario item;
        //! iz, de
        /*! Variables de tipo TAVLCalendario */
        TAVLCalendario iz, de;
        //! fe
        /*! Variable de tipo entero */
        int fe;
        //! EsHoja
        /*! Funcion privada EsHoja */
        bool EsHoja() const;

    public:
        //! Constructor
        /*! Constructor por defecto de la clase TNodoAVL */
        TNodoAVL ();
        //! Constructor de copia
        /*! Constructor de copia de la clase TNodoAVL */
        TNodoAVL (const TNodoAVL &);
        //! Destructor
        /*! Destructor de la clase TNodoAVL */
        ~TNodoAVL ();
        //! Operador asignacion
        /*! Operador asignacion de la clase TNodoAVL */
        TNodoAVL & operator=(const TNodoAVL &);
};

class TElemColaAVLCalendario;
//! Clase TColaAVLCalendario
/*! Clase que representa el la cola de un arbol avl */
class TColaAVLCalendario {
    private:
        //! item
        /*! Variable de tipo TElemColaAVLCalendario que apunta al primero de la cola */
        TElemColaAVLCalendario *primero;
        //! item
        /*! Variable de tipo TElemColaAVLCalendario que apunta al ultimo de la cola */
        TElemColaAVLCalendario *ultimo;

    public:
        //! Constructor
        /*! Constructor por defecto de la clase TColaAVLCalendario */
        TColaAVLCalendario ();
        //! Constructor
        /*! Constructor de copia de la clase TColaAVLCalendario */
        TColaAVLCalendario (const TColaAVLCalendario &);
        //! Destructor
        /*! Destructor de la clase TColaAVLCalendario */
        ~ TColaAVLCalendario ();
        //! Operador asignacion
        /*! Operador asignacion de la clase TColaAVLCalendario */
        TColaAVLCalendario & operator=(const TColaAVLCalendario &);
        //! Operador igualdad
        /*! Operador igualdad de la clase TColaAVLCalendario */
        bool operator==(const TColaAVLCalendario &);
        //! Operador suma
        /*! Operador suma de la clase TColaAVLCalendario */
        TColaAVLCalendario operator+(const TColaAVLCalendario &);
        //! Funcion EsVacia
        /*! Funcion EsVacia de la clase TColaAVLCalendario */
        bool EsVacia()const;
        //! Funcion Encolar
        /*! Funcion Encolar de la clase TColaAVLCalendario */
        bool Encolar(TAVLCalendario *);
        //! Funcion Desencolar
        /*! Funcion Desencolar de la clase TColaAVLCalendario */
        bool Desencolar();
        //! Funcion Cabeza
        /*! Funcion Cabeza de la clase TColaAVLCalendario */
        TAVLCalendario *Cabeza()const;
        //! Funcion Longitud
        /*! Funcion Longitud de la clase TColaAVLCalendario */
        int Longitud()const;
};

//! Clase TElemColaAVLCalendario
/*! Clase que representa el elemento de la cola de un arbol */
class TElemColaAVLCalendario {
    friend class TColaAVLCalendario;

    private:
        //! arbol
        /*! Variable de tipo TAVLCalendario de puntero a arbol */
        TAVLCalendario *arbol;
        //! sig
        /*! Variable de tipo TElemColaAVLCalendario de puntero a sig */
        TElemColaAVLCalendario *sig;

    public:
        //! Constructor
        /*! Constructor por defecto de la clase TElemColaAVLCalendario */
        TElemColaAVLCalendario ();
        //! Constructor de copia
        /*! Constructor de copia de la clase TElemColaAVLCalendario */
        TElemColaAVLCalendario (const TElemColaAVLCalendario &);
        //! Operador asignacion
        /*! Operador asignacion de la clase TElemColaAVLCalendario */
        TElemColaAVLCalendario & operator=(const TElemColaAVLCalendario &);
        //! Destructor
        /*! Destructor de la clase TElemColaAVLCalendario. Se llama implicitamente al destructor de TAVLCalendario */
        ~TElemColaAVLCalendario (){}
        //! Funcion Arbol
        /*! Funcion Arbol de la clase TColaAVLCalendario */
        TAVLCalendario* Arbol();
};

#endif
