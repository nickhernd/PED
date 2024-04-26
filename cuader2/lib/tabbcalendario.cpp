#include "tabbcalendario.h"
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include <queue>
#include <iostream>
using namespace std;

// PRIVADO
void TABBCalendario::InordenAux(TVectorCalendario &v, int &pos) const{
    if(!this->EsVacio()){
        this->raiz->iz.InordenAux(v, pos);
        v[pos] = this->Raiz();
        pos++;
        this->raiz->de.InordenAux(v, pos);
    }
}

void TABBCalendario::PreordenAux(TVectorCalendario &v, int &pos) const{
    if(!this->EsVacio()){
        v[pos] = this->Raiz();
        pos++;
        this->raiz->iz.PreordenAux(v, pos);        
        this->raiz->de.PreordenAux(v, pos);
    }
}

void TABBCalendario::PostordenAux(TVectorCalendario &v, int &pos) const{
    if(!this->EsVacio()){ 
        this->raiz->iz.PostordenAux(v, pos);        
        this->raiz->de.PostordenAux(v, pos);
        v[pos] = this->Raiz();
        pos++;
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
    PostordenAux(v, posicion);

    return v;
}

//PUBLICO
TABBCalendario::TABBCalendario() {
    this->raiz = nullptr;
}

TABBCalendario::TABBCalendario(const TABBCalendario &obj)
{
    CopiaArbol(obj);
}

TABBCalendario::~TABBCalendario() 
{
    Borrar(this->raiz->item);
}

    
TABBCalendario& TABBCalendario::operator=(const TABBCalendario& tabb) {
   if(this != &tabb){   
        this->~TABBCalendario();
        this->CopiaArbol(tabb);
    }

    return *this;
}


bool TABBCalendario::operator==( TABBCalendario& abb)  {
    return(Inorden() == abb.Inorden() && Preorden() == abb.Preorden() && Postorden() == abb.Postorden());
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

//Borrar nodo sin ser hoja hacerlo con punteros
bool TABBCalendario::Borrar(const TCalendario &cal){
    if(!this->EsVacio() && this->Buscar(cal)){
        if(this->raiz->item > cal)
            return this->raiz->iz.Borrar(cal);

        else if(this->raiz->item < cal)
            return this->raiz->de.Borrar(cal);

        else if(this->raiz->iz.EsVacio() && this->raiz->de.EsVacio() ){
            this->raiz = NULL;
            return true;
        }

        else if(this->raiz->iz.EsVacio() && !this->raiz->de.EsVacio()){
            this->raiz = this->raiz->de.raiz;
            return true;
        }

        else if(!this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()){
            this->raiz = this->raiz->iz.raiz;
            return true;
        }

        else if(!this->raiz->iz.EsVacio() && !this->raiz->de.EsVacio()){
            TCalendario izq = this->raiz->iz.Ordenar();
            
            this->raiz->iz.Borrar(izq);
        }

        else return false;

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
    if(raiz->de.EsVacio() && raiz->iz.EsVacio()) return 1;
    if(!raiz->de.EsVacio() && raiz->iz.EsVacio()) return 0 + raiz->de.NodosHoja();
    else if(raiz->de.EsVacio() && !raiz->iz.EsVacio()) return 0 + raiz->iz.NodosHoja();
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

//TNodoABB::TNodoABB(const TNodoABB &nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de){}

TNodoABB::TNodoABB(const TNodoABB &nodo) {
    this->item = nodo.item; 
    this->iz = nodo.iz;
    this->de = nodo.de;
}

TNodoABB::~TNodoABB() {}

TNodoABB & TNodoABB::operator=(const TNodoABB &nodo){
    if(this != &nodo){      
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

