//*************************************************************************************************************//
//                               UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                       //
//                   				Proyecto Final de estructura de datos                  				       //
//           Integrantes:  Miguel Guaño-Wladymir Brborich      NRC:4408                                        //
//           Docente: Ing Fernando Solis       Asingatura: Estructura de datos                                 //
//           Carrera: Ingenieria en Sistemas e informatica. fecha:2016-08-17                                   //
//                                                                                                             //
//                                                                                                             //
//                                                                                                             //
//*************************************************************************************************************//
#include "NodoCircular.h"
int NodoCircular::getDato() { return Dato; }
void NodoCircular::setDato(int _Dato)
{
	Dato = _Dato;
	return;
}
ListaCircular  NodoCircular::getSiguiente()
{
	return Siguiente;
}
void NodoCircular::setSiguiente(ListaCircular _Siguiente)
{
	this->Siguiente = _Siguiente;
	return;
}
void NodoCircular::Insertar(ListaCircular &L, int _Dato)
{	
	ListaCircular Nuevo = new (NodoCircular);
	Nuevo->setDato(_Dato);
	if (L == NULL)
	{
		Nuevo->setSiguiente(L);
		L = Nuevo;
	}
	else
	{
		Nuevo->setSiguiente((L->getSiguiente()));
	}
	L->setSiguiente(Nuevo);

	return;
}
void NodoCircular::Borrar(ListaCircular &L, int Borrar)
{
	ListaCircular Nuevo = new (NodoCircular);
	ListaCircular Aux = new (NodoCircular);
	Aux = L;
	do
	{
		if (Aux->getSiguiente()->getDato() != Borrar)
		{
			Aux = Aux->getSiguiente();
		}

	} while (Aux->getSiguiente()->getDato() != Borrar&&Aux != L);
	if (Aux->getSiguiente()->getDato() == Borrar)
	{
		if (Aux == Aux->getSiguiente())
		{
			free(Aux);
			Aux = NULL;
		}
		else
		{
			Nuevo = Aux->getSiguiente();
			Aux->setSiguiente(Nuevo->getSiguiente());
			free(Nuevo);
		}
		L = Aux;
	}
	return;
}
void NodoCircular::InsertarFinal(ListaCircular &L, int Insertar)
{
	ListaCircular Siguiente = new NodoCircular;
	ListaCircular Nuevo = new NodoCircular;
	Siguiente = L;	
	if (L == NULL)
	{
		Nuevo->setDato(Insertar);
		L = Nuevo;
		L->setSiguiente(Nuevo);return;
	}
	else
	{
		do
		{
			if (Siguiente->getSiguiente() == L)
			{
				Nuevo->setDato(Insertar);
				Nuevo->setSiguiente(L);
				Siguiente->setSiguiente(Nuevo);
				return;
			}
			Siguiente = Siguiente->getSiguiente();

		} while (Siguiente != L);
	}
	return;
}
void NodoCircular::InsertarDespuesDe(ListaCircular &L, int Despues, int Insertar)
{
	ListaCircular Nueva = new NodoCircular;
	ListaCircular Siguiente = new NodoCircular;
	Siguiente = L;
	do
	{
		if (Siguiente->getDato() == Despues)
		{
			Nueva->setDato(Insertar);
			Nueva->setSiguiente(Siguiente->getSiguiente());
			Siguiente->setSiguiente(Nueva);
			return;
		}
		Siguiente = Siguiente->getSiguiente();
	} while (Siguiente != L);
	return;
}
String^ NodoCircular::MostrarDatos(ListaCircular L)
{
	String^ Mensaje = "";
	ListaCircular Nuevo = new (NodoCircular);
	Nuevo = L;
	do
	{
		if (Nuevo != L)
		{
			Mensaje += Nuevo->getDato() + "\n";			
		}	
		Nuevo = Nuevo->getSiguiente();

	} while (Nuevo != L);
	Mensaje += L->getDato() + "\n";
	return Mensaje;
}
NodoCircular::NodoCircular()
{
}
NodoCircular::~NodoCircular()
{
}