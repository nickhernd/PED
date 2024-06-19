#include "tvectorcalendario.h"


//! Constructor por defecto
/*! 
Constructor por defecto de la clase tvectorcalendario que pone el tamano a 0 y el puntero a calendario c a null
*/
TVectorCalendario::TVectorCalendario()
{
	tamano=0;
	c=NULL;
}

//! Constructor por defecto sobrecargado
/*! 
Constructor por defecto con parametros
\param tam variable de tipo entero con el tamano
*/
TVectorCalendario::TVectorCalendario(int tam)
{
	if(tam>0)
	{
		c= new TCalendario[tam];
		tamano=tam;
	}
	else
	{
		c=NULL;
		tamano=0;
	}
}

//! Constructor de Copia
/*! 
Constructor de copia que crea un vector a partir de otro
\param co copia del objeto
*/
TVectorCalendario::TVectorCalendario(const TVectorCalendario &co)
{
	if (co.c!=NULL)
	{
		c=new TCalendario[co.tamano];
		tamano=co.tamano;
		for (int i=0;i<co.tamano;i++)
			c[i]=co.c[i];
	}
	else
	{
		c=NULL;
		tamano=0;
	}
}

//! Destructor de la clase
/*! 
Destructor que pone el tamano a 0 y el puntero c a null
*/
TVectorCalendario::~TVectorCalendario()
{
	if (c!=NULL)
	{
		tamano=0;
		delete [] c;
		c=NULL;
	}
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\return *this el propio objeto
*/
TVectorCalendario & TVectorCalendario::operator=(const TVectorCalendario &co)
{
	if(this!=&co){
		this->~TVectorCalendario();
		if (co.tamano>0)
		{
			tamano=co.tamano;
			c=new TCalendario [co.tamano];
			for(int i=0;i<co.tamano;i++)
				c[i]=co.c[i];
		}
	}
	return *this;
}

//! Operador igualdad
/*! 
Sobrecarga del operador igualdad
\param co parametro de tipo tvectorcalendario pasado por referencia  
\return bool devuelve true si son iguales
*/
bool TVectorCalendario::operator==(const TVectorCalendario &co)
{
	bool retorno=true;
	if(tamano==co.tamano)
	{
		if(co.c!=NULL && c==NULL) retorno=false;
		else 
			if(co.c==NULL && c!=NULL) retorno=false;
			else
				if(co.c!=NULL && c!=NULL)
				{
					for(int i=0;i<tamano;i++)
					{
						if(!(c[i]==co.c[i]))
						retorno=false;
			
					}
				}
	}
	else
		retorno=false;
	return retorno;
}

//! Operador desigualdad
/*! 
Sobrecarga del operador desigualdad
\param co parametro de tipo tvectorcalendario pasado por referencia  
\return bool devuelve true si son distintos
*/
bool TVectorCalendario::operator!=(const TVectorCalendario &co)
{
	bool retorno=false;
	if(tamano==co.tamano)
	{
		if(co.c!=NULL && c==NULL) retorno=true;
		else 
			if(co.c==NULL && c!=NULL) retorno=true;
			else
				if(co.c!=NULL && c!=NULL)
				{
					for(int i=0;i<tamano;i++)
					{
						if(!(c[i]==co.c[i]))
						retorno=true;
			
					}
				}
	}
	else
		retorno=true;
	return retorno;

}

//! Operador Corchetes izquierda
/*! 
Sobrecarga del operador corchetes por la izquierda
\param i parametro de tipo entero con la posicion del elemento que se debe devolver
\return TCalendario devuelve el calendario que se pide, si no existe esa posicion se devuelve un tipo tcalendario error
*/
TCalendario & TVectorCalendario::operator[](int i) 
{
	if(i<=tamano && i>0)
		return c[i-1];
	else
	{
		return error;
	}
}

//! Operador Corchetes derecha
/*! 
Sobrecarga del operador corchetes por la derecha
\param i parametro de tipo entero con la posicion del elemento que se debe devolver
\return TCalendario devuelve el calendario que se pide, si no existe esa posicion se devuelve un tipo tcalendario error
*/
TCalendario TVectorCalendario::operator[](int i) const
{
	TCalendario a;
	if(i<=tamano && i>0)
		return c[i-1];
	else
	{
		return a;
	}

}

///! Tamano
/*! 
Funcion que devuelve el tamano del vector
\return tamano con las posiciones
*/
int TVectorCalendario::Tamano()const
{
	return tamano;
}

///! Ocupadas
/*! 
Funcion que devuelve el numero de posiciones ocupadas del vector
\return int con las posiciones que estan ocupadas
*/
int TVectorCalendario::Ocupadas()const
{
	int j=0;
	if(c!=NULL)
	{
		for(int i=0; i<tamano; i++)
		{
			if(c[i].EsVacio()==false)
				j++;
		}
	}
	return j;

}

///! ExisteCal
/*! 
Funcion que busca si existe el calendario que se le pasa como parametro
\param ca el elemento a buscar
\return bool devuelve true si el elemento existe en el vector sino devuelve false
*/
bool TVectorCalendario::ExisteCal(const TCalendario &ca)
{
	bool retorno=false;
	if(c!=NULL)
	{
		for(int i=0; i<tamano; i++)
		{
			if(c[i]==ca)
			{
				retorno=true;
			}
		}
	}
	return retorno;
}

///! MostrarMensajes
/*! 
Funcion que muestra los mensajes de igual fecha o posterior a la pasada como parametro
\param dia variable de tipo entero con el dia
\param mes variable de tipo entero con el mes
\param anyo variable de tipo entero con el anyo
*/
void TVectorCalendario::MostrarMensajes(int d,int m,int a)
{
	if(c!=NULL)
	{
		cout<<"[";
		for(int i=0; i<tamano; i++)
		{
			if(c[i].Mensaje()!=NULL)
			{
				if(a<c[i].Anyo())
				{
					cout<<c[i];
					if(i!=tamano-1) cout<<",";
				}
				else
				{ 
					if(a==c[i].Anyo())
					{
						if(m<c[i].Mes())
						{
							cout<<c[i];
							if(i!=tamano-1) cout<<",";
						}
						else
						{
							if(m==c[i].Mes())
								if(d<=c[i].Dia())
								{
									cout<<c[i];
									if(i!=tamano-1) cout<<",";
								}
						}
					}
				}
			}
		}
		cout<<"]";
	}
}

///! Redimensionar
/*! 
Funcion que redimensiona un vector
\param dim con la nueva dimension
\return retorno con verdadero o falso
*/
bool TVectorCalendario::Redimensionar(int dim)
{
	bool retorno;
	TCalendario *copia;
	TCalendario copia2;
	int tamant, i;
	if(dim<=0 || dim == tamano)
	{
		retorno=false;
	}
	else
	{
		if(dim > tamano)
		{
			copia=new TCalendario [tamano];
			for(i=0;i<tamano;i++)
				copia[i]=c[i];
			tamant = tamano;
			tamano = dim;
			c= new TCalendario [tamano];
			i=0;
			for(int j=0;j<tamant;j++)
			{
				c[j]=copia[i];
				i++;
			}
			for(int k=tamant; k<tamano;k++)
			{
				c[k]=copia2;
			}
			retorno=true;
		}
		else
		{
			copia=new TCalendario [tamano];
			//for(i=0;i<dim;i++)
			//copia[i]=c[i];
			for(int l=0; l<dim; l++)
			{
				copia[l]=c[l];
			}
			delete [] c;
			c=NULL;
			tamano = dim;
			c= new TCalendario [tamano];
			for(int m=0; m<dim; m++)
			{
				c[m]=copia[m];
			}
			retorno=true;
		}
	}
	return retorno;
}

//! Sobrecarga del operador salida
/*! 
Sobrecarga del operador salida
\param o tipo ostream
\param co tipo vector con el objeto
\return o devuelve un ostream
*/
ostream & operator<<(ostream &o, const TVectorCalendario &co)
{
	if(co.c!=NULL)
	{
		if(co.Tamano()==0)
			o<<"[]";
		else
		{
			o<<"[";
			for(int i=0; i<co.Tamano(); i++)
			{
				o<<"("<<i+1<<") "<<co.c[i];
				if(i!=co.Tamano()-1)
					o<<", ";
			}
			o<<"]";
		}
	}
	else
		o<<"[]";
	return o;
}
