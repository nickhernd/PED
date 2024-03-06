#include <iostream>
#include "tvectorcalendario.h"

using namespace std;

bool TVectorCalendario::esBisiesto(int anyo)  {
    return ((anyo % 4 == 0 && anyo % 100 != 0) || (anyo % 400 == 0));
}

bool TVectorCalendario::comprobarFecha(int dia, int mes, int anyo){
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

TVectorCalendario::TVectorCalendario(){
    this->tamano = 0;
    this->c = NULL;
}

TVectorCalendario::TVectorCalendario(int tam){
    if(tam <= 0){
        this->tamano = 0;
        this->c = NULL;
    } else {
        this->tamano = tam;
        this->c = new TCalendario[tamano];
        if(c == NULL){
            this->tamano = 0;
        }
    }
}

TVectorCalendario::~TVectorCalendario(){
    if (c!=NULL) {
        delete [] c;
        this->c = NULL;
        this->tamano = 0;
    }
}

TVectorCalendario &TVectorCalendario::operator=(const TVectorCalendario &tvector) {
    if(this->c != NULL) {
        this->~TVectorCalendario();
    } 
    
    this->c = new TCalendario[tvector.tamano];

    for(int i = 0; i < tvector.tamano; i++) {
        this->c[i] = tvector.c[i];
    }

    this->tamano = tvector.tamano;
    
    return *this;
}

bool TVectorCalendario::operator==(TVectorCalendario &tvector) {
    if(this->tamano == tvector.tamano) {
        for(int i = 0; i < tvector.tamano; i++){
            if(this->c[i] != tvector.c[i])
                return false;
        }
    } else {
        return false;
    }

    return true;
}

bool TVectorCalendario::operator!=(TVectorCalendario &tvector) {
    if(this->tamano == tvector.tamano) {
        for(int i = 0; i < this->tamano; i++){
            if(this->c[i] != tvector.c[i])
                return true;
        }
    } else {
        return true;
    }

    return false;
}

TCalendario & TVectorCalendario::operator[](int pos) {
    if(pos <= 0 || pos > this->tamano ) {
        return error;
    }

    return this->c[pos-1];
}

TCalendario TVectorCalendario::operator[](int pos) const {
    TCalendario tcal;

    if(pos <= 0 || pos > tamano) {
        return tcal;
    }

    return c[pos-1];
}

int TVectorCalendario::Ocupadas() {
    int cont = 0;
    TCalendario cal; 

    if(this->c == NULL) {
        return cont;
    }

    for(int i  = 0; i < this->tamano; i++) {
        if(!this->c[i].EsVacio())
            cont++;
    }

    return cont;
}

bool TVectorCalendario::ExisteCal(TCalendario &calendario) {
    for(int i = 0; i < this->tamano; i++){       
        if(calendario == this->c[i]){
            return true;
        } 
    } 
    return false;
}

void TVectorCalendario::MostrarMensajes(int dia, int mes,int anyo) {

    TCalendario *calendario = new TCalendario(dia, mes, anyo, NULL);

    if(comprobarFecha(dia, mes, anyo) || c == NULL) {
        cout << "[]"; 
    } else {
        cout << "[";
        for (int i = 0; i < tamano; i++) {
            if(*calendario > c[i] || *calendario == c[i]) {
                cout << c[i];
            }
            if(i < tamano-1) {
                cout << "z, ";
            }
        }
        cout << "]";
    }

}

bool TVectorCalendario::Redimensionar(int tam){
    if(tam <= 0)
        return false;
    if(tam == this->tamano)
        return false;

    TCalendario *aux = new TCalendario[tam];
    TCalendario *vacio = new TCalendario();

    if(tam > this->tamano){
        for(int i = 0; i < tam; i++){
            if(i < this->tamano)
                aux[i] = this->c[i];
            else aux[i] = (*vacio);
        } 

        (*this).~TVectorCalendario();   
        this->c = aux;
        this->tamano = tam;

        delete vacio;
        return true;  
    }
    else{
        for(int i = 0; i < tam; i++)
            aux[i] = this->c[i];

        (*this).~TVectorCalendario();   
        this->c = aux;
        this->tamano = tam;
        
        delete vacio;

        return true;  
    }
}

ostream & operator<<(ostream & os, TVectorCalendario &tvector) {
    if(tvector.c == NULL) {
        os << "[]"; 
    } else {
        os << "[";
        for (int i = 0; i < tvector.tamano; i++) {
            
            os << "(" << i+1 << ") "  << tvector.c[i];
            
            if(i < tvector.tamano-1) {
                os << ", ";
            }
        }
        os << "]";
    }

    return os;
}