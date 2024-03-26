#ifndef _TABBCALENDARIO_H_
#define _TABBCALENDARIO_H_

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"

using namespace std;
class TNodoABB;
class TABBCalendario;

class TNodoABB {
    friend class TABBCalendario;
    private:
        TCalendario item;
        TABBCalendario iz, de;
    public:
        TNodoABB();
        TNodoABB(TNodoABB &);
        ~TNodoABB();
        TNodoABB &operator=(TNodoABB &) const;
};

class TABBCalendario {
    friend class TNodoABB;
    private:
        
    public:

};

#endif
