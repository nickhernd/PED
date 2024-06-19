#include<iostream>
#include"tcalendario.h"
using namespace std;

#ifndef _TVECTORCALENDARIO_H_
#define _TVECTORCALENDARIO_H_

//! Clase TVectorCalendario
/*! Clase que representa el calendario */
class TVectorCalendario
{
	private:
		//! c
		/*! Variable de tipo puntero a TCalendario que apunta a calendario */
		TCalendario *c; // Uso de LAYERING sobre la clase
		//! tamano
		/*! Variable de tipo  entero con el tamano del vector */
		int tamano;
		//! error
		/*! Variable de tipo TCalendario con un calendario creado por defecto */
		TCalendario error;
	public:
		//! Constructor
		/*! Constructor por defecto de la clase TVectorCalendario */
		TVectorCalendario();
		//! Constructor sobrecargado
		/*! Constructor sobrecargado de la clase TVectorCalendario */
		TVectorCalendario(int);
		//! Constructor de copia
		/*! Constructor copia de la clase TVectorCalendario */
		TVectorCalendario(const TVectorCalendario &);
		//! Destructor
		/*! Destructor de la clase TVectorCalendario */
		~TVectorCalendario();
		//! Operador asignacion
		/*! Operador asignacion de la clase TVectorCalendario */
		TVectorCalendario & operator=(const TVectorCalendario &);
		//! Operador igualdad
		/*! Operador igualdad de la clase TVectorCalendario */
		bool operator==(const TVectorCalendario &);
		//! Operador desigualdad
		/*! Operador desigualdad de la clase TVectorCalendario */
		bool operator!=(const TVectorCalendario &);
		//! Operador corchetes izquierda
		/*! Operador corchetes izquierda de la clase TVectorCalendario */
		TCalendario & operator[](int);
		//! Operador corchetes derecha
		/*! Operador corchetes derecha de la clase TVectorCalendario */
		TCalendario operator[](int) const;
		//! Funcion Tamano
		/*! Funcion Tamano de la clase TVectorCalendario */
		int Tamano()const;
		//! Funcion Ocupadas
		/*! Funcion Ocupadas de la clase TVectorCalendario */
		int Ocupadas()const;
		//! Funcion ExisteCal
		/*! Funcion ExisteCal de la clase TVectorCalendario */
		bool ExisteCal(const TCalendario &);
		//! Funcion MostrarMensajes
		/*! Funcion MostrarMensajes de la clase TVectorCalendario */
		void MostrarMensajes(int,int,int);
		//! Funcion Redimensionar
		/*! Funcion Redimensionar de la clase TVectorCalendario */
		bool Redimensionar(int);
	//! Sobrecarga operador de salida
	/*! Funcion amiga. Sobrecarga del operador de salida de la clase TVectorCalendario */
	friend ostream & operator<<(ostream &, const TVectorCalendario &);
};
#endif
