#include "tavlcalendario.h"
#include <iostream>
#include <queue>

TNodoAVL::TNodoAVL() : item(), de(), iz(), fe(){}

void TNodoAVL::Copia(const TNodoAVL &nodo){
    this->item = nodo.item;
    this->iz = nodo.iz;
    this->de = nodo.de;
    this->fe = nodo.fe;
}

TNodoAVL::TNodoAVL(const TNodoAVL &nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de), fe(nodo.fe){}

TNodoAVL::~TNodoAVL(){}

TNodoAVL & TNodoAVL::operator=(const TNodoAVL &nodo){
    if(this != &nodo){      //Protección contra autoasignación
        this->~TNodoAVL();
        Copia(nodo);
    }
    return *this;
}

TAVLCalendario::TAVLCalendario(){
    this->raiz = NULL;
}

void TAVLCalendario::Copia(const TAVLCalendario &avl){
    if(!avl.EsVacio()){
        this->raiz = new TNodoAVL();
        this->raiz->item = avl.raiz->item;
        this->raiz->iz.Copia(avl.raiz->iz);
        this->raiz->de.Copia(avl.raiz->de);
    }
    else this->raiz = NULL;
}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &avl){
    this->raiz = NULL;
    Copia(avl);
}

TAVLCalendario::~TAVLCalendario(){
    if (this->raiz != NULL) {
        this->raiz->iz.~TAVLCalendario();
        this->raiz->de.~TAVLCalendario();
        delete this->raiz;
        this->raiz = NULL;
    }
}

TAVLCalendario & TAVLCalendario::operator= (const TAVLCalendario &avl){
    if(this != &avl){
        this->~TAVLCalendario();
        this->Copia(avl);
    }

    return *this;
}

bool TAVLCalendario::operator==(const TAVLCalendario &avl) const{
    if(this->Inorden() == avl.Inorden())
        return true;
    else return false;
}

bool TAVLCalendario::operator!=(const TAVLCalendario &avl) const{
    return !(*this == avl);
}

bool TAVLCalendario::EsVacio() const{
    return (this->raiz == NULL);
}

bool TAVLCalendario::Insertar(const TCalendario &cal){
    bool insertado = false;
    
    if(this->EsVacio()){
        TNodoAVL *nuevoNodo = new TNodoAVL();
        nuevoNodo->item = cal;
        this->raiz = nuevoNodo;
        insertado = true;
    }
    else if(!this->Buscar(cal)){
        if(this->raiz->item < cal)
            insertado = this->raiz->de.Insertar(cal);
        else insertado = this->raiz->iz.Insertar(cal);
    }
    
    if(insertado)
        this->Equilibrar();

    return insertado;
}

TCalendario TAVLCalendario::Ordenar() const{
    TCalendario cal;
    if(!this->EsVacio()){
        if(this->raiz->de.EsVacio())
            return this->raiz->item;
        else return this->raiz->de.Ordenar();
    }

    return cal;
}

bool TAVLCalendario::Borrar(const TCalendario &cal){

    bool borrado = false;

    if(!this->EsVacio() && this->Buscar(cal)){
        if(this->raiz->item > cal)
            borrado = this->raiz->iz.Borrar(cal);

        else if(this->raiz->item < cal)
            borrado = this->raiz->de.Borrar(cal);

        //Nodo hoja
        else if(this->raiz->iz.EsVacio() && this->raiz->de.EsVacio() ){
            this->raiz = NULL;
            borrado = true;
        }

        else if(this->raiz->iz.EsVacio() && !this->raiz->de.EsVacio()){
            this->raiz = this->raiz->de.raiz;
            borrado = true;
        }

        else if(!this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()){
            this->raiz = this->raiz->iz.raiz;
            borrado = true;
        }

        else if(!this->raiz->iz.EsVacio() && !this->raiz->de.EsVacio()){
            TCalendario izq = this->raiz->iz.Ordenar();
            this->raiz->item = izq;
            this->raiz->iz.Borrar(izq);
        }

        else borrado = false;

    }

    if (this->raiz != NULL)
        this->Equilibrar();

    return borrado;
}

bool TAVLCalendario::Buscar(const TCalendario &cal) const{
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

TCalendario TAVLCalendario::Raiz() const{
    return EsVacio() ? TCalendario() : this->raiz->item;
}

int TAVLCalendario::Altura() const{
    return EsVacio() ? 0 : 1 + max(this->raiz->iz.Altura(), this->raiz->de.Altura());
}

int TAVLCalendario::Nodos() const{
    return EsVacio() ? 0 : 1 + this->raiz->iz.Nodos() + this->raiz->de.Nodos();
}

int TAVLCalendario::NodosHoja() const{
    if (!this->EsVacio()){
        if(!this->raiz->iz.EsVacio() || !this->raiz->iz.EsVacio())
            return this->raiz->iz.NodosHoja() + this->raiz->de.NodosHoja();
        else
            return 1;
    }   
    else return 0;
}

void TAVLCalendario::InordenAux(TVectorCalendario &v, int &pos) const{
    if(!this->EsVacio()){
        this->raiz->iz.InordenAux(v, pos);
        v[pos++] = this->Raiz();
        this->raiz->de.InordenAux(v, pos);
    }
}
               
TVectorCalendario TAVLCalendario::Inorden() const{
    int pos = 1;
    TVectorCalendario v (this->Nodos());
    this->InordenAux(v, pos);
    return v;
}

void TAVLCalendario::PreordenAux(TVectorCalendario &v, int &pos) const{
    if(!this->EsVacio()){
        v[pos++] = this->Raiz();
        this->raiz->iz.PreordenAux(v, pos);        
        this->raiz->de.PreordenAux(v, pos);
    }
}

TVectorCalendario TAVLCalendario::Preorden() const{
    int pos = 1;
    TVectorCalendario v (this->Nodos());
    this->PreordenAux(v, pos);
    return v;
}

void TAVLCalendario::PostordenAux(TVectorCalendario &v, int &pos) const{
    if(!this->EsVacio()){ 
        this->raiz->iz.PostordenAux(v, pos);        
        this->raiz->de.PostordenAux(v, pos);
        v[pos++] = this->Raiz();
    }
}

TVectorCalendario TAVLCalendario::Postorden() const{
    int pos = 1;
    TVectorCalendario v (this->Nodos());
    this->PostordenAux(v, pos);
    return v;
}

int TAVLCalendario::CalcularFE(){
    int izquierda = this->raiz->iz.Altura(), derecha = this->raiz->de.Altura();    
    return derecha - izquierda;
}

void TAVLCalendario::ActualizarFE(){

    if(this->raiz->iz.raiz != NULL)
        this->raiz->iz.raiz->fe = this->CalcularFE();

    if(this->raiz->de.raiz != NULL)
        this->raiz->de.raiz->fe = this->CalcularFE();
}

void TAVLCalendario::Equilibrar(){
    TNodoAVL *nodo;

    this->raiz->fe = CalcularFE();

    if(this->raiz->fe < -1){
        TNodoAVL *izquierdo;

        //ROTAMOS IZQUIERDA
        if(this->raiz->iz.raiz->fe <= 0){
            izquierdo = raiz->iz.raiz;
            raiz->iz.raiz = raiz->iz.raiz->de.raiz;
            izquierdo->de.raiz = raiz;
            raiz = izquierdo; 

        } else{

            izquierdo = raiz->iz.raiz;
            raiz->iz.raiz = izquierdo->de.raiz->de.raiz;
            izquierdo->de.raiz->de.raiz = raiz;
            raiz = izquierdo->de.raiz;
            izquierdo->de.raiz = raiz->iz.raiz;
            raiz->iz.raiz = izquierdo;
        }

        this->raiz->fe = CalcularFE();
        ActualizarFE();
    }

    else if(this->raiz->fe > 1){
        TNodoAVL *derecho = this->raiz;

        //ROTAMOS DERECHA
        if (raiz->de.raiz->fe >= 0){

            derecho = raiz->de.raiz;
            raiz->de.raiz = raiz->de.raiz->iz.raiz;
            derecho->iz.raiz = raiz;
            raiz = derecho;

        } else{

            derecho = raiz->de.raiz;
            raiz->de.raiz = derecho->iz.raiz->iz.raiz;
            derecho->iz.raiz->iz.raiz = raiz;
            raiz = derecho->iz.raiz;
            derecho->iz.raiz = raiz->de.raiz;
            raiz->de.raiz = derecho;
        }

        this->raiz->fe = CalcularFE();
        ActualizarFE();
    }
}

ostream& operator<<(ostream &s, const TAVLCalendario &obj){
    s << obj.Inorden();
    return s;
}
