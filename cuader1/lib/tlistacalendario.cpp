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

TListaPos & TListaPos::operator=(TListaPos &tlistapos){
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
    TListaPos actual_Tlista = tlistacal.Primera();

    if(this->Longitud() == tlistacal.Longitud()){
        do{
            if(!actual.EsVacia() && !actual_Tlista.EsVacia()){
                if(actual.pos->c != actual_Tlista.pos->c)
                    return false;

                actual = actual.Siguiente();
                actual_Tlista = actual_Tlista.Siguiente();
            }
        }while(!actual.EsVacia());

        return true;
    }
    return false;
}

TListaCalendario TListaCalendario::Insertar(const TCalendario &tcal) {
    bool insertar = false;
    TlistaPos tsiguiente;
    TNodoCalendario *tnodo = new TNodoCalendario();

    if(this->primero == NULL) {
        tnodo->c = tcal;
        this->primero = tnodo;
        tnodo->siguiente = NULL;
        return(*this);
    }

    tnodo->c=tcal;
    if(primero->siguiente == NULL) {
        if(tnodo->c > tcal) {
            this->primero = tnodo;
            tnodo->siguiente = tnodo.pos;
            return true;
        } else {
            tnodo.pos->siguiente = tnodo;
            tnodo->siguiente = NULL;
            return true;
        }
    } else {
        while(tnodo.pos != NULL) {
            tsiguiente = tnodo.pos->siguiente;
            if(tnodo.pos->c < tcal) {
                if(tsiguiente == NULL) {
                    tnodo.pos->siguiente = tnodo;
                    tnodo->siguiente = NULL;
                    return true;
                } else {
                    if(tsiguiente->c > tcal) {
                        tnodo.pos->siguiente = tnodo;
                        tnodo->siguiente = tsiguiente;
                        return true;
                    }
                }
     
            } 
            tnodo.pos = tnodo.pos->siguiente;
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

bool TListaCalendario::Borrar(const TListaPos &tlista) {

    return false;
}

bool TListaCalendario::Borrar(int dia, int mes, int anyo) {
    TNodoCalendario *auxp = this->primero;
    TNodoCalendario *borrar;

    while(auxp != NULL) {
        if(this->primero->c.Dia() == dia && this->primero->c.Mes() == mes && this->primero->c.Anyo == Anyo) {
            borrar = this->primero;
            this->primero = this->siguiente;
            delete borrar;
            return true;
        } else {
            if(auxp->siguiente != NULL && auxp->siguiente->c.Dia == dia && auxp->siguiente->c.Mes == mes && auxp->siguiente->c.Anyo == Anyo) {
                borrar = auxp->siguiente;
                auxp->siguiente = auxp->siguiente->siguiente; 
                delete borrar;
                return true;
            } else auxp = auxp->siguiente;
        }
    
    return false;

    }
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
    return NULL;
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
    TNodoCalendario *auxp = this->primero;
    TNodoCalendario *auxpsig = auxp->siguiente;

    while(auxpsig != NULL) {
        auxp = auxp->siguiente;
        auxpsig = auxp->siguiente;
    }

    delete auxpsig;
    return auxp;
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2) {
    return NULL;
}

TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2) {
    return NULL;
}

friend ostream & operator<<(ostream &os, TListaCalendario &tlistacal) {
    TNodoCalendario *auxp = this->primero;
    
    os << "<";
    while(auxp->siguiente != NULL) {
        os << auxp->c;
    }
    os << ">";
}

