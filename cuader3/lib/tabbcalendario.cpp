#include "tabbcalendario.h"
#include <queue>

//! Constructor por defecto
/*! 
Constructor por defecto de la clase tnodo que utiliza las funciones item, iz y de
*/
TNodoABB::TNodoABB():item(),iz(),de(){}

//! Constructor de Copia
/*! 
Constructor de copia que crea un nodo abb a partir de otro
\param c copia del objeto
*/
TNodoABB::TNodoABB(const TNodoABB &c)
{
	item=c.item;
	iz=c.iz;
	de=c.de;
}

//! Destructor de la clase
/*! 
Destructor que destrulle item, iz y de llamando a sus respectivos destructores
*/
TNodoABB::~TNodoABB ()
{
	item.~TCalendario();
	iz.~TABBCalendario();
	de.~TABBCalendario();
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\param c con el objeto a asignar
\return *this el propio objeto
*/
TNodoABB & TNodoABB::operator=(const TNodoABB &c)
{
	this->~TNodoABB();
	item=c.item;
	iz=c.iz;
	de=c.de;
	return(*this);
}

//! EsHoja
/*! 
Funcion que dice si un nodo es hoja
\return bool devuelve true si es nodo hoja
*/
bool TNodoABB::EsHoja()
{
	if (iz.EsVacio() && de.EsVacio())
		return true;
	else
		return false;
}


//! InordenAux
/*! 
Funcion privada que devuelve el recorrido en inorden
\param ve variable de tipo tvector calendario con el calendario a recorrer
\param posicion variable de tipo entero con la posicion pasada por referencia
*/
void TABBCalendario::InordenAux(TVectorCalendario &ve, int &posicion)const
{
	if(!EsVacio())
	{
	if(raiz->iz.raiz!=NULL)
		raiz->iz.InordenAux(ve,posicion);
	ve[posicion]=raiz->item;
	posicion++;
	if(raiz->de.raiz!=NULL)
		raiz->de.InordenAux(ve,posicion);
	}
}

//! PreordenAux
/*! 
Funcion privada que devuelve el recorrido en preorden
\param ve variable de tipo tvector calendario con el calendario a recorrer
\param posicion variable de tipo entero con la posicion pasada por referencia
*/
void TABBCalendario::PreordenAux(TVectorCalendario &ve, int &posicion)const
{
	if(raiz!=NULL)
	{
		ve[posicion]=raiz->item;
		posicion++;
		if(raiz->iz.raiz!=NULL)
			raiz->iz.PreordenAux(ve,posicion);
		if(raiz->de.raiz!=NULL)
			raiz->de.PreordenAux(ve,posicion);
	}
}

//! PostordenAux
/*! 
Funcion privada que devuelve el recorrido en postorden
\param ve variable de tipo tvector calendario con el calendario a recorrer
\param posicion variable de tipo entero con la posicion pasada por referencia
*/
void TABBCalendario::PostordenAux(TVectorCalendario &ve, int &posicion)const
{
	if(raiz!=NULL)
	{
		if(raiz->iz.raiz!=NULL)
			raiz->iz.PostordenAux(ve,posicion);
		if(raiz->de.raiz!=NULL)
			raiz->de.PostordenAux(ve,posicion);
		ve[posicion]=raiz->item;
		posicion++;
	}
}

//! CopiarArbol
/*! 
Funcion que copia un arbol entero que se le pasa
\param c con el tabbcalendario a copiar
\return bool devuelve true si se ha podido copiar
*/
void TABBCalendario::CopiarArbol(const TABBCalendario &c)
{
	if(!c.EsVacio())
			{
				TNodoABB *aux;
				aux=new TNodoABB();
				aux->item=c.raiz->item;
				raiz=aux;
				(raiz->iz).CopiarArbol(c.raiz->iz);
				(raiz->de).CopiarArbol(c.raiz->de);
			}
			else raiz=NULL;
}

//! MayorIzda
/*! 
Funcion que devuleve el mayor de la izquierda
\return aux1 variable con el nodo mayor de la izquierda
*/
TNodoABB * TABBCalendario::MayorIzda()
{
	TNodoABB * aux1;
	if (raiz->iz.raiz == NULL) aux1=raiz->de.raiz;
	else aux1=raiz->iz.raiz;
	while(!aux1->de.EsVacio())
	{
		aux1=aux1->de.raiz;
	}
	return(aux1);
}

//! Constructor por defecto
/*! 
Constructor por defecto de la clase tabbcalendario que pone el puntero raiz a null
*/
TABBCalendario::TABBCalendario ()
{
	raiz=NULL;
}

//! Constructor de Copia
/*! 
Constructor de copia que crea un arbol abb a partir de otro
\param c copia del objeto
*/
TABBCalendario::TABBCalendario (const TABBCalendario &c)
{
	CopiarArbol(c);
}

//! Destructor de la clase
/*! 
Destructor que borra el arbol y pone el puntero raiz a null
*/
TABBCalendario::~TABBCalendario ()
{
	if(!EsVacio())
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
TABBCalendario & TABBCalendario::operator=(const TABBCalendario &c)
{
	if(!EsVacio()) this->~TABBCalendario();
	CopiarArbol(c);
	return(*this);
}

//! Operador igualdad
/*! 
Sobrecarga del operador igualdad
\param c parametro de tipo tabbcalendario pasado por referencia  
\return bool devuelve true si son iguales
*/
bool TABBCalendario::operator==(TABBCalendario &c)
{
	return((Inorden()==c.Inorden())&&(Preorden()==c.Preorden()) &&(Postorden()==c.Postorden()));
}

//! EsVacio
/*! 
Funcion que mira si un arbol esta vacio
\return retorno devuelve true si el arbol esta vacio
*/
bool TABBCalendario::EsVacio() const
{
	if(raiz==NULL) return (true);
	else return(false);
}

//! Insertar
/*! 
Funcion que inserta un elemento de tipo c en el arbol
\param c variable de tipo calendario el cual se va a insertar
\return retorno devuelve true si se ha podido insertar el elemento
*/
bool TABBCalendario::Insertar(TCalendario &c)
{
	TNodoABB *nodo;
	bool retorno=true;
	if(EsVacio())
	{
		nodo=new TNodoABB();
		if(!nodo) retorno=false;
		nodo->item=c;
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
	return (retorno);
}

//! Borrar
/*! 
Funcion que borra un elemento de tipo c del arbol
\param c variable de tipo calendario el cual se va a borrar
\return retorno devuelve true si se ha podido encontrar el elemento a borrar
*/
bool TABBCalendario::Borrar(TCalendario &c)
{
	TNodoABB *aux=raiz, *aux1;
	TCalendario ca;
	bool retorno=true;
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
				ca=aux->item;
				aux1=MayorIzda();
				aux->item=aux1->item;
				aux1->item=ca;
				delete aux1;
				aux1=NULL;
			}
		}
		else
		{
			if(aux->item>c) retorno=aux->iz.Borrar(c);
			else retorno=aux->de.Borrar(c);
		}
	}
	return (retorno);
}

//! Buscar
/*! 
Funcion que busca el elemento que se le pasa como parametro
\param c variable de tipo calendario el cual se va a buscar
\return retorno devuelve true si se ha encontrado el elemento buscado
*/
bool TABBCalendario::Buscar(TCalendario &c)
{
	bool retorno=false;
	if(!EsVacio())
	{
		if(raiz->item==c) retorno=true;
		else
		{
			if(raiz->item>c) retorno=raiz->iz.Buscar(c);
			else retorno=raiz->de.Buscar(c);
		}
	}
	return retorno;
}

//! Raiz
/*! 
Funcion que devuleve la raiz del arbol
\return retorno de tipo tcalendario con el elemento raiz
*/
TCalendario TABBCalendario::Raiz()
{
	TCalendario retorno;
	if(raiz!=NULL) return raiz->item;
	else return (retorno);
}

//! Altura
/*! 
Funcion que devuleve la altura del arbol
\return retorno variable entera con la altura del arbol
*/
int TABBCalendario::Altura()const
{
	int retorno=0,a1,a2;
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
int TABBCalendario::Nodos()const
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
int TABBCalendario::NodosHoja()const
{
	int retorno=0;
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
TVectorCalendario TABBCalendario::Inorden()const
{
	int posicion=1;
	TVectorCalendario recorrido(Nodos());
	InordenAux(recorrido, posicion);
	return recorrido;
}

//! Preorden
/*! 
Funcion que devuelve el recorrido en Preorden
\return v con el tvectorcalendario con el recorrido
*/
TVectorCalendario TABBCalendario::Preorden()const
{
	int posicion = 1;
	TVectorCalendario recorrido(Nodos());
	PreordenAux(recorrido, posicion);
	return recorrido;
}

//! Postorden
/*! 
Funcion que devuelve el recorrido en Postorden
\return v con el tvectorcalendario con el recorrido
*/
TVectorCalendario TABBCalendario::Postorden()const
{
	int posicion = 1;
	TVectorCalendario recorrido(Nodos());
	PostordenAux(recorrido, posicion);
	return recorrido;
}

//! Operador suma
/*! 
Sobrecarga del operador suma
\param c variable de tipo tabbcalendario que hay que sumar
\return aux el arbol sumado
*/
TABBCalendario TABBCalendario::operator+( TABBCalendario &c)
{
	int i=1;
	TABBCalendario aux(*this);
	TVectorCalendario aux1;
	if(!c.EsVacio())
	{
		aux1=c.Inorden();
		while(i<=aux1.Tamano())
		{
			aux.Insertar(aux1[i]);
			i++;		
		}
	}
	return aux;
}

//! Operador resta
/*! 
Sobrecarga del operador resta
\param c variable de tipo tabbcalendario que hay que restar
\return *this el arbol restado
*/
TABBCalendario TABBCalendario::operator-( TABBCalendario &c)
{
	int i=1;
	TABBCalendario aux;
	TCalendario ca;
	TVectorCalendario aux1;
	if(!this->EsVacio())
	{
		if(!c.EsVacio())
		{
			aux1=this->Inorden();
			while(i<=aux1.Tamano())
			{
				ca=aux1[i];
				if(!c.Buscar(ca)) aux.Insertar(ca);
				i++;			
			}
			return aux;		
		}
		else return(*this);
	}
	else return c;
}


//! Funcion BuscarLista
/*! 
Funcion BuscarLista de la clase arbol BB
\param l variable de tipo lista con una lista
\return *int vector de enteros
*/
int* TABBCalendario::BuscarLista(TListaCalendario & l)
{
TVectorCalendario aux;
TCalendario auxc;
TListaPos auxp;
int tama = l.Longitud();
bool encontrado=false;
int *vec = new int[tama];
	auxp=l.Primera();
	if(!auxp.EsVacia())
	{
		//Y si quitamos Inorden()??
		aux=Inorden();
		for(int j=0; j<tama && !auxp.EsVacia(); j++)
		{
			auxc=l.Obtener(auxp);
			if(Buscar(auxc) == true)
			{
				for(int i=1; i<=aux.Tamano() && !encontrado; i++)
				{
					if(aux[i].Anyo()==l.Obtener(auxp).Anyo())
					{
						if(i!=1)
						{
							vec[j]=aux[i-1].Anyo();
							encontrado=true;
						}
						else
						{
							vec[j]=0;
							encontrado=true;	
						}
						
					}
				}
			encontrado=false;
			}
			else vec[j]=0;
			auxp=auxp.Siguiente();
		}
	}
	else vec=NULL;
return vec;
}

TVectorCalendario TABBCalendario::Niveles() const {
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

ostream& operator<<(ostream &os,const TABBCalendario &tabb) {
    os << tabb.Niveles();
    return os;
}