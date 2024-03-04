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
        delete [] this->mensaje;
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

    for(int i = 0; i < dias; i++){
        tcalendario++; 
    }

    return tcalendario;
}

TCalendario TCalendario::operator-(int dias)  {
    TCalendario tcalendario(*this);
    
    for(int i = 0; i < dias; i++){   
        tcalendario--;
    }

    if(!comprobarFecha(tcalendario.dia, tcalendario.mes, tcalendario.anyo)){
        tcalendario.~TCalendario();
    }

    return tcalendario;
}

TCalendario TCalendario::operator++(int cantDias){
    TCalendario tcalendario(*this);
    if(mes == 2){
        if(dia ==29 && esBisiesto(anyo)){
                dia = 1;
                mes ++;             
        }else if(dia==28 && !esBisiesto(anyo)){
                dia = 1;
                mes++;
        }
        else{
            dia++;
        }        
    }
    else if(mes == 12 ){
        if (dia == 31){
            dia = 1;
            anyo++;
            mes = 1;
            
        }else{
            dia++;
        }
    }
    else if(mes ==4|| mes ==6 || mes==9 || mes==11){
        if(dia==30){
            mes ++;
            dia=1;
        }
        else{
            dia ++;
        }
    }
    else if(mes ==1|| mes ==3 || mes==5 || mes==7 ||mes ==8 ||mes ==10 ){
        if(dia==31){
            dia=1;
            mes ++;
            
        }
        else{
            dia ++;
        }
    }
    return tcalendario;
}

TCalendario & TCalendario::operator++(){
    if(mes == 2){
        if(dia ==29 && esBisiesto(anyo)){
                dia = 1;
                mes ++;             
        }else if(dia==28 && !esBisiesto(anyo)){
                dia = 1;
                mes++;
        }
        else{
            dia++;
        }        
    }
    else if(mes == 12 ){
        if (dia == 31){
            dia = 1;
            anyo++;
            mes = 1;
            
        }else{
            dia++;
        }
    }
    else if(mes ==4|| mes ==6 || mes==9 || mes==11){
        if(dia==30){
            mes ++;
            dia=1;
        }
        else{
            dia ++;
        }
    }
    else if(mes ==1|| mes ==3 || mes==5 || mes==7 ||mes ==8 ||mes ==10 ){
        if(dia==31){
            dia=1;
            mes ++;
            
        }
        else{
            dia ++;
        }
    }
    return *this;
}

TCalendario TCalendario::operator--(int cantDias){
    TCalendario tcalendario(*this);
    dia--;
    if(dia == 0){
        mes--;
        if(mes == 0){
            mes = 12;
            anyo--;
        }
        if(mes == 2 && !esBisiesto(this->anyo))
            dia = 28;
        else if(mes == 2 && esBisiesto(this->anyo))
            dia = 29;
        else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||
                mes == 10 || mes == 12)
            dia = 31;
        else dia = 30;
    }

    if(!comprobarFecha(this->dia, this->mes, this->anyo)){
        this->~TCalendario();
    }

    return tcalendario;
}

TCalendario & TCalendario::operator--(){
    dia--;
    if(dia == 0){
        mes--;
        if(mes == 0){
            mes = 12;
            anyo--;
        }
        if(mes == 2 && !esBisiesto(this->anyo))
            dia = 28;
        else if(mes == 2 && esBisiesto(this->anyo))
            dia = 29;
        else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||
                mes == 10 || mes == 12)
            dia = 31;
        else dia = 30;
    }

    if(!comprobarFecha(this->dia, this->mes, this->anyo)){
        this->~TCalendario();
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
    if(this->dia == tcalendario.dia && this->mes == tcalendario.mes && this->anyo == tcalendario.anyo && strcmp(this->mensaje, tcalendario.mensaje)) {
        return true;
    }
    return false;
}

bool TCalendario::operator!=(TCalendario &tcalendario) {
    if(this->dia == tcalendario.dia && this->mes == tcalendario.mes && this->anyo == tcalendario.anyo && strcmp(this->mensaje, tcalendario.mensaje)) {
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


