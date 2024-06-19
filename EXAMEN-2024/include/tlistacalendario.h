#ifndef tlistacalendario_h
#define tlistacalendario_h
#include <iostream>
#include "tcalendario.h"

using namespace std;

//! Clase TNodoCalendario
/*! Clase que representa el nodo de la lista */
class TNodoCalendario
{
	friend class TListaPos;
	friend class TListaCalendario;
	private:
		//! c
		/*! variable de tipo TCalendario con el calendario */
		TCalendario c;
		//! siguiente
		/*! variable de tipo puntero a TNodoCalendario que indica la posicion siguiente */
		TNodoCalendario *siguiente;
	public:
		//! Constructor
		/*! Constructor por defecto de la clase TNodoCalendario */
		TNodoCalendario();
		//! Constructor de copia
		/*! Constructor copia de la clase TNodoCalendario */
		TNodoCalendario(const TNodoCalendario &);
		//! Destructor
		/*! Destructor sobrecargado de la clase TNodoCalendario */
		~TNodoCalendario();
		//! Operador asignacion
		/*! Operador asignacion de la clase TNodoCalendario */
		TNodoCalendario & operator=(const TNodoCalendario &);
};

//! Clase TListaPos
/*! Clase que representa las posiciones de la lista */
class TListaPos
{
	friend class TListaCalendario;
	private:
		//! pos
		/*! variable de tipo puntero a TNodoCalendario que indica la pos */
		TNodoCalendario *pos;
	public:
		//! Constructor
		/*! Constructor por defecto de la clase TListaPos */
		TListaPos();
		//! Constructor de copia
		/*! Constructor copia de la clase TListaPos */
		TListaPos(const TListaPos &);
		//! Destructor
		/*! Destructor sobrecargado de la clase TListaPos */
		~TListaPos();
		//! Operador asignacion
		/*! Operador asignacion de la clase TListapos */
		TListaPos & operator=(const TListaPos &);
		//! Operador igualdad
		/*! Operador igualdad de la clase TListapos */
		bool operator==(const TListaPos &) const;
		//! Operador desigualdad
		/*! Operador desigualdad de la clase TListapos */
		bool operator!=(const TListaPos &) const;
		//! Funcion Siguiente
		/*! Funcion Siguiente de la clase TListapos */
		TListaPos Siguiente();
		//! Funcion EsVacia
		/*! Funcion EsVacia de la clase TListapos */
		bool EsVacia() const;
};

//! Clase TListaCalendario
/*! Clase que representa la lista */
class TListaCalendario
{
	private:
		//! primero
		/*! variable de tipo puntero a TNodoCalendario que indica la primera posicion de la lista */
		TNodoCalendario *primero;
	public:
		//! Constructor
		/*! Constructor por defecto de la clase TListaCalendario */
		TListaCalendario();
		//! Constructor de copia
		/*! Constructor copia de la clase TListaCalendario */
		TListaCalendario(const TListaCalendario &);
		//! Destructor
		/*! Destructor de la clase TListaCalendario */
		~TListaCalendario();
		//! Operador asignacion
		/*! Operador asignacion de la clase TListaCalendario*/
		TListaCalendario & operator=(const TListaCalendario &);
		//! Operador igualdad
		/*! Operador igualdad de la clase TListaCalendario*/
		bool operator==(const TListaCalendario &);
		//! Operador suma
		/*! Operador suma de la clase TListaCalendario*/
		TListaCalendario operator+(const TListaCalendario &);
		//! Operador resta
		/*! Operador resta de la clase TListaCalendario*/
		TListaCalendario operator-(const TListaCalendario &);
		//! Funcion Insertar
		/*! Funcion Insertar de la clase TListaCalendario*/
		bool Insertar(const TCalendario &);
		//! Funcion Borrar calendario
		/*! Funcion Borrar calendario de la clase TListaCalendario */
		bool Borrar(const TCalendario &);
		//! Funcion Borrar posicion
		/*! Funcion Borrar posicion de la clase TListaCalendario */
		bool Borrar (const TListaPos &);
		//! Funcion Borrar calendarios
		/*! Funcion Borrar calendarios de la clase TListaCalendario */
		bool Borrar(int,int,int);
		//! Funcion EsVacia
		/*! Funcion EsVAcia de la clase TListaCalendario */
		bool EsVacia() const;
		//! Funcion Obtener
		/*! Funcion Obtener de la clase TListaCalendario */
		TCalendario Obtener(const TListaPos&) const;
		//! Funcion Buscar
		/*! Funcion Buscar de la clase TListaCalendario */
		bool Buscar(const TCalendario &);
		//! Funcion Longitud
		/*! Funcion Longitud de la clase TListaCalendario */
		int Longitud() const;
		//! Funcion Primera
		/*! Funcion Primera de la clase TListaCalendario */
		TListaPos Primera() const;
		//! Funcion Ultima
		/*! Funcion Ultima de la clase TListaCalendario */
		TListaPos Ultima() const;
		//! Funcion SumarSubl
		/*! Funcion Suma de dos sublistas de la clase TListaCalendario */
		TListaCalendario SumarSubl(int, int, TListaCalendario&, int, int);
		//! ExtraerRango
		/*! Funcion Extraer Rango de la clase TListaCalendario */
		TListaCalendario ExtraerRango(int, int);
	//! Sobrecarga operador de salida
	/*! Funcion amiga. Sobrecarga del operador de salida de la clase TListaCalendario */
	friend ostream & operator<<(ostream &, const TListaCalendario &);
};

#endif
