#include "tabbcalendario.h"
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include <queue>
#include <iostream>
using namespace std;

<<<<<<< HEAD
// PRIVADO
void TABBCalendario::InordenAux(TVectorCalendario &v, int &pos) const{
    if(!this->EsVacio()){
        this->raiz->iz.InordenAux(v, pos);
        v[pos++] = this->Raiz();
        this->raiz->de.InordenAux(v, pos);
    }
}

void TABBCalendario::PreordenAux(TVectorCalendario &v, int &pos) const{
    if(!this->EsVacio()){
        v[pos++] = this->Raiz();
        this->raiz->iz.PreordenAux(v, pos);        
        this->raiz->de.PreordenAux(v, pos);
    }
}
=======
class TNodoABB {
    TNodoABB::TNodoABB() : iz(nullptr), de(nullptr) {}

    TNodoABB::TNodoABB(const TNodoABB &nodo) : item(nodo.item), iz(nullptr), de(nullptr) {
        if (nodo.iz) {
            iz = new TNodoABB(*nodo.iz);
        }
        if (nodo.de) {
            de = new TNodoABB(*nodo.de);
        }
    }

    TNodoABB::~TNodoABB() {}
>>>>>>> abf49d7e635386f1debb3850f08effe8bf42bc66

void TABBCalendario::PostordenAux(TVectorCalendario &v, int &pos) const{
    if(!this->EsVacio()){ 
        this->raiz->iz.PostordenAux(v, pos);        
        this->raiz->de.PostordenAux(v, pos);
        v[pos++] = this->Raiz();
    }
}

void TABBCalendario::CopiaArbol(const TABBCalendario &abb){
    if(!abb.EsVacio()){
        this->raiz = new TNodoABB();
        this->raiz->item = abb.raiz->item;
        this->raiz->iz.CopiaArbol(abb.raiz->iz);
        this->raiz->de.CopiaArbol(abb.raiz->de);
    }
    else this->raiz = NULL;
}

TVectorCalendario TABBCalendario::Inorden() const{
    int posicion = 1;
    // Vector del tamaño adecuado para almacenar todos los nodos
    TVectorCalendario v(Nodos());
    InordenAux(v, posicion);
    return v;
}

TVectorCalendario TABBCalendario::Preorden() const{
    int posicion = 1;
    // Vector del tamaño adecuado para almacenar todos los nodos
    TVectorCalendario v(Nodos());
    PreordenAux(v, posicion);
    return v;
}

TVectorCalendario TABBCalendario::Postorden() const{
    int posicion = 1;
    // Vector del tamaño adecuado para almacenar todos los nodos
    TVectorCalendario v(Nodos());
    PreordenAux(v, posicion);
    return v;
}

//PUBLICO
TABBCalendario::TABBCalendario() : raiz(nullptr) {}

TABBCalendario::TABBCalendario(const TABBCalendario &obj)
{
    this->raiz = obj.raiz;
}

TABBCalendario::~TABBCalendario() 
{
    Borrar(this->raiz->item);
}

    
<<<<<<< HEAD
TABBCalendario& TABBCalendario::operator=(const TABBCalendario& tabb) {
   if(this != &tabb){
        this->~TABBCalendario();
        this->CopiaArbol(tabb);
    }

    return *this;
}
=======
    void TAABCalendario::InordenAux(TVectorCalendario &vec, int &num) {
       
    }

    void TAABCalendario::PreordenAux(TVectorCalendario &vec, int &num) {
        vec[num].c = raiz.item;
        PreordenAux(vec, num + 1);
    }

    void TAABCalendario::PostordenAux() {

    }

    TAABCalendario() {
        this->raiz = NULL;
    }


    TABBCalendario(TABBCalendario &obj) {
        this->raiz = NULL;
    }

    ~TAABCalendario() {
        if(raiz != nullptr) {
            delete raiz;
            this->raiz = NULL;
        }
        
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
>>>>>>> abf49d7e635386f1debb3850f08effe8bf42bc66
    

bool TABBCalendario::operator==(const TABBCalendario& abb) const {
    if (Nodos() != abb.Nodos()) {
        return false; // Si los árboles tienen diferente cantidad de nodos, no son iguales
    }

    // Crear vectores con los recorridos en inorden de ambos árboles
    TVectorCalendario vecThis = Inorden();
    TVectorCalendario vecTabb = abb.Inorden();

    // Comparar los vectores elemento a elemento
    for (int i = 1; i <= Nodos(); i++) {
        if (vecThis[i] != vecTabb[i]) {
            return false; // Si hay un elemento diferente, los árboles no son iguales
        }
    }

    return true; // Si todos los elementos son iguales, los árboles son iguales
}
    
bool TABBCalendario::Insertar(const TCalendario &cal){
    if(this->EsVacio()){
        TNodoABB *nuevoNodo = new TNodoABB();
        nuevoNodo->item = cal;
        this->raiz = nuevoNodo;
        return true;
    }
    else if(!this->Buscar(cal)){
        if(this->raiz->item < cal)
            return this->raiz->de.Insertar(cal);
        else return this->raiz->iz.Insertar(cal);
    }
    return false;
}

TCalendario TABBCalendario::Ordenar() const{
    TCalendario cal;
    if(!this->EsVacio()){
        if(this->raiz->de.EsVacio())
            return this->raiz->item;
        else return this->raiz->de.Ordenar();
    }

    return cal;
}

bool TABBCalendario::Borrar(const TCalendario &cal){
    if(!this->EsVacio() && this->Buscar(cal)){
        if(this->raiz->item > cal)
            return this->raiz->iz.Borrar(cal);

        else if(this->raiz->item < cal)
            return this->raiz->de.Borrar(cal);

        //Nodo hoja
        else if(this->raiz->iz.EsVacio() && this->raiz->de.EsVacio() ){
            this->raiz = NULL;
            return true;
        }

<<<<<<< HEAD
        else if(this->raiz->iz.EsVacio() && !this->raiz->de.EsVacio()){
            this->raiz = this->raiz->de.raiz;
            return true;
=======
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
>>>>>>> abf49d7e635386f1debb3850f08effe8bf42bc66
        }

        else if(!this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()){
            this->raiz = this->raiz->iz.raiz;
            return true;
        }

        else if(!this->raiz->iz.EsVacio() && !this->raiz->de.EsVacio()){
            TCalendario izq = this->raiz->iz.Ordenar();
            this->raiz->item = izq;
            this->raiz->iz.Borrar(izq);
        }

<<<<<<< HEAD
        else return false;

=======
    int NodosHoja() {
        if(raiz.de == nullptr && raiz.iz == nullptr) return 0;
        if(raiz.de != nullptr && raiz.iz == nullptr) return raiz.de.NodosHoja();
        else if(raiz.de == nullptr && raiz.iz != nullptr) return raiz.iz.NodosHoja();
        else return raiz.de.NodosHoja() + raiz.iz.NodosHoja();
    } 

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
>>>>>>> abf49d7e635386f1debb3850f08effe8bf42bc66
    }

    return false;
}

bool TABBCalendario::Buscar(const TCalendario &cal) const{
    if(!this->EsVacio()){
        if(this->raiz->item == cal)
            return true;
        else{
            if(this->raiz->de.Buscar(cal) || this->raiz->iz.Buscar(cal))
                return true;
            else return false; 
        }
    }
    return false;
}
     
TCalendario TABBCalendario::Raiz() const{
    return raiz->item;
}

int TABBCalendario::Altura() const{
    if(raiz == nullptr) {
        return 0;
    }

    return 1 + max(raiz->iz.Altura(), raiz->de.Altura());
} 

int TABBCalendario::Nodos() const{
    if(raiz == nullptr) {
        return 0;
    }

    return 1 + raiz->iz.Nodos() + raiz->de.Nodos();
}

int TABBCalendario::NodosHoja() const{
    if(raiz->de.EsVacio() && raiz->iz.EsVacio()) return 0;
    if(!raiz->de.EsVacio() && raiz->iz.EsVacio()) return raiz->de.NodosHoja();
    else if(raiz->de.EsVacio() && !raiz->iz.EsVacio()) return raiz->iz.NodosHoja();
    else return raiz->de.NodosHoja() + raiz->iz.NodosHoja();
} 

TVectorCalendario TABBCalendario::Niveles() const{
    queue<TABBCalendario> queue;
    TVectorCalendario tvectorcal(this->Nodos());

    TABBCalendario abb = *this;
    queue.push(abb);

    int i = 1;
    while(!queue.empty()){
        tvectorcal[i] = abb.raiz->item;
        abb = queue.front();
        
        if(!abb.raiz->iz.EsVacio())
            queue.push(abb.raiz->iz);

        if(!abb.raiz->de.EsVacio())
            queue.push(abb.raiz->de);
        i++;
    }
    return tvectorcal;
}

TABBCalendario TABBCalendario::operator+ (TABBCalendario &abb){
    TABBCalendario result(*this);
    TABBCalendario aux(abb);

    TVectorCalendario listaNodos = aux.Inorden();

    for(int i = 1; i <= listaNodos.Tamano(); i++)
        result.Insertar(listaNodos[i]);

    return result;
}

TABBCalendario TABBCalendario::operator- (TABBCalendario &abb){
    TVectorCalendario listaNodos = this->Inorden();
    TABBCalendario result;

    for(int i = 1; i <= listaNodos.Tamano(); i++){
        TCalendario cal = listaNodos[i];

        if(!abb.Buscar(cal))
            result.Insertar(cal);
    }
    return result;
}

ostream& operator<<(ostream &os, const TVectorCalendario &vec) {
    for (int i = 1; i <= vec.Tamano(); ++i) {
        os << "[" << i << "] " << vec[i];
    }
    return os;
}


TNodoABB::TNodoABB() {}

TNodoABB::TNodoABB(const TNodoABB &nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de){}

TNodoABB::~TNodoABB() {}

TNodoABB & TNodoABB::operator=(const TNodoABB &nodo){
    if(this != &nodo){      //Protección contra autoasignación
        this->~TNodoABB();
        CopiaNodo(nodo);
    }
    return *this;
}

void TNodoABB::CopiaNodo(const TNodoABB &nodo){
    //Usando el operador= de la clase TABBCalendario
    this->item = nodo.item;
    this->iz = nodo.iz;
    this->de = nodo.de;
}

