#include "tabbcalendario.h"
#include <iostream>
#include <queue>

// TNodoABB

TNodoABB::TNodoABB() : item(), iz(), de() {}

TNodoABB::TNodoABB(const TNodoABB &tn) : item(tn.item), iz(tn.iz), de(tn.de) {}

TNodoABB::~TNodoABB() {}

TNodoABB & TNodoABB::operator=(const TNodoABB &tnodo) {
    if(this != &tnodo){
        this->~TNodoABB();
        this->iz = tnodo.iz;
        this->de = tnodo.de;
        this->item = tnodo.item;
    }
    return *this;
}

// TABBCalendario

bool TABBCalendario::EsVacio() const {
    return (raiz == NULL);
}

TCalendario TABBCalendario::Raiz() const {
    TCalendario aux;

    if(raiz != NULL){
        aux = raiz->item;
    }

    return aux;
}

void TABBCalendario::InordenAux(TVectorCalendario &tvec, int &pos) const {
    if(raiz != NULL){
        (raiz->iz).InordenAux(tvec, pos);
        tvec[pos] = Raiz();
        pos++;
        (raiz->de).InordenAux(tvec, pos);
    }
}

void TABBCalendario::PreordenAux(TVectorCalendario &tvec, int &pos) const {
    if(raiz != NULL){
        tvec[pos] = Raiz();
        pos++;
        (raiz->iz).PreordenAux(tvec, pos);
        (raiz->de).PreordenAux(tvec, pos);
    }
}

void TABBCalendario::PostordenAux(TVectorCalendario &tvec, int &pos) const {
    if(raiz != NULL){
        (raiz->iz).PostordenAux(tvec, pos);
        (raiz->de).PostordenAux(tvec, pos);
        tvec[pos] = Raiz();
        pos++;
    }
}

int TABBCalendario::Altura() const {
    int altura_iz = 0;
    int altura_de = 0;
    
    if(EsVacio()){
        return 0;
    } else {
        altura_iz = (raiz->iz).Altura();
        altura_de = (raiz->de).Altura();
        return (1 + max(altura_iz, altura_de));
    }
}

int TABBCalendario::Nodos() const {
    if(EsVacio()){
        return 0;
    }
    else{
        return (1 + (raiz->iz).Nodos() + (raiz->de).Nodos());
    }
}

int TABBCalendario::NodosHoja() const {
    if(EsVacio()){
        return 0;
    } else {
        if((raiz->iz).EsVacio() && (raiz->de).EsVacio()){
            return 1;
        } else {
            return (raiz->iz).NodosHoja() + (raiz->de).NodosHoja();
        }
    }
}

/**
 *  Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario.
 */
bool TABBCalendario::Buscar(const TCalendario &cal) const
{
    if(EsVacio()){
        return false;
    }
    if(raiz->item == cal){
        return true;
    } else {
        return (raiz->iz).Buscar(cal) || (raiz->de).Buscar(cal);
    }
}

TABBCalendario::TABBCalendario()
{
    raiz = NULL;
}

void TABBCalendario::Copiar(const TABBCalendario &tabb)
{
    if(tabb.raiz != NULL){
        TNodoABB *aux = new TNodoABB();
        aux->item = tabb.raiz->item;
        raiz = aux;
        (raiz->iz).Copiar(tabb.raiz->iz);
        (raiz->de).Copiar(tabb.raiz->de);
    }
    else raiz = NULL;
}

TABBCalendario::TABBCalendario(const TABBCalendario &tabb)
{
    if(this != &tabb) Copiar(tabb);
}

TABBCalendario::~TABBCalendario()
{
    if(raiz != NULL){
        delete raiz;
        raiz = NULL;
    }
}

TABBCalendario & TABBCalendario::operator=(const TABBCalendario &tabb)
{
    if(this != &tabb){
        this->~TABBCalendario();
        Copiar(tabb);
    }
    return *this;
}

bool TABBCalendario::Insertar(TCalendario &cal)
{
    bool insert = false;

    if(Buscar(cal)){
        return false;
    }

    if(EsVacio()){
        TNodoABB *nodo = new TNodoABB();
        raiz = nodo;
        raiz->item = cal;
        insert = true;
    }
    else{
        if(cal < raiz->item){
            insert = raiz->iz.Insertar(cal);
        }
        else{ 
            insert = raiz->de.Insertar(cal);
        }
    }
    return insert;
}

bool TABBCalendario::operator==(const TABBCalendario &tabb)
{
    TVectorCalendario vIZ = Inorden();
    TVectorCalendario vDE = tabb.Inorden();

    if(vIZ == vDE){
        return true;
    }
    return false;
}

TCalendario TABBCalendario::mayorIz()
{
    TCalendario cal;

    if(EsVacio()) {
        return cal;
    }
    else{
        if((raiz->de).EsVacio()){
            cal = raiz->item;
        }
        else {
            cal = raiz->de.mayorIz();
        }
    }
    return cal;
}

bool TABBCalendario::Borrar( TCalendario &cal)
{
    bool borrar = false;
    TCalendario mayorIz;
    TNodoABB *nodo;

    if(EsVacio()){ 
        return false;
    }

    if(cal < raiz->item){ 
        borrar = raiz->iz.Borrar(cal);
    }
    else if(cal > raiz->item){ 
        borrar = raiz->de.Borrar(cal); 
    }
    else{ 
        borrar = true;

        if((raiz->iz).EsVacio() && (raiz->de).EsVacio()){
            delete raiz;
            raiz = NULL;
        }
        
        else if(!(raiz->iz).EsVacio() && (raiz->de).EsVacio()){
            nodo = raiz;
            raiz = (raiz->iz).raiz; 
            nodo->iz.raiz = NULL;
            delete nodo; 
            nodo = NULL;
        }

        else if((raiz->iz).EsVacio() && !(raiz->de).EsVacio()){
            nodo = raiz;
            raiz = (raiz->de).raiz; 
            nodo->de.raiz = NULL;
            delete nodo;
            nodo = NULL;
        }
        
        else{
            mayorIz = raiz->iz.mayorIz(); 
            raiz->item = mayorIz; 
            borrar = raiz->iz.Borrar(mayorIz);
        }
    }
    return borrar;
}

TVectorCalendario TABBCalendario::Inorden() const {
    int pos = 1;
    // Vector del tamaño adecuado para almacenar todos los nodos
    TVectorCalendario v(Nodos());
    InordenAux(v, pos);
    return v;
}

TVectorCalendario TABBCalendario::Preorden() const
{
    int pos = 1;
    // Vector del tamaño adecuado para almacenar todos los nodos
    TVectorCalendario v(Nodos());
    PreordenAux(v, pos);
    return v;
}

TVectorCalendario TABBCalendario::Postorden() const
{
    int pos = 1;
    // Vector del tamaño adecuado para almacenar todos los nodos
    TVectorCalendario v(Nodos());
    PostordenAux(v, pos);
    return v;
}

TVectorCalendario TABBCalendario::Niveles() const
{
    TVectorCalendario v(Nodos());

    if(EsVacio()){
        return v;
    }
    else{
        int pos = 1;
        queue<TABBCalendario> abbCOLA;
        TABBCalendario aux = (*this);
        abbCOLA.push(aux);

        while(!abbCOLA.empty()){
            aux = abbCOLA.front();
            v[pos] = aux.Raiz();
            pos++;
            abbCOLA.pop();
            if(!(aux.raiz->iz).EsVacio()){
                abbCOLA.push(aux.raiz->iz);
            }
            if(!(aux.raiz->de).EsVacio()){
                abbCOLA.push(aux.raiz->de);
            }
        }
    }
    return v;
}

TABBCalendario TABBCalendario::operator+(const TABBCalendario &tabb)
{
    TABBCalendario aux(*this);
    TVectorCalendario v = tabb.Inorden();

    for(int i = 1; i <= v.Tamano(); i++){
        aux.Insertar(v[i]);
    }
    return aux;
}

TABBCalendario TABBCalendario::operator-(const TABBCalendario &tabb)
{
    TABBCalendario aux;
    TVectorCalendario v = Inorden();

    for(int i = 1; i <= v.Tamano(); i++){
        if(!tabb.Buscar(v[i])){
            aux.Insertar(v[i]);
        }
    }
    return aux;
}

ostream& operator<<(ostream &os,TABBCalendario &tabb)
{
    os << tabb.Inorden();
    return os;
}