#include "tcalendario.h"
#include <cstring>

//! Constructor por defecto
/*! 
Constructor por defecto de la clase TCalendario
*/
TCalendario::TCalendario ()
{
	dia=1;
	mes=1;
	anyo=1900;
	mensaje=NULL;
}

//! Constructor por defecto sobrecargado
/*! 
Constructor por defecto con parametros
\param dia variable de tipo entero con el dia
\param mes variable de tipo entero con el mes
\param anyo variable de tipo entero con el anyo
*/
TCalendario::TCalendario(int dia, int mes, int anyo, char * mens)
{
	bool fechaCorrecta=true;
	bool bisiesto=(((anyo % 4 == 0) && (anyo % 100 != 0)) || (anyo % 400 == 0));
	if(dia<=0 || dia>31 || mes<0 || mes>12 || anyo<1900)
	{
		fechaCorrecta=false;
	}
	else
	{
		if(dia==29 && mes==2 && bisiesto==false) fechaCorrecta=false;
		if(dia>29 && mes==2) fechaCorrecta=false;
		if((dia>30) && ((mes==4) || (mes==6) || (mes==9) || (mes==11))) fechaCorrecta=false;
		if((dia>31) && ((mes==1) || (mes==3) || (mes==5) || (mes==7)|| (mes==8) || (mes==10) || (mes==12))) fechaCorrecta=false;
	}
	if(anyo<1900) fechaCorrecta=false;
	if(fechaCorrecta==true)
	{
		this->dia=dia;
		this->mes=mes;
		this->anyo=anyo;
		if (mens!=NULL)
		{
			mensaje=new char[strlen(mens)+1];
			strcpy(mensaje,mens);
		}
		else
			mensaje=NULL;
	}
	else
	{
		this->dia=1;
		this->mes=1;
		this->anyo=1900;
		this->mensaje=NULL;
	}

}

//! Constructor de Copia
/*! 
Constructor de copia que crea una fecha a partir de otra
\param c copia del objeto
*/
TCalendario::TCalendario (const TCalendario &c)
{
	dia=c.dia;
	mes=c.mes;
	anyo=c.anyo;
	if (c.mensaje!=NULL)
	{
		mensaje=new char[strlen(c.mensaje)+1];
		strcpy(mensaje,c.mensaje);
	}
	else
		mensaje=NULL;
}

//! Destructor de la clase
/*! 
Destructor que pone todos los valores a 0 y el mensaje a null
*/
TCalendario::~TCalendario()
{
	dia=1;
	mes=1;
	anyo=1900;
	if(mensaje!=NULL)
	{
		delete mensaje;
		mensaje=NULL;
	}
}

//! Operador de asignacion
/*! 
Sobrecarga del operador de asignacion
\return *this el propio objeto
*/
TCalendario & TCalendario::operator=(const TCalendario &c)
{
	dia=c.dia;
	mes=c.mes;
	anyo=c.anyo;
	if (c.mensaje!=NULL)
	{
		mensaje=new char[strlen(c.mensaje)+1];
		strcpy(mensaje,c.mensaje);
	}
	else
		mensaje=NULL;
	return (*this);
}

//! Operador suma
/*! 
Sobrecarga del operador suma
\param dias los que le tienes que sumar
\return copia copia del objeto con los dias sumados
*/
TCalendario TCalendario::operator+(int dias)
{
	TCalendario copia(*this);
	while(dias>0)
	{
		++copia;
		dias--;
	}
	return copia;
}

//! Operador resta
/*! 
Sobrecarga del operador resta
\param dias los que le tienes que restar 
\return copia copia del objeto con los dias restados
*/
TCalendario TCalendario::operator-(int dias)
{
	TCalendario copia(*this);
	while(dias>0)
	{
		--copia;
		dias--;
	}
	if(copia.anyo<1900)
	{
		copia.dia=1;
		copia.mes=1;
		copia.anyo=1900;
		copia.mensaje=NULL;
	}
	return copia;
}

//! Postincremento
/*! 
Sobrecarga del operador postincremento
\param i variable de valor simbolico, para distinguir el postincremento del preincremento
\return copia copia del objeto incrementado
*/
TCalendario TCalendario::operator++(int i)
{
	TCalendario copia(*this);
	++(*this);
	/*if (mensaje!=NULL)
	{
		copia.mensaje=new char[strlen(mensaje)+1];
		strcpy(copia.mensaje,mensaje);
	}
	else
		copia.mensaje=NULL;*/
	return copia;
	
}

//! Preincremento
/*! 
Operador de incremento
\return *this modifica el objeto propio
*/
TCalendario & TCalendario::operator++()
{
	bool bisiesto=(((anyo % 4 == 0) && (anyo % 100 != 0)) || (anyo % 400 == 0));
	dia++;
	if((dia==31) && ((mes==4) || (mes==6) || (mes==9) || (mes==11)))
	{
		mes++;
		dia=1;
	}
	if((dia==32) && ((mes==1) || (mes==3) || (mes==5) || (mes==7)|| (mes==8) || (mes==10) || (mes==12)))
	{
		mes++;
		dia=1;
		if(mes==13)
		{
			mes=1;
			anyo++;
		}
	}
	if((dia==29) && (mes==2) && bisiesto==false)
	{
		mes++;
		dia=1;
	}
	if((dia==30) && (mes==2) && bisiesto==true)
	{
		mes++;
		dia++;
	}
	return(*this);
}

//! Postdecremento
/*! 
Sobrecarga del operador postdecremento
\param i variable de valor simbolico, para distinguir el postdecremento del predecremento
\return copia copia del objeto decrementado
*/
TCalendario TCalendario::operator--(int i)
{
	TCalendario copia(*this);
	--(*this);
	/*if (mensaje!=NULL)
	{
		copia.mensaje=new char[strlen(mensaje)+1];
		strcpy(copia.mensaje,mensaje);
	}
	else
		copia.mensaje=NULL;*/
	return copia;
}

//! Predecremento
/*! 
Operador de decremento
\return *this modifica el objeto propio
*/
TCalendario & TCalendario::operator--()
{
	bool bisiesto=(((anyo % 4 == 0) && (anyo % 100 != 0)) || (anyo % 400 == 0));
	dia--;
	if((dia==0) && ((mes==2) || (mes==4) || (mes==6) || (mes==9) || (mes==11) || (mes==8) ))
	{
		mes--;
		dia=31;
	}
	if((dia==0) && ((mes==1) || (mes==5) || (mes==7)|| (mes==10) || (mes==12)))
	{
		mes--;
		dia=30;
		if(mes==0)
		{
			dia=31;
			mes=12;
			anyo--;
		}
	}
	if((dia==0) && (mes==3) && bisiesto==false)
	{
		mes--;
		dia=28;
	}
	if((dia==0) && (mes==3) && bisiesto==true)
	{
		mes--;
		dia=29;
	}
	if(dia!=1 || mes!=1 || anyo!=1900)
	{
		bool fechaCorrecta;
		TCalendario copia;//de aqui
		if(dia==1 && mes==1 && anyo==1900) fechaCorrecta=false;
		else
		{
			if ((*this)>copia) fechaCorrecta=true;
		}//aqui
		if(fechaCorrecta==false)//cambiar
		{
			dia=1;
			mes=1;
			anyo=1900;
			mensaje=NULL;
		}
	}
	if(anyo<1900)
	{
		dia=1;
		mes=1;
		anyo=1900;
		mensaje=NULL;
	}
	return (*this);
}

//! ModFecha
/*! 
Funcion que asigna del objeto otra fecha pasada por parametro, el mensaje no se modifica
\param d dia de la fecha parametro
\param m mes de la fecha parametro
\param a anyo de la fecha parametro
\return bool devuelve true si se ha podido realizar la modificacion
*/
bool TCalendario::ModFecha(int d, int m, int a)
{
	if(d==1 && m==1 && a==1900)
	{
		dia=d;
		mes=m;
		anyo=a;
		return(true);
	}
	else
	{
		TCalendario copia(d,m,a,NULL);
		if(copia.dia==1 && copia.mes==1 && copia.anyo==1900)
			return(false);
		else
		{
			dia=copia.dia;
			mes=copia.mes;
			anyo=copia.anyo;
			return(true);
		}
	}
}

//! ModMensaje
/*! 
Modifica la fecha del objeto propio por el que se le pasa por parametro
\param mens puntero a char con el mensaje  
*/
void TCalendario::ModMensaje(char *mens)
{
	if (mens!=NULL)
	{
		mensaje=new char[strlen(mens)+1];
		strcpy(mensaje,mens);
	}
	else
		mensaje=NULL;
}

//! Operador igualdad
/*! 
Sobrecarga del operador igualdad
\param copia parametro de tipo tcalendario pasado por referencia  
\return bool devuelve true si son iguales
*/
bool TCalendario::operator==(const TCalendario &copia)
{
	if(copia.dia==dia && copia.mes==mes && copia.anyo==anyo)
		if(copia.mensaje==NULL && mensaje!=NULL) return false;
		else
			if(copia.mensaje!=NULL && mensaje==NULL) return false;
			else
				if(copia.mensaje==NULL && mensaje==NULL) return true;
				else 
					if(strcmp(copia.mensaje,mensaje)==0) return true;
					else return false;
	else
		return(false);
}

//! Operador desigualdad
/*! 
Sobrecarga del operador desigualdad
\param copia parametro de tipo tcalendario pasado por referencia  
\return bool devuelve true si son distintos
*/
bool TCalendario::operator!=(const TCalendario &copia)
{
	if(copia.dia==dia && copia.mes==mes && copia.anyo==anyo)
		if(copia.mensaje==NULL && mensaje!=NULL) return true;
		else
			if(copia.mensaje!=NULL && mensaje==NULL) return true;
			else
				if(copia.mensaje==NULL && mensaje==NULL) return false;
				else 
					if(strcmp(copia.mensaje,mensaje)==0) return false;
					else return true;
	else
		return(true);
}


///! Operador mayor que
/*! 
Sobrecarga del operador mayor que
\param copia parametro de tipo tcalendario pasado por referencia  
\return bool devuelve true si el objeto es mayor que el parametro pasado por referencia
*/
bool TCalendario::operator>(const TCalendario &copia)const
{
	if(anyo>copia.anyo) return true;
	else
	{
		if(anyo==copia.anyo)
		{
			if(mes>copia.mes) return true;
			else
			{
				if(mes==copia.mes)
				{
					if(dia>copia.dia) return true;
					else
					{
						if(dia==copia.dia)
						{
							if(mensaje!=NULL && copia.mensaje!=NULL)
								if(strcmp(mensaje,copia.mensaje)>0) return true;
								else return false;
							else 
								if(mensaje==NULL && copia.mensaje==NULL) return false;
								else 
									if(mensaje==NULL) return false;
									else return true;
						}
						else return false;
					}
				}
				else return false;
			}
		}
		else return false;
	}
}

///! Operador menor que
/*! 
Sobrecarga del operador menor que
\param copia parametro de tipo tcalendario pasado por referencia  
\return bool devuelve true si el objeto es menor que el parametro pasado por referencia
*/
bool TCalendario::operator<(const TCalendario &copia)const
{
	if(anyo<copia.anyo) return true;
	else
	{
		if(anyo==copia.anyo)
		{
			if(mes<copia.mes) return true;
			else
			{
				if(mes==copia.mes)
				{
					if(dia<copia.dia) return true;
					else
					{
						if(dia==copia.dia)
						{
							if(mensaje!=NULL && copia.mensaje!=NULL)
								if(strcmp(mensaje,copia.mensaje)<0) return true;
								else return false;
							else 
								if(mensaje==NULL && copia.mensaje==NULL) return false;
								else 
									if(mensaje==NULL) return true;
									else return false;
						}
						else return false;
					}
				}
				else return false;
			}
		}
		else return false;
	}
}

//! EsVacio
/*! 
Comprueba si una fecha tiene valores asignados
\return bool devuelve true si esta vacia
*/
bool TCalendario::EsVacio()const
{
	if(dia==1 && mes==1 && anyo==1900 && mensaje==NULL) return true;
	else return false;
}

//! Dia
/*! 
Funcion que devuelve el dia
\return dia variable con el dia
*/
int TCalendario::Dia()const
{
	return dia;
}

///! Mes
/*! 
Funcion que devuelve el mes
\return mes variable con el mes
*/
int TCalendario::Mes()const
{
	return mes;
}

///! Anyo
/*! 
Funcion que devuelve el anyo
\return anyo variable con el anyo
*/
int TCalendario::Anyo()const
{
	return anyo;
}

///! Mensaje
/*! 
Funcion que devuelve el mensaje
\return mensaje puntero a char con el mensaje
*/
char* TCalendario::Mensaje()
{
	if(mensaje!=NULL)
	{
		return mensaje;
	}
}

//! Sobrecarga del operador salida
/*! 
Sobrecarga del operador salida
\param o tipo ostream
\param c tipo calendario con el objeto
\return o devuelve un ostream
*/
ostream & operator<<(ostream &o, const TCalendario &c)
{
	if(c.dia<10) o<<"0"<<c.dia<<"/";
	else o<<c.dia<<"/";
	if(c.mes<10) o<<"0"<<c.mes<<"/";
	else o<<c.mes<<"/";
	if(c.anyo<1) o<<"0000"<<" \"";
	else o<<c.anyo<<" \"";
	if(c.mensaje!=NULL)o<<c.mensaje<<"\"";
	else o<<"\"";
	return o;
}
