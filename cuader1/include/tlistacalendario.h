#ifndef _TLISTACALENDARIO_H_
#define _TLISTACALENDARIO_H__H_

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"

using namespace std;

class TNodoCalendario {
    private:
        TCalendario c; 
        TNodoCalendario *siguiente;

    public:
        TNodoCalendario();
        TNodoCalendario(TNodoCalendario &);
        ~TNodoCalendario();
        TNodoCalendario & operator=(TNodoCalendario &);
};

class TlistaPos {
    private:
        TNodoCalendario *pos;

    public:
        TlistaPos();
        TlistaPos(TlistaPos &);
        ~TlistaPos();
        TlistaPos & operator=(TlistaPos &);

        bool operator==(TListaPos &);
        bool operator!=(TListaPos &);
        TListaPos Siguiente();
        bool EsVacia();
};

class TListaCalendario {
    private:
        TNodoCalendario *primero;

    public:
        TListaCalendario();
        TListaCalendario(TListaCalendario &);
        ~TListaCalendario();
        TListaCalendario & operator=(TListaCalendario &);

        bool operator==(TListaCalendario &)
        TListaCalendario operator+ (TListaCalendario &);
        TListaCalendario operator- (TListaCalendario &);
        Bool Insertar(TCalendario &);
        bool Borrar(TCalendario &);
        bool Borrar (TListaPos &);
        bool Borrar(int,int,int);
        bool EsVacia();

        TCalendario Obtener(TListaPos &)
        bool Buscar(TCalendario &);
        int Longitud();
        TListaPos Primera() {return this->primero;};
        TListaPos Ultima();
        TListaCalendario SumarSubl (int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2);
        TListaCalendario ExtraerRango (int n1, int n2);

        friend ostream & operator<<(ostream &, TListaCalendario &);
};


#endif