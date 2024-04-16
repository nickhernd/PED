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
    
    void TAABCalendario::InordenAux(TVectorCalendario &obj, int &num) {

    }

    void TAABCalendario::PreordenAux(TVectorCalendario &obj, int &num) {

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

    TAABCalendario &TAABCalendario::opertaro=(const TAABCalendario &obj) const {

    }

    bool operator==( TABBCalendario &) {

    }

    bool EsVacio() {

    }
    
    bool Insertar(TCalendario &) {

    }

    bool Borrar(TCalendario &) {

    }

    bool Buscar(TCalendario &) {

    }
     
    TCalendario Raiz() {

    }

    int Altura() {

    } 

    int Nodos() {

    }

    int NodosHoja() {

    }

    TVectorCalendario Inorden() {

    }

    TVectorCalendario Preorden() {

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
