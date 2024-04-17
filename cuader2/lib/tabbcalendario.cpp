#include "tabbcalendario.h"
#include <queue>

class TNodoABB {
    TNodoABB::TNodoABB() : iz(nullptr), de(nullptr) {}

    TNodoABB::TNodoABB(const TNodoABB& nodo) : item(nodo.item), iz(nullptr), de(nullptr) {
    if (nodo.iz) {
        iz = new TNodoABB(*nodo.iz);
    }
    if (nodo.de) {
        de = new TNodoABB(*nodo.de);
    }
}

    TNodoABB::~TNodoABB() {
        delete iz;
        delete de;
        this->item = new TCalendario();
    }

    TNodoABB& TNodoABB::operator=(const TNodoABB& nodo) {
        if (this != &nodo) {
            item = nodo.item;
            delete iz;
            delete de;
            iz = nullptr;
            de = nullptr;
                if (nodo.iz) {
                    iz = new TNodoABB(*nodo.iz);
                }

                if (nodo.de) {
                    de = new TNodoABB(*nodo.de);
                }
        }
        return *this;
    }
};

class TAABCalendario {
    TABBCalendario::TABBCalendario() : raiz(nullptr) {}
    
    void TAABCalendario::InordenAux(TVectorCalendario &vec, int &num) {
       

    }

    void TAABCalendario::PreordenAux(TVectorCalendario &vec, int &num) {


        vec[num].c = raiz.item;
        PreordenAux()
    }

    void TAABCalendario::PostordenAux() {

    }

    TAABCalendario() 
    {
        this->raiz = NULL;
    }


    TABBCalendario(TABBCalendario &obj)
    {
        this->raiz = NULL;
    }

    ~TAABCalendario() 
    {
        delete raiz;
        this->raiz = NULL;
    }

    TAABCalendario &TAABCalendario::operator=(const TAABCalendario &tabb) const {
        if(raiz == nullptr)  {
            raiz = tabb.raiz;
            raiz.de = tabb.raiz.de;
            raiz.iz = tabb.raiz.iz;
        }

        this.Insertar(tabb.raiz.item);
        do {
            this.Insertar(tabb.raiz.iz.item);
            this.Insertar(tabb.raiz.de.item);
        } while()
    }

    bool operator==( TABBCalendario &tabb) {

    }
    
    bool Insertar(TCalendario &cal) {
        if(raiz = nullptr) {
            raiz.item = cal;
            return true;
        }

        if(Buscar(cal)) return false;
        TNodoABB *actual = new TNodoABB();
        TNodoABB *nextNodo = new TNodoABB();
        actual = raiz;
                
        do {
            if(cal > actual.item) nextNodo = actual.de;
            else if(cal < actual.item) nextNodo = actual.iz;
        } while (nextNodo != nullptr);

        if(cal > actual.item) actual.de.item = cal;
        else actual.iz.item = cal;

        return true; 

    }

    bool Borrar(TCalendario &cal) {
        if(!Buscar(cal)) return false;

        
    }

    bool Buscar(TCalendario &cal) {
        if(raiz == nullptr) return false;
        if(raiz.item == cal) return true;
        TNodoABB *nextNodo = new TNodoABB();
        nextNodo = raiz;
        do {
            if(cal > nextNodo.item) nextNodo = nextNodo.de;
            else if(cal < nextNodo.item) nextNodo = nextNodo.iz;
            else return true;
        } while (nextNodo != nullptr);

        delete nextNodo;
    
        return false;
    }
     
    TCalendario Raiz() {
        return raiz.item;
    }

    int Altura() {
        if(raiz = nullptr) {
            return 0;
        }

        return 1 + max(raiz.iz.Altura(), raiz.de.Altura());
    } 

    int Nodos() {
        if(raiz = nullptr) {
            return 0;
        }

        return 1 + raiz.iz.Nodos() + raiz.de.Nodos();
    }

    int NodosHoja() {
        if(raiz.de == nullptr && raiz.iz == nullptr) return 0;
        if(raiz.de != nullptr && raiz.iz == nullptr) return raiz.de.NodosHoja();
        else if(raiz.de == nullptr && raiz.iz != nullptr) return raiz.iz.NodosHoja();
        else return raiz.de.NodosHoja() + raiz.iz.NodosHoja();
    } 

    /*TVectorCalendario Inorden() {
        int posición = 1;
        // Vector del tamaño adecuado para almacenar todos los nodos
        TVectorCalendario v(Nodos());
        InordenAux(v, posicion);
        return v;
    }*/

    TVectorCalendario Inorden() {
        int posición = 1;
        // Vector del tamaño adecuado para almacenar todos los nodos
        TVectorCalendario v(Nodos());
        InordenAux(v, posicion);
        return v;
    }

    TVectorCalendario Preorden() {
        int posición = 0;
        // Vector del tamaño adecuado para almacenar todos los nodos
        TVectorCalendario v(Nodos());
        PreordenAux(v, posicion);
        return v;
    }

    TVectorCalendario Postorden() {

    }

    TVectorCalendario Niveles() {

    }

    TABBCalendario operator+( TABBCalendario &) {

    }

    TABBCalendario operator-( TABBCalendario &) {

    }
    
}
