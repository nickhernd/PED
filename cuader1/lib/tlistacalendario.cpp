#include "tlistacalendario.h"

//! Constructor por defecto
/*! 
Constructor por defecto de la clase nodo utilizando layering
*/
TNodoCalendario::TNodoCalendario():c()
{
	siguiente=NULL;
}

//! Constructor de copia
/*! 
Constructor de copia que crea un nodo a partir de otro
\param n copia del objeto
*/
TNodoCalendario::TNodoCalendario(const TNodoCalendario &n)
{
	siguiente=n.siguiente;
	c=n.c;
}

//! Destructor de la clase
/*! 
Destructor de la clase nodo que apunta el puntero siguiente a null y destruye el calendario llamando al destructor de calendario
*/
TNodoCalendario::~TNodoCalendario()
{
	siguiente=NULL;
	c.~TCalendario();
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\return *this el propio objeto
*/
TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &n)
{
	c=n.c;
	siguiente=n.siguiente;
	return(*this);
}


//! Constructor por defecto
/*! 
Constructor por defecto de la clase TListaPos que pone la pos a null
*/
TListaPos::TListaPos()
{
	pos=NULL;
}

//! Constructor de copia
/*! 
Constructor de copia que crea una posicion a partir de otra
\param p copia del objeto
*/
TListaPos::TListaPos(const TListaPos &p)
{
	pos=p.pos;
}

//! Destructor de la clase
/*! 
Destructor de la clase tlistapos que apunta el puntero pos a null
*/
TListaPos::~TListaPos()
{
	pos=NULL;
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\return *this el propio objeto
*/
TListaPos & TListaPos::operator=(const TListaPos &p)
{
	pos=p.pos;
	return(*this);
}

//! Operador igualdad
/*! 
Sobrecarga del operador igualdad
\param p parametro de tipo tlistapos pasado por referencia  
\return bool devuelve true si son iguales
*/
bool TListaPos::operator==(const TListaPos &p)const
{
	bool retorno=false;
	if(pos==p.pos) retorno=true;
	return retorno;
}

//! Operador desigualdad
/*! 
Sobrecarga del operador desigualdad
\param p parametro de tipo tlistapos pasado por referencia  
\return bool devuelve true si son desiguales
*/
bool TListaPos::operator!=(const TListaPos &p)const
{
	bool retorno=false;
	if(pos!=p.pos) retorno=true;
	return retorno;
}


//! Siguiente
/*! 
Funcion que devuelve la posicion siguiente
\return po devuelve la posicion
*/
TListaPos TListaPos::Siguiente()
{
	TListaPos po;
	if(pos->siguiente!=NULL) po.pos=pos->siguiente;
	return po;
}

//! EsVacia
/*! 
Comprueba si la posicion esta vacia
\return bool devuelve true si la posicion no apunta a un elemento de la lista o el puntero interno pos es null
*/
bool TListaPos::EsVacia() const
{
	bool retorno=false;
	if(pos==NULL) retorno=true;
	return retorno;
}


//! Constructor por defecto
/*! 
Constructor por defecto de la clase TListaCalendario que pone primero a null
*/
TListaCalendario::TListaCalendario()
{
	primero=NULL;
}

//! Constructor de copia
/*! 
Constructor de copia que crea una lista a partir de otra
\param l copia del objeto
*/
TListaCalendario::TListaCalendario(const TListaCalendario &l)
{
	TListaPos aux;
	TCalendario ca;
	primero = NULL;
	if(!l.EsVacia())
	{
		aux=l.Primera();
		while(!aux.EsVacia())
		{
			ca=aux.pos->c;
			this->Insertar(ca);
			aux=aux.Siguiente();
		}
	}
}

//! Destructor de la clase
/*! 
Destructor de la clase tlistacalendario que elimina la lista y sus nodos y apunta primero a null
*/
TListaCalendario::~TListaCalendario()
{
	if(!EsVacia())
	{
		TListaPos aux, aux1;
		aux=Primera();
		while(aux.pos->siguiente!=NULL)
		{
			aux1=aux;
			aux=aux.Siguiente();
			delete aux1.pos;
			aux1.pos=NULL;
		
		}
		delete aux.pos;
		if(primero!=NULL) primero=NULL;
	}
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\return *this el propio objeto
*/
TListaCalendario & TListaCalendario::operator=(const TListaCalendario &l)
{
	TListaPos aux;
	if(!EsVacia()) this->~TListaCalendario();
	if(!l.EsVacia())
	{
		aux=l.Primera();
		while(!aux.EsVacia())
		{
			Insertar(aux.pos->c);
			aux=aux.Siguiente();
		}
	}
	return (*this);
}

//! Operador de igualdad
/*! 
Sobrecarga del operador igualdad
\return bool con el resultado de si la lista es o no igual.
*/
bool TListaCalendario::operator==(const TListaCalendario &l)
{
	bool iguales = true;
	TListaPos aux, aux1;
	if(Longitud()!=l.Longitud())
	{
		 iguales = false;
	}
	else
	{
		aux=Primera();
		aux1=l.Primera();
		while(!aux.EsVacia() && (!aux1.EsVacia()) && (iguales))
		{
			if(aux.pos->c!=aux1.pos->c) 
			{
				iguales=false;
			}
			aux=aux.Siguiente();
			aux1=aux1.Siguiente();
		}
	}
	return(iguales);
}

//! Operador suma
/*! 
Sobrecarga del operador suma de los listas
\param l la lista que has que sumar a la propia
\return aux la lista completa despues de la suma
*/
TListaCalendario TListaCalendario::operator+(const TListaCalendario &l)
{
	TListaCalendario aux;
	TListaPos auxp;
	auxp=Primera();
	while(!auxp.EsVacia())
	{
		aux.Insertar(auxp.pos->c);
		auxp=auxp.Siguiente();
	}
	auxp=l.Primera();
	while(!auxp.EsVacia())
	{
		aux.Insertar(auxp.pos->c);
		auxp=auxp.Siguiente();
	}
	return (aux);
}


//! Operador resta
/*! 
Sobrecarga del operador resta de una lista
\param l lista que hay que restar
\return aux la lista definitiva despues de la resta
*/
TListaCalendario TListaCalendario::operator-(const TListaCalendario &l)
{
	TListaCalendario aux;
	TListaPos auxp, auxp1;
	auxp=Primera();
	bool encontrado=false;
	while(!auxp.EsVacia())
	{
		auxp1=l.Primera();
		encontrado=false;
		while(!auxp1.EsVacia() && !encontrado)
		{
			if(auxp.pos->c==auxp1.pos->c)
			{
				encontrado=true;
			}
			else auxp1=auxp1.Siguiente();
		}
		if(!encontrado)
		{
			aux.Insertar(auxp.pos->c);
		}
		auxp=auxp.Siguiente();
	}
	return (aux);
}

//! Insertar
/*! 
Funcion que inserta un calendario en la lista
\param ca variable con el calendario
\return bool si se ha podido insertar y no esta repetido se devuelve true
*/
bool TListaCalendario::Insertar(const TCalendario &ca)
{
    TNodoCalendario *nuevo = new TNodoCalendario();
    if (!nuevo) return false;

    nuevo->c = ca;
    nuevo->siguiente = nullptr;

    if (EsVacia() || ca < primero->c) {
        nuevo->siguiente = primero;
        primero = nuevo;
        return true;
    }

    TNodoCalendario *actual = primero;
    while (actual->siguiente && actual->siguiente->c < ca) {
        actual = actual->siguiente;
    }

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
    return true;
}

//! Borrar calendario
/*! 
Funcion que borra un calendario de la lista
\param ca variable con el calendario
\return bool si se ha podido borrar y se encuentra en la lista se devuelve true
*/
bool TListaCalendario::Borrar(const TCalendario &ca)
{
	bool retorno=false, encontrado=false;
	TListaPos auxp;
	if(!EsVacia())
	{
		auxp=Primera();
		while (!auxp.EsVacia() && !encontrado)
		{
			if(auxp.pos->c==ca)
			{
				encontrado=true;
				retorno=Borrar(auxp);
			}
			else auxp=auxp.Siguiente();
		}
	}
	return(retorno);
}

//! Borrar posicion
/*! 
Funcion que borra una posicion que estaba ocupada de la lista
\param p posicon de la lista
\return bool si la posicion existe y se ha podido borrar se devuelve true
*/
bool TListaCalendario::Borrar(const TListaPos &p)
{
	bool retorno=false,borrado=false;
	TListaPos auxp,auxp1;
	auxp=Primera();
	if(p==Primera())
	{
		if(p==Ultima())
		{
			primero=NULL;
			delete auxp.pos;
			auxp.pos=NULL;
			retorno=true;
		}
		else
		{
			primero=auxp.pos->siguiente;
			delete auxp.pos;
			auxp.pos=NULL;
			retorno=true;
		}
	}
	else
	{
		auxp1=auxp.Siguiente();
		while(borrado==false && !auxp1.EsVacia())
		{
			if(p==auxp1)
			{
				if(auxp1==Ultima())
				{
					auxp.pos->siguiente=NULL;
					delete auxp1.pos;
					auxp1.pos=NULL;
					borrado=true;
					retorno=true;
				}
				else
				{
					auxp.pos->siguiente=auxp1.pos->siguiente;
					delete auxp1.pos;
					auxp1.pos=NULL;
					borrado=true;
					retorno=true;
				}
			}
			else
			{
				auxp=auxp.Siguiente();
				auxp1=auxp1.Siguiente();
			}
		}
	}
	return (retorno);
}

//! Borrar anteriores
/*! 
Funcion que borra los nodos que tienen fecha anterior a la pasada como parametro
\param d dia de un calendario
\param m mes de un calendario
\param a anyo de un calendario
\return bool si se ha podido borrar los nodos se devuelve true
*/
bool TListaCalendario::Borrar(int d,int m,int a)
{
	bool retorno=false;
	TCalendario ca(d,m,a,""); 
	TListaPos auxp, auxp1;
	if(!EsVacia())
	{
		auxp=Primera();
		auxp1=auxp;
		while (!auxp1.EsVacia())
		{
			if(auxp.pos->c<ca)
			{
				auxp1=auxp.Siguiente();
				retorno=Borrar(auxp);
				auxp=auxp1;
			}
			else
			{
				auxp=auxp.Siguiente();
				auxp1=auxp;
			}
		}
	}
	return(retorno);
}

//! EsVacia
/*! 
Comprueba si la lista esta vacia
\return bool devuelve true si el puntero primero apunta a null
*/
bool TListaCalendario::EsVacia() const
{
	bool retorno=false;
	if (primero==NULL) retorno=true;
	return (retorno);
}

//! Obtener
/*! 
Obtiene el elemento que se encuentra en la posicion que se le introduce como parametro
\param p con la posicion
\return TCalendario devuelve el elemento de tipo calendario que se encuentra en esa posicion
*/
TCalendario TListaCalendario::Obtener(const TListaPos &p) const
{
	bool encontrado=false;
	TListaPos auxp;
	if (!EsVacia())
	{
		auxp=Primera();
		while (!auxp.EsVacia() && !encontrado)
		{
			if(auxp==p)
			{
				encontrado=true;
				TCalendario *ca = new TCalendario(p.pos->c);
				return(*ca);
			}
			else auxp=auxp.Siguiente();
		}
		if(!encontrado)
		{
			TCalendario *ca = new TCalendario();
			return *ca;
		}
	}
}

//! Buscar
/*! 
Busca el elemento que se le introduce como parametro
\param ca con el elemento de tipo calendario a buscar
\return bool devuelve true si ha encontrado el elemento
*/
bool TListaCalendario::Buscar(const TCalendario &ca)
{
	TListaPos auxp;
	bool encontrado=false;
	auxp=Primera();
	while(!auxp.EsVacia() && !encontrado)
	{
		if(auxp.pos->c==ca)
		{
			encontrado=true;
		}
		else auxp=auxp.Siguiente();
	}
	return (encontrado);
}

//! Longitud
/*! 
Devuelve la longitud de la lista
\return retorno con el numero de elementos en la lista
*/
int TListaCalendario::Longitud() const
{
	int retorno=0;
	TListaPos auxp;
	auxp=Primera();
	while(!auxp.EsVacia())
	{
		retorno+=1;
		auxp=auxp.Siguiente();
	}
	return retorno;
	
}

//! Primera
/*! 
Devuelve la primera posicion de la lista
\return retorno con la direccion de la posicion
*/
TListaPos TListaCalendario::Primera() const
{
	TListaPos *retorno;
	retorno = new TListaPos();
	if(!EsVacia())
	{
		retorno->pos=primero;
	}
	return (*retorno);
}

//! Ultima
/*! 
Devuelve la ultima posicion de la lista
\return retorno con la direccion de la posicion
*/
TListaPos TListaCalendario::Ultima() const
{
	TListaPos auxp,auxp1;
	auxp1=Primera();
	if(!auxp1.EsVacia())
	{
		auxp=auxp1.Siguiente();
		while(!auxp.EsVacia())
		{
			auxp1=auxp1.Siguiente();
			auxp=auxp.Siguiente();
		}
	}
	return (auxp1);
}

//! SumarSubl
/*! 
Suma dos sublistas
\param I_L1 con el indice 1 de la lista propia
\param F_L1 con el indice 2 de la lista propia
\param I_L2 con el indice 1 de la lista L2
\param F_L2 con el indice 2 de la lista L2
\param L2 con la lista pasada como parametro
\return laux con las sublistas sumadas
*/
TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario& L2, int I_L2, int F_L2)
{
	TListaCalendario laux;
	TListaPos paux, paux1;
	int i1=I_L1, f1=F_L1, i2=I_L2, f2=F_L2, cont, cont2;
	
	if(I_L1 < 1) i1=1;
	if(I_L2 < 1) i2=1;
	if(F_L1 > Longitud()) f1=Longitud();
	if(F_L2 > L2.Longitud()) f2=L2.Longitud();

	paux=Primera();
	paux1=L2.Primera();
	cont=1;
	while(cont < i1)
	{
		paux=paux.Siguiente();
		cont++;
	}
	cont2=1;
	while(cont2 < i2)
	{
		paux1=paux1.Siguiente();
		cont2++;
	}

	while(cont <= f1)
	{
		laux.Insertar(paux.pos->c);
		paux=paux.Siguiente();
		cont++;
	}

	while(cont2 <= f2)
	{
		laux.Insertar(paux1.pos->c);
		paux1=paux1.Siguiente();
		cont2++;
	}
	
	return (laux);
}


//! ExtraerRango
/*! 
Extrae un rango de nodos de la lista
\param n1 con el indice 1
\param n2 con el indice 2
\return laux con el rango extraido
*/
TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2)
{
	TListaCalendario laux;
	TListaPos paux, paux1;
	int auxn1=n1, auxn2=n2, cont;
	
	paux=Primera();
	if(n1 < 1) auxn1=1;
	if(n2 > Longitud()) auxn2=Longitud();
	if(auxn1==auxn2 || auxn1<auxn2)
	{
		cont=1;
		while(cont < auxn1)
		{
			paux=paux.Siguiente();
			cont++;
		}	
		while(cont <= auxn2)
		{
			laux.Insertar(paux.pos->c);
			paux=paux.Siguiente();
			cont++;
		}
		paux1=laux.Primera();	
		while(!paux1.EsVacia())
		{
			Borrar(paux1.pos->c);
			paux1=paux1.Siguiente();
			cont++;
		}
	}
	return(laux);
}



//! Sobrecarga del operador salida
/*! 
Sobrecarga del operador salida
\param o tipo ostream
\param l tipo lista con el objeto
\return o devuelve un ostream
*/
ostream & operator<<(ostream &o, const TListaCalendario &l)
{
	TListaPos auxp, auxpt;
	TCalendario ca;
	if(l.EsVacia())
	{
		o<<"<>";
	}
	else
	{
		auxp=l.Primera();
		o<<"<";
		while(!auxp.EsVacia())
		{
			ca=l.Obtener(auxp);
			o<<ca;
			auxp=auxp.Siguiente();
			auxpt=auxp;
			if(!auxpt.EsVacia()) o<<" "; 
		}
		
		o<<">";
	}
	return o;
}
