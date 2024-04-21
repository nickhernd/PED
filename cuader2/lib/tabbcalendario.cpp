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
    
    //PRIVADO
    void TABBCalendario::InordenAux(TVectorCalendario& v, int& pos) const {
        if (raiz == nullptr) {
            return;
        }

        InordenAux(v, pos, raiz);
    }

    void TABBCalendario::InordenAux(TVectorCalendario& v, int& pos, const TNodoABB* nodo) const {
        if (nodo != nullptr) {
            InordenAux(v, pos, nodo->iz);
            v[pos++] = nodo->item;
            InordenAux(v, pos, nodo->de);
        }
    }

    void TABBCalendario::PreordenAux(TVectorCalendario& v, int& pos) const {
        if (raiz == nullptr) {
            return;
        }

        PreordenAux(v, pos, raiz);
    }

    void TABBCalendario::PreordenAux(TVectorCalendario& v, int& pos, const TNodoABB* nodo) const {
        if (nodo != nullptr) {
            v[pos++] = nodo->item;
            PreordenAux(v, pos, nodo->iz);
            PreordenAux(v, pos, nodo->de);
        }
    }

    void TABBCalendario::PostordenAux(TVectorCalendario& v, int& pos) const {
        if (raiz == nullptr) {
            return;
        }

        PostordenAux(v, pos, raiz);
    }

    void TABBCalendario::PostordenAux(TVectorCalendario& v, int& pos, const TNodoABB* nodo) const {
        if (nodo != nullptr) {
            PostordenAux(v, pos, nodo->iz);
            PostordenAux(v, pos, nodo->de);
            v[pos++] = nodo->item;
        }
    }

    TNodoABB* TABBCalendario::CopiarSubarbol(TNodoABB* nodo) const {
        if (nodo == nullptr) {
            return nullptr;
        }

        TNodoABB* nuevoNodo = new TNodoABB();
        nuevoNodo->item = nodo->item;

        nuevoNodo->iz = CopiarSubarbol(nodo->iz);
        nuevoNodo->de = CopiarSubarbol(nodo->de);

        return nuevoNodo;
    }

    //PUBLICO
    TABBCalendario::TABBCalendario() : raiz(nullptr) {}

    TABBCalendario(TABBCalendario &obj)
    {
        this->raiz = obj.raiz;
    }

    TAABCalendario::~TAABCalendario() 
    {
        BorrarSubarbol(this->raiz);
    }

    
    TABBCalendario& TABBCalendario::operator=(const TABBCalendario& tabb) {
        if (this != &tabb) {
            // Limpiar el árbol actual
            BorrarSubarbol(raiz);

            // Copiar el nuevo árbol
            raiz = CopiarSubarbol(tabb.raiz);
        }
        return *this;
    }
    

    bool TABBCalendario::operator==(const TABBCalendario& tabb) const {
        if (Nodos() != tabb.Nodos()) {
            return false; // Si los árboles tienen diferente cantidad de nodos, no son iguales
        }

        // Crear vectores con los recorridos en inorden de ambos árboles
        TVectorCalendario vecThis = Inorden();
        TVectorCalendario vecTabb = tabb.Inorden();

        // Comparar los vectores elemento a elemento
        for (int i = 1; i <= vecThis.Nelementos(); i++) {
            if (vecThis[i] != vecTabb[i]) {
                return false; // Si hay un elemento diferente, los árboles no son iguales
            }
        }

        return true; // Si todos los elementos son iguales, los árboles son iguales
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

    TNodoABB* TABBCalendario::BuscarMayorIzquierda(TNodoABB* nodo) const{
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
     
    TCalendario TAABCalendario::Raiz() {
        return raiz.item;
    }

    int TAABCalendario::Altura() {
        if(raiz = nullptr) {
            return 0;
        }

        return 1 + max(raiz.iz.Altura(), raiz.de.Altura());
    } 

    int TAABCalendario::Nodos() {
        if(raiz = nullptr) {
            return 0;
        }

        return 1 + raiz.iz.Nodos() + raiz.de.Nodos();
    }

    int TAABCalendario::NodosHoja() {
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

    TVectorCalendario TAABCalendario::Inorden() {
        int posición = 1;
        // Vector del tamaño adecuado para almacenar todos los nodos
        TVectorCalendario v(Nodos());
        InordenAux(v, posicion);
        return v;
    }

    TVectorCalendario TAABCalendario::Preorden() {
        int posición = 1;
        // Vector del tamaño adecuado para almacenar todos los nodos
        TVectorCalendario v(Nodos());
        PreordenAux(v, posicion);
        return v;
    }

    TVectorCalendario TAABCalendario::Postorden() {
        int posición = 1;
        // Vector del tamaño adecuado para almacenar todos los nodos
        TVectorCalendario v(Nodos());
        PreordenAux(v, posicion);
        return v;
    }

    TVectorCalendario TAABCalendario::Niveles() {

    }

    TABBCalendario TAABCalendario::operator+( TABBCalendario &) {

    }

    TABBCalendario TAABCalendario::operator-( TABBCalendario &) {

    }

    friend ostream & operator<<(ostream &, TABBCalendario &) {

    }
    
}
