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
    
    if(this->pos->siguiente != NULL)
        tlistapos.pos = this->pos->siguiente;

    return tlistapos;
}

bool TListaPos::EsVacia() {
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
    this->primero = tlistacal.primero;
}

TListaCalendario::~TListaCalendario() {
    delete primero;
}

TListaCalendario & TListaCalendario::operator=(const TListaCalendario &tlistacal) {
    if(this != &tlistacal) {
        (*this).~TListaCalendario();
        this->primero = tlistacal.primero;
    }

    return (*this);
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

bool TListaCalendario::Insertar(TCalendario &tcal) {
    TNodoCalendario *tsiguiente = new TNodoCalendario();
    TNodoCalendario *tnodo = new TNodoCalendario();

    if(this->primero == NULL) {
        tnodo->c = tcal;
        this->primero = tnodo;
        tnodo->siguiente = NULL;
        return true;
    }

    tnodo->c=tcal;
    if(primero->siguiente == NULL) {
        if(this->primero->c > tcal) {
            this->primero = tnodo;
            tnodo->siguiente = this->primero;
            return true;
        } else {
            tnodo->siguiente = tnodo;
            tnodo->siguiente = NULL;
            return true;
        }
    } else {
        while(tnodo != NULL) {
            tsiguiente = tnodo->siguiente;
            if(tnodo->c < tcal) {
                if(tsiguiente == NULL) {
                    tnodo->siguiente = tnodo;
                    tnodo->siguiente = NULL;
                    return true;
                } else {
                    if(tsiguiente->c > tcal) {
                        tnodo->siguiente = tnodo;
                        tnodo->siguiente = tsiguiente;
                        return true;
                    }
                }
     
            } 
            tnodo = tnodo->siguiente;
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

TListaCalendario TListaCalendario::operator+(TListaCalendario &tlistacal) {
    TListaCalendario *tlista = new TListaCalendario(*this);

    for(TListaPos i = tlistacal.Primera(); !i.EsVacia(); i = i.Siguiente()) {
        tlista->Insertar(i.pos->c);
    }

    return (*tlista);
}

TListaCalendario TListaCalendario::operator-(TListaCalendario &tlistacal){
    TListaCalendario *tlist = new TListaCalendario(*this);

    for(TListaPos i = tlistacal.Primera(); !i.EsVacia(); i = i.Siguiente()) {
        tlist->Borrar(i.pos->c);
    }

    return (*tlist);
}

bool TListaCalendario::EsVacia() const{
    if(this->primero == NULL)
        return true;
    
    return false;
}

TCalendario TListaCalendario::Obtener(TListaPos &tlista) {
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
    TNodoCalendario *auxp = this->primero;

    while(auxp != NULL) {
        tam += 1;
        auxp = auxp->siguiente;
    }

    return tam;
}

TListaPos TListaCalendario::Primera() const{
    TListaPos tpos;
    if(this->EsVacia())
        return tpos;
    else{
        tpos.pos = this->primero;
        return tpos; 
    }
}

TListaPos TListaCalendario::Ultima() const{
    TListaPos tposact;
    TListaPos tpossig;

    do {
        tposact.pos = this->primero;
        tpossig.pos = this->primero->siguiente;
    }  while(tpossig.pos != NULL);

    return tpossig;
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2) {
    return (*this);
}

TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2) {
    return (*this);
}

ostream & operator<<(ostream &os, TListaCalendario &tlistacal) {
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

