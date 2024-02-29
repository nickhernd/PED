#include "tlistacalendario.h"

TNodoCalendario::TNodoCalendario() : c(){
    this->siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &tnodo): c(tnodo.c){
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

TListaPos::TlistaPos() {
    this->pos = NULL;
}

TlistaPos::TListaPos(TListaPos &tlistapos){
    this->pos = tlistapos.pos;
}

TlistaPos::~TlistaPos() {
    this->pos.~TNodoCalendario();
}

TlistaPos & TListaPos::operator=(const TlistaPos &tlistapos){
    if(this =! &tlistapos) {
        (*this).~TlistaPos();
        this->pos = tlistapos.pos;
    }

    return (*this);
}