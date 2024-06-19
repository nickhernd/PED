#include<iostream>
using namespace std;

#ifndef _TCALENDARIO_H_
#define _TCALENDARIO_H_

//! Clase TCalendario
/*! Clase que representa el calendario */
class TCalendario
{
	private:
		//! dia
		/*! Variable de tipo entero que indica el numero del dia */
		int dia;
		//! mes
		/*! Variable de tipo entero que indica el numero del mes */
		int mes;
		//! anyo
		/*! Variable de tipo entero que indica el numero del anyo */
		int anyo;
		//! mensaje
		/*! Variable de tipo puntero a char que indica el mensaje de la fecha */
		char* mensaje;
	public:
		//! Constructor
		/*! Constructor por defecto de la clase TCalendario */
		TCalendario ();
		//! Constructor sobrecargado
		/*! Constructor sobrecargado de la clase TCalendario */
		TCalendario(int dia, int mes, int anyo, char * mens);
		//! Constructor de copia
		/*! Constructor copia de la clase TCalendario */
		TCalendario (const TCalendario &);
		//! Destructor
		/*! Destructor de la clase TCalendario */
		~TCalendario();
		//! Operador asignacion
		/*! Operador asignacion de la clase TCalendario */
		TCalendario & operator=(const TCalendario &);
		//! Operador suma
		/*! Operador suma de la clase TCalendario */
		TCalendario operator+(int);
		//! Operador resta
		/*! Operador resta de la clase TCalendario */
		TCalendario operator-(int);
		//! Operador postincremento
		/*! Operador postincremento de la clase TCalendario */
		TCalendario operator++(int);
		//! Operador preincremento
		/*! Operador preincremento de la clase TCalendario */
		TCalendario &operator++();
		//! Operador posdecremento
		/*! Operador posdecremento de la clase TCalendario */
		TCalendario operator--(int);
		//! Operador predecremento
		/*! Operador predecremento de la clase TCalendario */
		TCalendario &operator--();
		//! Funcion ModFecha
		/*! Funcion ModFecha de la clase TCalendario */
		bool ModFecha(int, int, int);
		//! Funcion ModMensaje
		/*! Funcion ModMensaje de la clase TCalendario */
		void ModMensaje(char *);
		//! Operador igualdad
		/*! Operador igualdad de la clase TCalendario */
		bool operator ==(const TCalendario &);
		//! Operador desigualdad
		/*! Operador desigualdad de la clase TCalendario */
		bool operator !=(const TCalendario &);
		//! Operador mayor que
		/*! Operador mayor que de la clase TCalendario */
		bool operator>(const TCalendario &)const;
		//! Operador menor que
		/*! Operador menor que de la clase TCalendario */
		bool operator<(const TCalendario &)const;
		//! Funcion EsVacio
		/*! Funcion EsVacio de la clase TCalendario */
		bool EsVacio() const;
		//! Funcion Dia
		/*! Funcion Dia de la clase TCalendario */
		int Dia() const;
		//! Funcion Mes
		/*! Funcion Mes de la clase TCalendario */
		int Mes() const;
		//! Funcion Anyo
		/*! Funcion Anyo de la clase TCalendario */
		int Anyo() const;
		//! Funcion Mensaje
		/*! Funcion Mensaje de la clase TCalendario */
		char *Mensaje();
	//! Sobrecarga operador de salida
	/*! Funcion amiga. Sobrecarga del operador de salida de la clase TCalendario */
	friend ostream & operator<<(ostream &, const TCalendario &);
};
#endif
