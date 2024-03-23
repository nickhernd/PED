#include "tlistacalendario.h"
#include <iostream>

using namespace std;

//TNODOCALENDARIO
TNodoCalendario::TNodoCalendario(): c() {
    this->siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(TNodoCalendario &tnodo) : c(tnodo.c) {
    this->siguiente = tnodo.siguiente;
}

TNodoCalendario::~TNodoCalendario(){
    this->c.~TCalendario();
    this->siguiente = NULL;
}

TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &tnodo){
    if(this != &tnodo){  
        (*this).~TNodoCalendario();
        this->c = tnodo.c;
        this->siguiente = tnodo.siguiente;
    }
    return (*this);
}

//TLISTAPOS
TListaPos::TListaPos() {
    this->pos = NULL;
}

TListaPos::TListaPos(const TListaPos &tlistapos){
    this->pos = tlistapos.pos;
}

TListaPos::~TListaPos() {
    this->pos = NULL;
}

TListaPos & TListaPos::operator=(const TListaPos &tlistapos){
    if(this != &tlistapos){
        this->pos = tlistapos.pos;
    }

    return (*this);
}

bool TListaPos::operator==(const TListaPos &tlista) const{
    if(this->pos == tlista.pos)
        return true;

    return false;
}

bool TListaPos::operator!=(const TListaPos &tlista) const{ 
    return !(*this == tlista);
}

TListaPos TListaPos::Siguiente() const{
    TListaPos tlistapos;
    
    if(this->pos->siguiente != NULL){
        tlistapos.pos = this->pos->siguiente;
    }
    return tlistapos;
}

bool TListaPos::EsVacia() const{
    if(this->pos == NULL) {
        return true;
    }
    
    return false;
}

//TLISTACALENDARIO
TListaCalendario::TListaCalendario() {
    this->primero = NULL;
}

TListaCalendario::TListaCalendario(const TListaCalendario &tlistacal) {
    if (tlistacal.primero) {
        primero = new TNodoCalendario(*(tlistacal.primero));
        TNodoCalendario *nodoActual = primero;
        TNodoCalendario *nodoOriginal = tlistacal.primero->siguiente;
        while (nodoOriginal) {
            nodoActual->siguiente = new TNodoCalendario(*nodoOriginal);
            nodoActual = nodoActual->siguiente;
            nodoOriginal = nodoOriginal->siguiente;
        }
    } else {
        primero = nullptr;
    }
}

TListaCalendario::~TListaCalendario() {
    while (primero) {
        TNodoCalendario *borrar = primero;
        primero = primero->siguiente;
        delete borrar;
    }
}

TListaCalendario &TListaCalendario::operator=(const TListaCalendario &tlistacal) {
    if (this != &tlistacal) {
        this->~TListaCalendario(); // Liberar memoria de la lista actual
        if (tlistacal.primero) {
            primero = new TNodoCalendario(*(tlistacal.primero));
            TNodoCalendario *nodoActual = primero;
            TNodoCalendario *nodoOriginal = tlistacal.primero->siguiente;
            while (nodoOriginal) {
                nodoActual->siguiente = new TNodoCalendario(*nodoOriginal);
                nodoActual = nodoActual->siguiente;
                nodoOriginal = nodoOriginal->siguiente;
            }
        } else {
            primero = nullptr;
        }
    }
    return *this;
}

bool TListaCalendario::operator==(const TListaCalendario &tlistacal) const{
    TListaPos actual = this->Primera();
    TListaPos actual_compara = tlistacal.Primera();

    if(this->Longitud() == tlistacal.Longitud()){
        do{
            if(!actual.EsVacia() && !actual_compara.EsVacia()){
                if(actual.pos->c != actual_compara.pos->c)
                    return false;

                actual = actual.Siguiente();
                actual_compara = actual_compara.Siguiente();
            }
        }while(!actual.EsVacia());

        return true;
    }
    return false;
}

bool TListaCalendario::Insertar(const TCalendario &tcal) {
    TNodoCalendario *tsiguiente, *tanterior = new TNodoCalendario();
    TNodoCalendario *tnodo = new TNodoCalendario();
    bool insertado = false;

    if(this->primero == NULL) {
        tnodo->c = tcal;
        this->primero = tnodo;
        tnodo->siguiente = NULL;
        return true;
    }

    tnodo->c=tcal;
    if(primero->siguiente == NULL) {
        if(this->primero->c > tcal) {
            tnodo->siguiente = this->primero;
            this->primero = tnodo;
            return true;
        } else {
            this->primero->siguiente = tnodo;
            tnodo->siguiente = NULL;
            return true;
        }
    } else {
        tanterior = this->primero;
        tsiguiente = this->primero->siguiente;
     
        while(!insertado) {
            if(tanterior->c < tcal) {
                if(tsiguiente == NULL) {
                    tanterior->siguiente = tnodo;
                    tnodo->siguiente=NULL;
                    insertado = true;
                    return true;
                } else {
                    if(tsiguiente->c > tcal) {
                        tanterior->siguiente = tnodo;
                        tnodo->siguiente = tsiguiente;
                        insertado = true;
                        return true;
                    }
                }
     
            } 
            tanterior = tsiguiente;
            tsiguiente = tsiguiente->siguiente;
        }
    }
    
    delete tnodo;
    
    return false;
}

bool TListaCalendario::Borrar(TCalendario &tcal){
    TNodoCalendario *aux = this->primero;
    TNodoCalendario *borrar;

    while(aux != NULL){ 
        
        if(this->primero->c == tcal){
            borrar = this->primero;
            this->primero = this->primero->siguiente; 
            delete borrar;
            return true; 
        } else {
            if(aux->siguiente != NULL && aux->siguiente->c == tcal){
                borrar = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente; 
                delete borrar;
                return true;
            }

            else aux = aux->siguiente;
        }  
    }

    return false;
}

bool TListaCalendario::Borrar(const TListaPos &tlistapos) {
    if (tlistapos.pos) {
        TNodoCalendario *borrar = tlistapos.pos;
        TNodoCalendario *anterior = primero;
        if (anterior == borrar) {
            primero = borrar->siguiente;
        } else {
            while (anterior->siguiente != borrar) {
                anterior = anterior->siguiente;
            }
            anterior->siguiente = borrar->siguiente;
        }
        delete borrar;
        return true;
    }
    return false;
}


bool TListaCalendario::Borrar(int dia, int mes, int anyo) {
    TNodoCalendario *auxp = this->primero;
    TNodoCalendario *borrar;

    while(auxp != NULL) {
        if(this->primero->c.Dia() == dia && this->primero->c.Mes() == mes && this->primero->c.Anyo() == anyo) {
            borrar = this->primero;
            this->primero = auxp->siguiente;
            delete borrar;
            return true;
        } else {
            if(auxp->siguiente != NULL && auxp->siguiente->c.Dia() == dia && auxp->siguiente->c.Mes() == mes && auxp->siguiente->c.Anyo() == anyo) {
                borrar = auxp->siguiente;
                auxp->siguiente = auxp->siguiente->siguiente; 
                delete borrar;
                return true;
            } else auxp = auxp->siguiente;
        }
    }
    return false;
}

TListaCalendario TListaCalendario::operator+(const TListaCalendario &tlistacal) const {
    TListaCalendario listaSuma(*this);
    TListaPos pos = tlistacal.Primera();
    
    while (!pos.EsVacia()) {
        listaSuma.Insertar(pos.pos->c);
        pos = pos.Siguiente();
    }
    return listaSuma;
}

TListaCalendario TListaCalendario::operator-(const TListaCalendario &tlistacal) const {
    TListaCalendario listaResta(*this);
    TListaPos pos = tlistacal.Primera();
    while (!pos.EsVacia()) {
        listaResta.Borrar(pos.pos->c);
        pos = pos.Siguiente();
    }
    return listaResta;
}

bool TListaCalendario::EsVacia() const{
    if(this->primero == NULL)
        return true;
    
    return false;
}

bool TListaCalendario::Buscar(TCalendario &tcal) const{
    TListaPos actual = this->Primera();

    while(!actual.EsVacia()) {
        if(actual.pos->c == tcal) {
            return true;
        }
        actual = actual.Siguiente();
    }

    return false;
}

TCalendario TListaCalendario::Obtener(const TListaPos &tlista) const{
    TListaPos actual = this->Primera();

    while(!actual.EsVacia()) {
        if(actual == tlista) {
            return actual.pos->c;
        }

        actual = actual.Siguiente();
    }

    return TCalendario();
}

int TListaCalendario::Longitud() const{
    int tam = 0;
    TListaPos posi = this->Primera();

    while(!posi.EsVacia()) {
        tam += 1;
        posi = posi.Siguiente();
    }

    return tam;
}

TListaPos TListaCalendario::Primera() const{
    TListaPos tpos;
    if(this->EsVacia()) 
        return tpos;
    
    tpos.pos = this->primero;
    return tpos; 
        
}

TListaPos TListaCalendario::Ultima() const{
    TListaPos tposact = this->Primera();
    TListaPos tpossig = tposact.Siguiente();
    int i = 1;

    while(!tpossig.EsVacia() && i < this->Longitud()) {
        tposact = tpossig;
        tpossig = tposact.Siguiente();
        ++i;
    }

    return tposact;
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2) {
    TListaCalendario *copia_L1 = new TListaCalendario(*this);
    TListaCalendario *copia_L2 = new TListaCalendario(L2);
    TListaCalendario suma;

    *copia_L1 = copia_L1->ExtraerRango(I_L1, F_L1);
    *copia_L2 = copia_L2->ExtraerRango(I_L2, F_L2);

    suma = *copia_L1 + *copia_L2;
    return suma;
}

TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2){
    TListaCalendario *copia_lista = new TListaCalendario(*this);
    TListaCalendario extraer_lista;
    TListaPos actual = copia_lista->Primera();

    if(n1 > n2) return extraer_lista;

    if(n1 <= 0) n1 = 1;

    if(n2 > this->Longitud()) n2 = this->Longitud();
    
    int cont = 1;
    while(!actual.EsVacia()) {
        if(cont >= n1 && cont <= n2){
            this->Borrar(actual);
            extraer_lista.Insertar(actual.pos->c);
        }
        actual = actual.Siguiente();
        ++cont;
    }

    copia_lista->~TListaCalendario();

    return extraer_lista;
}

ostream & operator<<(ostream &os, const TListaCalendario &tlistacal) {
    TListaPos actual = tlistacal.Primera();

    os << "<";
    while(!actual.EsVacia()) {
        os << tlistacal.Obtener(actual);

        if(actual !=  tlistacal.Ultima()) os << " "; 

        actual = actual.Siguiente();
    }
    os << ">";

    return os;
}

