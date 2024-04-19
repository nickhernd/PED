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

    TNodoABB::~TNodoABB() {}

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
        this->raiz = nullptr;
    }


    TABBCalendario(TABBCalendario &obj)
    {
        this->raiz = obj.raiz;
    }

    ~TAABCalendario() 
    {
        BorrarSubarbol(this->raiz);
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
    
    bool TABBCalendario::Insertar(const TCalendario& c) {
    if (EsVacio()) {
        raiz = new TNodoABB();
        raiz->item = c;
        return true;
    }

    TNodoABB* actual = raiz;
    TNodoABB* padre = nullptr;

    while (actual != nullptr) {
        if (c == actual->item) {
            return false; // El elemento ya existe en el árbol
        } else if (c < actual->item) {
            padre = actual;
            actual = actual->iz;
        } else {
            padre = actual;
            actual = actual->de;
        }
    }

    TNodoABB* nuevo = new TNodoABB();
    nuevo->setItem(c);

    if (c < padre->iz) {
        padre->iz = nuevo;
    } else {
        padre->de = nuevo;
    }

    return true;
    }

    bool TABBCalendario::Borrar(const TCalendario& c) {
        if (!Buscar(c)) {
            return false; // El elemento no existe en el árbol
        }

        BorrarSubarbol(raiz, c);
        return true;
    }

    void TABBCalendario::BorrarSubarbol(TNodoABB* nodo) {
        if (nodo == nullptr) {
            return nullptr; // El elemento no está en el árbol
        }

        if (c < nodo->item) {
            nodo->iz = BorrarSubarbol(nodo->iz, c);
        } else if (c > nodo->item) {
            nodo->de = BorrarSubarbol(nodo->de, c);
        } else {
            // El nodo a borrar es este nodo

            // Caso 1: El nodo no tiene hijos
            if (nodo->iz == nullptr && nodo->de == nullptr) {
                delete nodo;
                return nullptr;
            }

            // Caso 2: El nodo tiene un solo hijo
            if (nodo->iz == nullptr) {
                TNodoABB* temp = nodo->de;
                delete nodo;
                return temp;
            } else if (nodo->de == nullptr) {
                TNodoABB* temp = nodo->iz;
                delete nodo;
                return temp;
            }

            // Caso 3: El nodo tiene dos hijos
            TNodoABB* temp = BuscarMayorIzquierda(nodo->iz);
            nodo->item = temp->item;
            nodo->iz = BorrarSubarbol(nodo->iz);
        }

        return nodo;
    }

    TNodoABB* TABBCalendario::BuscarMayorIzquierda(TNodoABB* nodo) {
        if (nodo == nullptr || nodo->de == nullptr) {
            return nodo;
        }
        return BuscarMayorIzquierda(nodo->de);
    }

    bool TABBCalendario::Buscar(const TCalendario& c) const {
        TNodoABB* actual = raiz;

        while (actual != nullptr) {
            if (c == actual->item) {
                return true; // El elemento está en el árbol
            } else if (c < actual->item) {
                actual = actual->iz;
            } else {
                actual = actual->de;
            }
        }

        return false; // El elemento no está en el árbol
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
        int posición = 1;
        // Vector del tamaño adecuado para almacenar todos los nodos
        TVectorCalendario v(Nodos());
        PreordenAux(v, posicion);
        return v;
    }

    TVectorCalendario Postorden() {
        int posición = 1;
        // Vector del tamaño adecuado para almacenar todos los nodos
        TVectorCalendario v(Nodos());
        PreordenAux(v, posicion);
        return v;
    }

    TVectorCalendario Niveles() {

    }

    TABBCalendario operator+( TABBCalendario &) {

    }

    TABBCalendario operator-( TABBCalendario &) {

    }
    
}
