#include "tabbcalendario.h"

class TNodoABB {
    TNodoABB() {
        this->item = NULL;
        this->iz = NULL;
        this->de = NULL;
    }

    TNodoABB(TNodoABB &obj) {
        this->item = obj.item;
        this->iz = obj.iz;
        this->de = obj.de;
    }

    ~TNodoABB() {
        this->item = NULL;
        this->iz = NULL;
        this->de = NULL;
    }

    TNodoABB & TNodoABB::operator=(TNodoABB &obj) {
        if((*this) == obj){
            return (*this);
        }

        this->item = obj.item;
        this->iz = obj.iz;
        this->de = obj.de;

        return (*this);
    }
};

class TAABCalendario {
    TAABCalendario() 
    {
        this->raiz = NULL;
    }


    TABBCalendario(TABBCalendario &obj)
    {
        this->raiz = NULL;
    }

    ~TAABCalendario() 
    {
        delete raiz;
        this->raiz = NULL;
    }

    TAABCalendario &TAABCalendario::opertaro=(const TAABCalendario &obj) const {

    }

    
}
