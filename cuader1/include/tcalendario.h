// GUARDAS DE INCLUSIÓN
#ifndef _TCALENDARIO_H_
#define _TCALENDARIO_H_  

#include <string.h>
#include <iostream>

using namespace std;

class TCalendario{
    private:
        int dia;
        int mes; 
        int anyo;
        char* mensaje;
        bool esBisiesto(int);
        bool comprobarFecha(int, int, int);
    
    public:
        TCalendario();
        TCalendario(int dia, int mes, int anyo, char* mensaje);
        TCalendario(TCalendario &);
        ~TCalendario();
        TCalendario &operator=(const TCalendario &);
       
        // OPERADORES
        TCalendario operator+(int);
        TCalendario operator-(int);
        TCalendario operator++(int);
        TCalendario & operator++();
        TCalendario operator--(int);
        TCalendario & operator--();

        // BOLEANOS MODIFICADORES
        bool ModFecha (int, int, int);
        bool ModMensaje(char *);

        // SOBRECARGA DE OPERADORES
        bool operator==(TCalendario &);
        bool operator!=(TCalendario &);
        bool operator>(TCalendario &);
        bool operator<(TCalendario &);


        //TCalendario vacío
        bool EsVacio();
        
        // GETTERS (De)
        int Dia() {return this->dia;};
        int Mes() {return this->mes;};
        int Anyo() {return this->anyo;};
        // Devuelve el mensaje del calendario;
        char *Mensaje() {return this->mensaje;};
        // Sobrecarga del operador salida
        friend ostream & operator<<(ostream &, const TCalendario &);
};

#endif 
