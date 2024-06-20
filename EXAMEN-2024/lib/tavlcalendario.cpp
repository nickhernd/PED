#include<iostream>
#include "tavlcalendario.h"


//! Constructor por defecto
/*! 
Constructor por defecto de la clase telemcolaavlcalendario que pone el puntero arbol y sig a null
*/
TElemColaAVLCalendario::TElemColaAVLCalendario()
{
	arbol=NULL;
	sig=NULL;
}

//! Constructor de Copia
/*! 
Constructor de copia que crea un vector a partir de otro
\param co copia del objeto
*/
TElemColaAVLCalendario::TElemColaAVLCalendario (const TElemColaAVLCalendario &c)
{
	arbol=c.arbol;
	sig=c.sig;;
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\param c el objeto a copiar
\return *this el propio objeto
*/
TElemColaAVLCalendario & TElemColaAVLCalendario::operator=(const TElemColaAVLCalendario &c)
{
	this->~TElemColaAVLCalendario();
	arbol=c.arbol;
	sig=c.sig;
	return (*this);
}

//! Arbol
/*! 
Funcion que devuelve el puntero a arbol
\return arbol puntero
*/
TAVLCalendario* TElemColaAVLCalendario::Arbol()
{
	return(arbol);
}

//! Constructor por defecto
/*! 
Constructor por defecto de la clase tcolaavlcalendario que pone el puntero primero y ultimo a null
*/
TColaAVLCalendario::TColaAVLCalendario()
{
	primero=NULL;
	ultimo=NULL;
}

//! Constructor de Copia
/*! 
Constructor de copia que crea una colaavlcalendario a partir de otra
\param co copia del objeto
*/
TColaAVLCalendario::TColaAVLCalendario (const TColaAVLCalendario &c)
{
	TElemColaAVLCalendario *aux,*aux1;
	primero=NULL;
	ultimo=NULL;
	if(!c.EsVacia())
	{
		aux=c.primero;
		while(aux!=NULL)
		{
			aux1=new TElemColaAVLCalendario();
			if(!aux1) cout<<"Error al reservar memoria"<<endl;
			else
			{
				aux1->arbol=aux->arbol;
				aux1->sig=NULL;
				if(primero==NULL)
				{
					primero=aux1;
					ultimo=aux1;
				}
				else
				{
					ultimo->sig=aux1;
					ultimo=aux1;
				}
				aux=aux->sig;
			}
		}
	}
}

//! Destructor de la clase
/*! 
Destructor que elimina la cola avl y pone sus punteros primero y ultimo a null
*/
TColaAVLCalendario::~TColaAVLCalendario()
{
	TElemColaAVLCalendario *aux,*aux1;
	if(!EsVacia())
	{
		aux=primero;
		while(aux!=NULL)
		{
			aux1=aux;
			aux=aux->sig;
			delete aux1;
			aux1=NULL;
		}
		primero=NULL;
		ultimo=NULL;
	}
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\param c el objeto que se va a copiar
\return *this el propio objeto
*/
TColaAVLCalendario & TColaAVLCalendario::operator=(const TColaAVLCalendario &c)
{
	TElemColaAVLCalendario *aux,*aux1;
	primero=NULL;
	ultimo=NULL;
	this->~TColaAVLCalendario();
	if(!c.EsVacia())
	{
		aux=c.primero;
		while(aux!=NULL)
		{
			aux1=new TElemColaAVLCalendario();
			if(!aux1) cout<<"Error al reservar memoria"<<endl;
			else
			{
				aux1->arbol=aux->arbol;
				aux1->sig=NULL;
				if(primero==NULL)
				{
					primero=aux1;
					ultimo=aux1;
				}
				else
				{
					ultimo->sig=aux1;
					ultimo=aux1;
				}
				aux=aux->sig;
			}
		}
	}
	return (*this);
}

//! Operador igualdad
/*! 
Sobrecarga del operador igualdad
\param c parametro de tipo tcolaavlcalendario pasado por referencia  
\return bool devuelve true si son iguales
*/
bool TColaAVLCalendario::operator==(const TColaAVLCalendario &c)
{
	bool retorno=true, encontrado=false;
	TElemColaAVLCalendario *aux,*aux1;
	aux=primero;
	aux1=c.primero;
	if(Longitud()!=c.Longitud()) retorno=false;
	else
	{
		if(!EsVacia())
		{
			while(aux!=NULL && !encontrado)
			{
				if(aux!=aux1) 
				{
					retorno=false;
					encontrado=true;
				}
				aux=aux->sig;
				aux1=aux1->sig;
			}
		}
	}
	return retorno;
}

//! Operador suma
/*! 
Sobrecarga del operador suma
\param c parametro de tipo tcolaavlcalendario pasado por referencia  
\return TColaAVLCalendario con el calendario resultante
*/
TColaAVLCalendario TColaAVLCalendario::operator+(const TColaAVLCalendario &c)
{
	TColaAVLCalendario retorno(*this);
	TElemColaAVLCalendario *aux;
	if(EsVacia()) return c;
	else
	{
		if(!c.EsVacia())
		{
			aux=c.primero;
			while(aux!=NULL)
			{
				retorno.Encolar(aux->arbol);
				aux=aux->sig;
			}
		}
		return retorno;
	}
}

//! EsVacia
/*! 
Funcion que devuelve true si una cosa esta vacia
\return retorno devuelve true si esta vacia
*/
bool TColaAVLCalendario::EsVacia()const
{
	if(primero==NULL && ultimo==NULL) return true;
	else return false;
}

//! Encolar
/*! 
Funcion que encola un tavlcalendario
\param avlcal con el puntero al arbol a encolar
\return retorno devuelve true si se ha podido encolar
*/
bool TColaAVLCalendario::Encolar(TAVLCalendario *avlcal)
{
	bool retorno=true;
	TElemColaAVLCalendario *aux;
	aux=new TElemColaAVLCalendario();
	aux->arbol=avlcal;
	if(!aux) retorno=false;
	else
	{
		if(primero==NULL)
		{
			primero=aux;
		}
		else
		{
			ultimo->sig=aux;
		}
		ultimo=aux;
	}
	return retorno;
}

//! 
//! Desencolar
/*! 
Funcion que desencola un tavlcalendario
\return retorno devuelve true si se ha podido desencolar
*/
bool TColaAVLCalendario::Desencolar()
{
	bool retorno=true;
	TElemColaAVLCalendario *aux;
	if(!EsVacia())
	{
		if(primero==ultimo)
		{
			delete primero;
			primero=NULL;
			ultimo=NULL;
		}
		else
		{
			aux=primero;
			primero=primero->sig;
			delete aux;
			aux=NULL;
		}
	}
	else retorno=false;
	return retorno;
}

///! Cabeza
/*! 
Funcion que devuelve el primer elemento de la cola
\return TAVLCalendario con el primer elemento de la cola
*/
TAVLCalendario* TColaAVLCalendario::Cabeza()const
{
	return primero->arbol;
}

///! Longitud
/*! 
Funcion que devuelve la longitud de la cola
\return retorno con la longitud de la cola
*/
int TColaAVLCalendario::Longitud()const
{
	TElemColaAVLCalendario *aux;
	int retorno=0;
	if(!EsVacia())
	{
		aux=primero;
		while(aux!=NULL)
		{
			retorno+=1;
			aux=aux->sig;
		}
	}
	return retorno;
}

//! Sobrecarga del operador salida
/*! 
Sobrecarga del operador salida
\param o tipo ostream
\param c tipo TColaAVLCalendario con el objeto
\return o devuelve un ostream
*/
ostream& operator<<(ostream &os,const TAVLCalendario &tavl) {
    os << tavl.Inorden();
    return os;
}

//! Constructor por defecto
/*! 
Constructor por defecto de la clase tnodoavl que pone el factor de equilibrio a 0
*/
TNodoAVL::TNodoAVL ():item(),iz(),de()
{
	fe=0;
}

//! Constructor de Copia
/*! 
Constructor de copia que crea un un nodo a partir de otro
\param c copia del objeto
*/
TNodoAVL::TNodoAVL (const TNodoAVL &c)
{	
	item=c.item;
	iz=c.iz;
	de=c.de;
	fe=c.fe;
}

//! Destructor de la clase
/*! 
Destructor que pone el fe a 0 y destruye el item y iz, de
*/
TNodoAVL::~TNodoAVL ()
{
	item.~TCalendario();
	iz.~TAVLCalendario();
	de.~TAVLCalendario();
	fe=0;
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\return *this el propio objeto
*/
TNodoAVL & TNodoAVL::operator=(const TNodoAVL &c)
{
	this->~TNodoAVL();
	item=c.item;
	iz=c.iz;
	de=c.de;
	fe=c.fe;
	return(*this);

}

//! InordenAux
/*! 
Funcion privada que devuelve el recorrido en Inorden
\param v variable de tipo tvector calendario con el calendario a recorrer
\param posicion variable de tipo entero con la posicion pasada por referencia
*/
void TAVLCalendario::InordenAux(TVectorCalendario & v, int & posicion)const
{
		if(raiz!=NULL)
		{
			if(raiz->iz.raiz!=NULL)
				raiz->iz.InordenAux(v,posicion);
			v[posicion]=raiz->item;
			posicion++;
			if(raiz->de.raiz!=NULL)
				raiz->de.InordenAux(v,posicion);
		}
}

//! PreordenAux
/*! 
Funcion privada que devuelve el recorrido en Preorden
\param v variable de tipo tvector calendario con el calendario a recorrer
\param posicion variable de tipo entero con la posicion pasada por referencia
*/
void TAVLCalendario::PreordenAux(TVectorCalendario & v, int & posicion)const
{
	if(raiz!=NULL)
	{
		v[posicion]=raiz->item;
		posicion++;
		if(raiz->iz.raiz!=NULL)
			raiz->iz.PreordenAux(v,posicion);
		if(raiz->de.raiz!=NULL)
			raiz->de.PreordenAux(v,posicion);
	}
}

//! PostordenAux
/*! 
Funcion privada que devuelve el recorrido en postorden
\param v variable de tipo tvector calendario con el calendario a recorrer
\param posicion variable de tipo entero con la posicion pasada por referencia
*/
void TAVLCalendario::PostordenAux(TVectorCalendario & v, int & posicion)const
{
	if(raiz!=NULL)
	{
		if(raiz->iz.raiz!=NULL)
			raiz->iz.PostordenAux(v,posicion);
		if(raiz->de.raiz!=NULL)
			raiz->de.PostordenAux(v,posicion);
		v[posicion]=raiz->item;
		posicion++;
	}
}
//! NivelesAux
/*! 
Funcion auxiliar para el recorrido en niveles
\param cola variable de tipo cola con la cola a encolar pasada por referencia
*/
void TAVLCalendario::NivelesAux(TColaAVLCalendario &cola)
{
	if(!EsVacio())
	{
		cola.Encolar(this);
	}
}
//! Copiar
/*! 
Funcion que copia un arbol entero que se le pasa
\param a con el tavlcalendario a copiar
\return bool devuelve true si se ha podido copiar
*/
void TAVLCalendario::Copiar(const TAVLCalendario &a) 
{
	if(!a.EsVacio())
	{
		TNodoAVL *aux;
		aux=new TNodoAVL();
		aux->item=a.raiz->item;
		aux->fe=a.raiz->fe;
		raiz=aux;
		(raiz->iz).Copiar(a.raiz->iz);
		(raiz->de).Copiar(a.raiz->de);
	}
	else raiz=NULL;
}

//! Constructor por defecto
/*! 
Constructor por defecto de la clase tavlcalendario que pone el puntero raiz a null
*/
TAVLCalendario::TAVLCalendario ()
{
	raiz=NULL;
}

//! Constructor de Copia
/*! 
Constructor de copia que crea un arbol avl a partir de otro
\param c copia del objeto
*/
TAVLCalendario::TAVLCalendario (const TAVLCalendario &c)
{
	Copiar(c);
}

//! Destructor de la clase
/*! 
Destructor que borra el arbol y pone el puntero raiz a null
*/
TAVLCalendario::~TAVLCalendario ()
{
	if(raiz!=NULL)
	{
		delete raiz;
		raiz=NULL;
	}
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\param c con el objeto a asignar
\return *this el propio objeto
*/
TAVLCalendario & TAVLCalendario::operator=(const TAVLCalendario &c) 
{
	this->~TAVLCalendario();
	if(c.raiz!=NULL)
	{
		Copiar(c);
	}
	return (*this);
}

//! Operador igualdad
/*! 
Sobrecarga del operador igualdad
\param c parametro de tipo tavlcalendario pasado por referencia  
\return bool devuelve true si son iguales
*/
bool TAVLCalendario::operator==(const TAVLCalendario &c) const
{
	bool retorno=false;
	if(raiz==NULL && c.raiz==NULL)
		retorno=true;
	else
		if(c.raiz!=NULL && raiz!=NULL)
			if(c.raiz->item==raiz->item && c.raiz->fe==raiz->fe && c.raiz->iz==raiz->iz && c.raiz->de==raiz->de)
				retorno=true;
	return retorno;
}

//! Operador desigualdad
/*! 
Sobrecarga del operador desigualdad
\param c parametro de tipo tavlcalendario pasado por referencia  
\return retorno devuelve true si son distintos
*/
bool TAVLCalendario::operator!=(const TAVLCalendario &c)const
{
	bool retorno=true;
	if(c==(*this))
		retorno=false;
	return retorno;
}

//! EsVacio
/*! 
Funcion que mira si un arbol esta vacio
\return retorno devuelve true si el arbol esta vacio
*/
bool TAVLCalendario::EsVacio()const
{
	bool retorno=true;
	if(raiz!=NULL)
		retorno=false;
	return retorno;
}

//! Insertar
/*! 
Funcion que inserta un elemento de tipo c en el arbol
\param c variable de tipo calendario el cual se va a insertar
\return retorno devuelve true si se ha podido insertar el elemento
*/
bool TAVLCalendario::Insertar(TCalendario &c)
{
	bool retorno=true;
	TNodoAVL *nodo, *A,*B,*C,*D,*E,*F;
	if(EsVacio())
	{
		nodo=new TNodoAVL();
		if(!nodo) retorno=false;
		nodo->item=c;
		nodo->fe=0;
		raiz=nodo;
	}
	else
	{
		if(c==raiz->item) retorno=false;
		else
		{
			if(c<raiz->item)
			{
				retorno=raiz->iz.Insertar(c);
			}
			else
			{
				if(c>raiz->item) retorno=raiz->de.Insertar(c);
			}
		}
	}
	raiz->fe=raiz->de.Altura()-raiz->iz.Altura();
	if(raiz->fe==-2)
	{
		if(raiz->iz.raiz->fe==-1)
		{
			D=raiz;
			B=D->iz.raiz;
			C=B->de.raiz;
			raiz=B;
			raiz->de.raiz=D;
			D->iz.raiz=C;
			D->fe=D->de.Altura()-D->iz.Altura();
		}
		else
			if(raiz->iz.raiz->fe==1)
			{
				F=raiz;
				B=raiz->iz.raiz;
				D=B->de.raiz;
				C=D->iz.raiz;
				E=D->de.raiz;
				raiz=D;
				raiz->iz.raiz=B;
				raiz->de.raiz=F;
				raiz->de.raiz->iz.raiz=E;
				raiz->iz.raiz->de.raiz=C;
				B->fe=B->de.Altura()-B->iz.Altura();
				D->fe=D->de.Altura()-D->iz.Altura();
			}
	}
	else
		if(raiz->fe==2)
		{
			if(raiz->de.raiz->fe==1)
			{
				D=raiz;
				B=D->de.raiz;
				C=B->iz.raiz;
				raiz=B;
				raiz->iz.raiz=D;
				D->de.raiz=C;
				D->fe=D->de.Altura()-D->iz.Altura();
			}
			else
				if(raiz->de.raiz->fe==-1)
				{
					F=raiz;
					B=raiz->de.raiz;
					D=B->iz.raiz;
					C=D->de.raiz;
					E=D->iz.raiz;
					raiz=D;
					raiz->de.raiz=B;
					raiz->iz.raiz=F;
					raiz->de.raiz->iz.raiz=C;
					raiz->iz.raiz->de.raiz=E;
					B->fe=B->de.Altura()-B->iz.Altura();
					D->fe=D->de.Altura()-D->iz.Altura();
				}
		}
	raiz->fe=raiz->de.Altura()-raiz->iz.Altura();
	return retorno;
}

//! Buscar
/*! 
Funcion que busca el elemento que se le pasa como parametro
\param c variable de tipo calendario el cual se va a buscar
\return retorno devuelve true si se ha encontrado el elemento buscado
*/
bool TAVLCalendario::Buscar(const TCalendario &c)
{
	bool retorno=false;
	if(!EsVacio())
	{
		if(raiz->item==c) retorno=true;
		else
		{
			retorno=raiz->iz.Buscar(c) || raiz->de.Buscar(c);
		}
	}
	return retorno;
}

//! Altura
/*! 
Funcion que devuleve la altura del arbol
\return retorno variable de tipo entero con la altura del arbol
*/
int TAVLCalendario::Altura()const
{
	int retorno=0, a1, a2;
	if(!EsVacio())
	{
		a1=raiz->iz.Altura();
		a2=raiz->de.Altura();
		if (a1<a2)retorno=1+a2;
		else retorno=a1+1;
	}
	return retorno;
}
//! Nodos
/*! 
Funcion que devuleve el numero de nodos del arbol
\return retorno variable de tipo entero con el numero de nodos del arbol
*/
int TAVLCalendario::Nodos()const
{
	int retorno=0, n1,n2;
	if(!EsVacio())
	{
		n1=(raiz->iz).Nodos();
		n2=(raiz->de).Nodos();
		retorno=1+n1+n2;
	}
	return(retorno);
}

//! NodosHoja
/*! 
Funcion que devuleve los nodos hoja del arbol
\return retorno variable de tipo entero con el numero de nodos hoja del arbol
*/
int TAVLCalendario::NodosHoja()const
{
	int retorno=0,n1,n2;
	if(!EsVacio())
	{
		if(((raiz->iz).EsVacio()) && ((raiz->de).EsVacio()))
		{
			retorno+=1;
		}
		else
			retorno+=(raiz->iz).NodosHoja()+(raiz->de).NodosHoja();
	}
	return(retorno);
}

//! Inorden
/*! 
Funcion que devuelve el recorrido en Inorden
\return v con el tvectorcalendario con el recorrido
*/
TVectorCalendario TAVLCalendario::Inorden()const
{
	int posicion=1;
	TVectorCalendario v(this->Nodos());
	InordenAux(v,posicion);
	return v;
}

//! Preorden
/*! 
Funcion que devuelve el recorrido en Preorden
\return v con el tvectorcalendario con el recorrido
*/
TVectorCalendario TAVLCalendario::Preorden()const
{
	int posicion=1;
	TVectorCalendario v(this->Nodos());
	PreordenAux(v,posicion);
	return v;
}

//! Postorden
/*! 
Funcion que devuelve el recorrido en Postorden
\return v con el tvectorcalendario con el recorrido
*/
TVectorCalendario TAVLCalendario:: Postorden()const
{
	int posicion=1;
	TVectorCalendario v(this->Nodos());
	PostordenAux(v,posicion);
	return v;
}

//! Borrar
/*! 
Funcion que borra un elemento de tipo c del arbol
\param c variable de tipo calendario el cual se va a borrar
\return retorno devuelve true si se ha podido encontrar el elemento a borrar
*/
bool TAVLCalendario::Borrar(const TCalendario &c)
{
	bool retorno=true;
	TNodoAVL *aux=raiz,*A,*B,*C,*D,*E,*F;
	TNodoAVL *aux1;
	TCalendario e;
	if(EsVacio() || !Buscar(c)) retorno=false;
	else
	{
		if(aux->item==c)
		{
			if(aux->EsHoja())
			{
				delete aux;
				aux=NULL;
				raiz=NULL;
			}
			else
			{
				e=aux->item;
				aux1=MayorIzda();
				aux->item=aux1->item;
				aux1->item=e;
				delete aux1;
				aux1=NULL;
			}	
		}
		else
		{
			if(aux->item>c) retorno=aux->iz.Borrar(c);
			else retorno=aux->de.Borrar(c);
		}
		if(aux!=NULL)
		{
			if(aux->de.raiz!=NULL && aux->de.raiz->item.EsVacio()) aux->de.raiz=NULL;
			if(aux->iz.raiz!=NULL && aux->iz.raiz->item.EsVacio()) aux->iz.raiz=NULL;
			aux->fe=aux->de.Altura()-aux->iz.Altura();
			if(raiz->fe==-2)
			{
				if(raiz->iz.raiz->fe==-1 || raiz->iz.raiz->fe==0)
				{
					D=raiz;
					B=D->iz.raiz;
					C=B->de.raiz;
					raiz=B;
					raiz->de.raiz=D;
					D->iz.raiz=C;
					D->fe=D->de.Altura()-D->iz.Altura();
				}
				else
					if(raiz->iz.raiz->fe==1)
					{
						F=raiz;
						B=raiz->iz.raiz;
						D=B->de.raiz;
						C=D->iz.raiz;
						E=D->de.raiz;
						raiz=D;
						raiz->iz.raiz=B;
						raiz->de.raiz=F;
						raiz->de.raiz->iz.raiz=E;
						raiz->iz.raiz->de.raiz=C;
						B->fe=B->de.Altura()-B->iz.Altura();
						D->fe=D->de.Altura()-D->iz.Altura();
					}
			}
			else
				if(raiz->fe==2)
				{
					if(raiz->de.raiz->fe==1 || raiz->de.raiz->fe==0)
					{
						D=raiz;
						B=D->de.raiz;
						C=B->iz.raiz;
						raiz=B;
						raiz->iz.raiz=D;
						D->de.raiz=C;
						D->fe=D->de.Altura()-D->iz.Altura();
					}
					else
						if(raiz->de.raiz->fe==-1)
						{
							F=raiz;
							B=raiz->de.raiz;
							D=B->iz.raiz;
							C=D->de.raiz;
							E=D->iz.raiz;
							raiz=D;
							raiz->de.raiz=B;
							raiz->iz.raiz=F;
							raiz->de.raiz->iz.raiz=C;
							raiz->iz.raiz->de.raiz=E;
							B->fe=B->de.Altura()-B->iz.Altura();
							D->fe=D->de.Altura()-D->iz.Altura();
						}
				}
			raiz->fe=raiz->de.Altura()-raiz->iz.Altura();
		}
	}
	return retorno;}

//! MayorIzda
/*! 
Funcion que devuleve el mayor de la izquierda
\return aux1 variable con el nodo mayor de la izquierda
*/
TNodoAVL * TAVLCalendario::MayorIzda() const
{
	TNodoAVL * aux1;
	if (raiz->iz.raiz == NULL) aux1=raiz->de.raiz;
	else aux1=raiz->iz.raiz;
	while(!aux1->de.EsVacio())
	{
		aux1=aux1->de.raiz;
	}
	return(aux1);
}

//! Raiz
/*! 
Funcion que devuleve la raiz del arbol
\return tcalendario con el elemento raiz
*/
TCalendario TAVLCalendario::Raiz()const
{
	return (raiz->item);
}

//! Niveles
/*! 
Funcion que devuelve el recorrido por niveles
\return i con el tvectorcalendario con el recorrido
*/
TVectorCalendario TAVLCalendario::Niveles()
{
	TColaAVLCalendario cola;
	int posicion=1;
	TVectorCalendario retorno(Nodos());
	if(!EsVacio())
	{
		cola.Encolar(this);
		while(!cola.EsVacia())
		{
			if(!cola.Cabeza()->raiz->iz.EsVacio()) cola.Cabeza()->raiz->iz.NivelesAux(cola);
			if(!cola.Cabeza()->raiz->de.EsVacio()) cola.Cabeza()->raiz->de.NivelesAux(cola);
			retorno[posicion]=cola.Cabeza()->Raiz();
			posicion++;
			cola.Desencolar();
		}
	}
	return retorno;
}

//! EsHoja
/*! 
Funcion privada eshoja que dice si un nodo es hoja
\return bool devuelve true si es hoja
*/
bool TNodoAVL::EsHoja()const
{
	if(iz.EsVacio() && de.EsVacio())
		return true;
	else
		return false;
}

