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
#include "NodoDoble.h"
void NodoDoble::setDato(int _Dato)
{
	this->Dato = _Dato;
	return;
}
int NodoDoble::getDato() { return Dato; }
void NodoDoble::setSiguente(ListaDoble _Siguiente)
{
	Siguiente = _Siguiente;
	return;
}
void NodoDoble::setAnterior(ListaDoble _Anterior)
{
	Anterior = _Anterior;
	return;
}
NodoDoble * NodoDoble::getSiguiente() { return Siguiente; }
NodoDoble * NodoDoble::getAnterior() { return Anterior; }
void NodoDoble::Insertar(ListaDoble &L, int Insertar)
{
	ListaDoble Nueva = new (NodoDoble);

	if (L == NULL)
	{
		Nueva->setDato(Insertar);
		Nueva->setAnterior(NULL);
		Nueva->setSiguente(NULL);
	}
	else
	{
		Nueva->setDato(Insertar);
		Nueva->setAnterior(NULL);
		Nueva->setSiguente(L);
	}
	L = Nueva;
	return;
}
void NodoDoble::Borrar(ListaDoble &l, int Eliminar)
{
	ListaDoble Aux = new (NodoDoble);
	Aux = l;
	ListaDoble Ant = new (NodoDoble);
	while (Aux != NULL)
	{
		if (Eliminar == Aux->getDato())
		{
			if (Aux = l)
			{
				l = l->getSiguiente();
			}
			else
			{
				Ant->setSiguente(Aux->getSiguiente());

			}
			delete (Aux);
			return;
		}
		Ant = Aux;
		Aux = Aux->getSiguiente();
	}
}
void NodoDoble::insertarincio(ListaDoble &a, int ingreso) 
{
	ListaDoble nuevo = new(NodoDoble);
	ListaDoble  ant = new (NodoDoble);
	nuevo->setDato(ingreso);
	if (a == NULL) 
	{
		nuevo->setSiguente(a);
		nuevo->setAnterior(NULL);
		a = nuevo;
	}
	else 
	{
		ant = a;
		while (ant->getSiguiente())
		{
			ant = ant->getSiguiente();
		}
	}
	nuevo->setSiguente(NULL);
	ant->setAnterior(NULL);
	ant->setSiguente(nuevo);
}
void NodoDoble::insertarluegode(ListaDoble &a, int b, int x) {
	ListaDoble p = new (NodoDoble);
	ListaDoble nuevo = new (NodoDoble);fflush(stdin);
	p = a;
	nuevo->setDato(x);
	while (p != NULL) 
	{
		if (p->getDato() == b)
		{
			if (p == a)
			{
				a->Insertar(a, x);
				return;
			}
			p->getSiguiente()->setAnterior(nuevo);
			nuevo->setSiguente(p->getSiguiente());
			p->setSiguente(nuevo);
			nuevo->setAnterior(p);
			return;
		}
		p = p->getSiguiente();
	}
}
String^ NodoDoble::MostrarDatos(ListaDoble N)
{
	String^ Mensaje = "";
	while (N != NULL)
	{
		Mensaje += Convert::ToString(N->getDato()) + "\n";
		N = N->getSiguiente();
	}
	return Mensaje;
}
NodoDoble::NodoDoble()
{
}
NodoDoble::~NodoDoble()
{
}
