#ifndef _TLISTACALENDARIO_H_
#define _TLISTACALENDARIO_H__H_

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"

using namespace std;

// Declaración adelantada de las clases para permitir su uso en las definiciones de otras clases
class TNodoCalendario;
class TListaPos;

// Declaración de la clase TListaCalendario
class TListaCalendario {
    friend class TNodoCalendario;
    friend class TListaPos;
    friend ostream & operator<<(ostream &, const TListaCalendario &);

private:
    TNodoCalendario *primero;

public:
    // Constructor y destructor
    TListaCalendario();
    TListaCalendario(const TListaCalendario &);
    ~TListaCalendario();

    // Operador de asignación
    TListaCalendario & operator=(const TListaCalendario &);

    // Operadores de comparación
    bool operator==( TListaCalendario &);

    // Operadores de suma y resta de listas
    TListaCalendario operator+( TListaCalendario &) ;
    TListaCalendario operator-( TListaCalendario &) ;

    // Métodos de inserción y borrado de elementos
    bool Insertar(const TCalendario &);
    bool Borrar(const TCalendario &);
    bool Borrar (const TListaPos &);
    bool Borrar(int,int,int);

    // Método para verificar si la lista está vacía
    bool EsVacia() const;

    // Métodos para obtener información sobre la lista
    TCalendario Obtener(const TListaPos &) const;
    bool Buscar(const TCalendario &) const;
    int Longitud() const;
    TListaPos Primera() const;
    TListaPos Ultima() const;
    TListaCalendario SumarSubl (int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2);
    TListaCalendario ExtraerRango (int n1, int n2);
};

// Declaración de la clase TNodoCalendario
class TNodoCalendario {
    friend class TListaPos;
    friend class TListaCalendario;

private:
    TCalendario c; 
    TNodoCalendario *siguiente;

public:
    // Constructores y destructor
    TNodoCalendario();
    TNodoCalendario(const TNodoCalendario &);
    ~TNodoCalendario();

    // Operador de asignación
    TNodoCalendario & operator=(const TNodoCalendario &);
};

// Declaración de la clase TListaPos
class TListaPos {
    friend class TNodoCalendario;
    friend class TListaCalendario;

private:
    TNodoCalendario *pos;

public:
    // Constructores y destructor
    TListaPos();
    TListaPos(const TListaPos &);
    ~TListaPos();

    // Operador de asignación
    TListaPos & operator=(const TListaPos &);

    // Operadores de comparación
    bool operator==(const TListaPos &) const;
    bool operator!=(const TListaPos &) const;

    // Método para obtener la posición siguiente
    TListaPos Siguiente() const;

    // Método para verificar si la posición está vacía
    bool EsVacia() const;
};

#endif
