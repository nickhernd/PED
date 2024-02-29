#include <iostream>
#include "tcalendario.h"

bool TCalendario::esBisiesto(int anyo)  {
    return ((anyo % 4 == 0 && anyo % 100 != 0) || (anyo % 400 == 0));
}

bool TCalendario::comprobarFecha(int dia, int mes, int anyo){
    if(dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && anyo >= 1900){

        if(esBisiesto(anyo) && mes==2 && dia > 29)
            return false; 
        
        else if(!esBisiesto(anyo) && mes == 2 && dia > 28)
                return false;
        
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
            if(dia > 30)
                return false;
        }
        return true;
    }
    return false;
}

TCalendario::TCalendario() {
    this->dia = 1;
    this->mes = 1;
    this->anyo = 1900;
    this->mensaje = NULL;
}

TCalendario::TCalendario(int dia, int mes, int anyo, char* mensaje) {
    if(comprobarFecha(dia, mes, anyo)){
        this->dia = dia;
        this->mes = mes;
        this->anyo = anyo;

        if(mensaje != NULL){
            this->mensaje = new char[strlen(mensaje)+1];
            strcpy(this->mensaje, mensaje);
        }
        else this->mensaje = NULL;
    } else {
        this->dia = 1;
        this->mes = 1;
        this->anyo = 1900;
        this->mensaje = NULL;
    }
}

TCalendario::TCalendario(TCalendario &tcalendario) {
    if(comprobarFecha(tcalendario.dia, tcalendario.mes, tcalendario.anyo)){
        this->dia = tcalendario.dia;
        this->mes = tcalendario.mes;
        this->anyo = tcalendario.anyo;

        if(tcalendario.mensaje != NULL){
            this->mensaje = new char[strlen(tcalendario.mensaje)+1];
            strcpy(this->mensaje, tcalendario.mensaje);
        }
        else this->mensaje = NULL;
    } else {
        this->dia = 1;
        this->mes = 1;
        this->anyo = 1900;
        this->mensaje = NULL;
    }
}

TCalendario &TCalendario::operator=(const TCalendario &tcalendario) {
    if(comprobarFecha(tcalendario.dia, tcalendario.mes, tcalendario.anyo)){
        this->dia = tcalendario.dia;
        this->mes = tcalendario.mes;
        this->anyo = tcalendario.anyo;

        if(tcalendario.mensaje != NULL){
            this->mensaje = new char[strlen(tcalendario.mensaje)+1];
            strcpy(this->mensaje, tcalendario.mensaje);
        }
        else this->mensaje = NULL;
    }
    
    return *this;
}

TCalendario::~TCalendario(){
    this->dia = 1;
    this->mes = 1;
    this->anyo = 1900;

    if(this->mensaje != NULL){
        delete []this->mensaje;
    }
        
    this->mensaje = NULL;
}

// Función privada para obtener el número de días en un mes
int obtenerDiasEnMes(int mes, int anyo)  {
    if (mes == 2) {
        if((anyo % 4 == 0 && anyo % 100 != 0) || (anyo % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Operador + para incrementar días
TCalendario TCalendario::operator+(int dias) {
    TCalendario tcalendario(*this);

    while (dias > 0) {

        int diasEnEsteMes = obtenerDiasEnMes(tcalendario.mes, tcalendario.anyo) - tcalendario.dia + 1;

        if (dias >= diasEnEsteMes) {
            dias = dias - diasEnEsteMes;
            tcalendario.dia = 1;
            if (tcalendario.mes == 12) {
                tcalendario.mes = 1;
                tcalendario.anyo++;
            } else {
                tcalendario.mes++;
            }
        } else {
            // Incrementar dentro del mismo mes
            tcalendario.dia += dias;
            dias = 0;
        }
    }

    return tcalendario;
}

TCalendario TCalendario::operator-(int dias)  {
    TCalendario tcalendario(*this);

    int auxdia = 0;

   while (dias > 0) {
        if(dias > tcalendario.dia) {
            auxdia = tcalendario.dia;
            tcalendario.mes = tcalendario.mes -1;
            if(tcalendario.mes == 0) {
                tcalendario.mes = 12;
                tcalendario.anyo = tcalendario.anyo -1;
            }
            tcalendario.dia = obtenerDiasEnMes(tcalendario.mes, tcalendario.anyo);
            dias = dias - auxdia;
        } else {
            tcalendario.dia = tcalendario.dia - dias;
            if(tcalendario.dia == 0) {
                tcalendario.mes = tcalendario.mes - 1;
                if(tcalendario.mes == 0) {
                    tcalendario.mes = 12;
                    tcalendario.anyo--;
                }
                tcalendario.dia = obtenerDiasEnMes(tcalendario.mes, tcalendario.anyo);
            }
            dias -= dias;
        }
    }

    if(tcalendario.anyo < 1900) {
        tcalendario.dia =1;
        tcalendario.mes = 1;
        tcalendario.anyo = 1900;
        tcalendario.mensaje = NULL;
    }

    return tcalendario;
}


TCalendario TCalendario::operator++(int dias) {
    TCalendario tcalendario(*this);

    while (dias > 0) {

        int diasEnEsteMes = obtenerDiasEnMes(mes, anyo) - dia + 1;

        if (dias >= diasEnEsteMes) {
            // Mover al siguiente mes
            dias -= diasEnEsteMes;
            dia = 1;
            if (mes == 12) {
                mes = 1;
                anyo++;
            } else {
                mes++;
            }
        } else {
            // Incrementar dentro del mismo mes
            dia += dias;
            dias = 0;
        }
    }

    return tcalendario;
}

TCalendario & TCalendario::operator++() {

        int dias = 1;

        int diasEnEsteMes = obtenerDiasEnMes(this->mes, this->anyo) - this->dia + 1;

        if (dias >= diasEnEsteMes) {
            // Mover al siguiente mes
            dias -= diasEnEsteMes;
            this->dia = 1;
            if (this->mes == 12) {
                this->mes = 1;
                this->anyo++;
            } else {
                this->mes++;
            }
        } else {
            // Incrementar dentro del mismo mes
            this->dia += dias;
        }
    

    return *this;
}

TCalendario TCalendario::operator--(int dias) {
    TCalendario tcalendario(*this);
    int auxdia = 0;

   while (dias > 0) {
        if(dias > dia) {
            auxdia = dia;
            mes = mes -1;
            if(mes == 0) {
                mes = 12;
                anyo = anyo -1;
            }
            dia = obtenerDiasEnMes(mes, anyo);
            dias = dias - auxdia;
        } else {
            dia = dia - dias;
            if(dia == 0) {
                mes = mes - 1;
                if(mes == 0) {
                    mes = 12;
                    anyo--;
                }
                dia = obtenerDiasEnMes(mes, anyo);
            }
        }
    }

    if(anyo < 1900) {
        dia = 1;
        mes = 1;
        anyo = 1900;
    }

    return tcalendario;
}

TCalendario & TCalendario::operator--() {
    int dias = 1;
    int auxdia = 0;

   while (dias > 0) {
        if(dias > this->dia) {
            auxdia = this->dia;
            this->mes = this->mes -1;
            if(this->mes == 0) {
                this->mes = 12;
                this->anyo = this->anyo -1;
            }
            this->dia = obtenerDiasEnMes(this->mes, this->anyo);
            dias = dias - auxdia;
        } else {
            this->dia = this->dia - dias;
            if(this->dia == 0) {
                this->mes = this->mes - 1;
                if(this->mes == 0) {
                    this->mes = 12;
                    this->anyo--;
                }
                this->dia = obtenerDiasEnMes(this->mes, this->anyo);
            }
        }
    }

    if(this->anyo < 1900) {
        this->dia = 1;
        this->mes = 1;
        this->anyo = 1900;
    }

    return *this;
}

bool TCalendario::EsVacio() {
    if(this->dia == 1 && this->mes == 1 && this->anyo == 1900 && this->mensaje == NULL) {
        return true;
    }
    return false;
}

bool TCalendario::ModFecha(int dia, int mes, int anyo) {
    if(comprobarFecha(dia, mes, anyo)) {
        this->dia = dia; 
        this->mes = mes;
        this->anyo = anyo;
        return true;
    }

    return false;
}

bool TCalendario::ModMensaje(char * mensaje){

    if(mensaje == NULL){
        this->mensaje = NULL;
        return true;
    }else{
        delete [] this->mensaje;
        this->mensaje = new char[strlen(mensaje)];
        strcpy(this->mensaje, mensaje); 
        return true;
    }
    return false;
}

bool TCalendario::operator==(TCalendario &tcalendario) {
    if(this->dia == tcalendario.dia && this->mes == tcalendario.mes && this->anyo == tcalendario.anyo && strcpy(this->mensaje, tcalendario.mensaje)) {
        return true;
    }
    return false;
}

bool TCalendario::operator!=(TCalendario &tcalendario) {
    if(this->dia == tcalendario.dia && this->mes == tcalendario.mes && this->anyo == tcalendario.anyo && strcpy(this->mensaje, tcalendario.mensaje)) {
        return false;
    }
    return true;
}

bool TCalendario::operator> ( TCalendario &tcalendario){
    if(this->anyo > tcalendario.anyo)
        return true;
    else if(this->anyo == tcalendario.anyo && this->mes > tcalendario.mes )
        return true;
    else if(this->anyo == tcalendario.anyo && this->mes == tcalendario.mes && this->dia > tcalendario.dia)
        return true;
    else if((this->anyo == tcalendario.anyo && this->mes == tcalendario.mes && this->dia == tcalendario.dia)
            && this->mensaje != tcalendario.mensaje){
        if(this->mensaje == NULL)
            return false;
        else if(tcalendario.mensaje == NULL)
            return true;
        else{
            if(strcmp(this->mensaje, tcalendario.mensaje) == 0)
                return false;
            else if(strcmp(this->mensaje, tcalendario.mensaje) > 0)
                return true;
            else return false;
        }
    }
    return false;
}

bool TCalendario::operator< ( TCalendario &tcalendario){
    if((*this)==tcalendario)
        return false;
    else return !(*this>tcalendario);
}

ostream &operator<<(ostream &os, const TCalendario &tcalendario){

    if(tcalendario.dia < 10)
        os << "0" << tcalendario.dia;
    else os << tcalendario.dia;

    os << "/";

    if(tcalendario.mes < 10)
        os << "0" << tcalendario.mes;
    else os << tcalendario.mes;

    os << "/";
    os << tcalendario.anyo << " ";
    
    if(tcalendario.mensaje != NULL)
        os <<"\"" << tcalendario.mensaje << "\"";
    else
        os << "\"\"";
    
    return os;
}


