#include "tlistacalendario.h"

//TNODOCALENDARIO
TNodoCalendario::TNodoCalendario(): c() {
    this->siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &tnodo) : c(tnodo.c) {
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
TListaPos::TlistaPos() {
    this->pos = NULL;
}

TlistaPos::TListaPos(const TListaPos &tlistapos){
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

bool TListaPos::operator==(const TListaPos &tlista) {
    
    if(tlista.pos.size() == this->pos.size()) {
        for(int i = 0; i < tlista.size(); i++) {
            if(tlista.pos[i] != this->pos[i]) {
                return false;
            }
        }    
        return true;
    } 
    
    return false;
}

bool TListaPos::operator!=(const TListaPos &tlista) {
    if(tlista.pos == this->pos) {
        return false;
    }

    return true;
}

TListaPos TListaPos::Siguiente() {

    TListaPos tlista;
    if(this->pos->siguiente != NULL) 
        return pos->siguiente;

    return tlista;

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

TListaCalendario & operator=(TListaCalendario &tlistacal) {
    if(this =! &tlistacal) {
        (*this).~TListaCalendario();
        this->primero = tlistacal.primero;
    }

    return (*this);
} 

bool TListaCalendario::operator==(TListaCalendario &tlistacal) {
    if(tlistacal.primero.size() == this->primera.size()) {
        for(int i = 0; i < tlistacal.size(); i++) {
            if(tlistacal.primera[i] != this->primera[i]) {
                return false;
            }
        }    
        return true;
    } 
    
    return false;
}

bool TListaCalendario::operator!=(const TListaCalendario &tlista) {
    if(tlista.primero == this->primero) {
        return false;
    }

    return true;
}

TListaCalendario TListaCalendario::operator+(TListaCalendario &tlistacal) {

}

TListaCalendario TListaCalendario::Insertar(const TCalendario &tcal) {
    bool insertar = false;
    TListaPos inicial = Primera();
    TlistaPos tsiguiente;
    TNodoCalendario *tnodo = new TNodoCalendario();

    if(primero == NULL) {
        tnodo->c = tcal;
        primero = tnodo;
        tnodo->siguiente = NULL;
        return(*this);
    }

    tnodo->c=tcal;
    if(primero->siguiente == NULL) {
        
        if(inicial->c > tcal) {
            primero = nodo;
            tnodo->siguiente = inicial.pos;
            return true;
        } else {
            inicial.pos->siguiente = nodo;
            tnodo->siguiente = NULL;
            return true;
        }
    } else {
        while(inicial.pos != NULL) {
            tsiguiente = inicial.pos->siguiente;
            if(inicial.pos->c < tcal) {
                if(tsiguiente == NULL) {
                    inicial.pos->siguiente = tnodo;
                    tnodo->siguiente = NULL;
                    return true;
                } else {
                    if(tsiguiente->c > tcal) {
                        inicial.pos->siguiente = tnodo;
                        tnodo->siguiente = tsiguiente;
                        return true;
                    }
                }
     
            } 
            inicial.pos = inicial.pos->siguiente;
        }
    }
    

    delete tnodo;
    return false;
}
