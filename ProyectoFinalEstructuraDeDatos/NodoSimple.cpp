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
#include "NodoSimple.h"
void NodoSimple::setDato(int _Dato)
{
	this->Dato = _Dato;
	return;
}
int NodoSimple::getDato() { return Dato; }
void NodoSimple::setSiguente(ListaSimple _Siguiente)
{
	Siguiente = _Siguiente;
	return;
}
NodoSimple * NodoSimple::getSiguiente() { return Siguiente; }
void NodoSimple::Insertar(ListaSimple &L, int Insertar)
{
	ListaSimple Nueva = new (NodoSimple);
	Nueva->setDato(Insertar);
	Nueva->setSiguente(L);
	L = Nueva;	
	return;
}
void NodoSimple::Borrar(ListaSimple &L, int Borrar)
{
	ListaSimple Nuevo = new (NodoSimple);
	ListaSimple Nuevo2 = new (NodoSimple);
	ListaSimple Aux = new NodoSimple;
	Aux = NULL;
	Nuevo = L;
	Nuevo2 = L;
	while (Nuevo != NULL)
	{
		if (Nuevo->getDato() == Borrar)
		{
			if (Nuevo == L)
			{
				L = L->getSiguiente();
				return;
			}
		}
		if (Nuevo->getSiguiente() == NULL)
		{
			L = Nuevo2;
			return;
		}
		if (Nuevo->getSiguiente()->getDato() == Borrar)
		{
			Aux = Nuevo->getSiguiente();
			Nuevo->setSiguente(Aux->getSiguiente());
			delete(Aux);
			return;
		}
		Nuevo = Nuevo->getSiguiente();
	}
	return;
}
void NodoSimple::ingresarfinal(ListaSimple &b, int entrada) {
	ListaSimple nuevo = new(NodoSimple);
	ListaSimple  ant=new (NodoSimple);
	nuevo->setDato(entrada);
	if (b == NULL)
	{
		nuevo->setSiguente(b);
		b = nuevo;
	}
	else 
	{
		ant = b;
		while (ant->getSiguiente()!=NULL)
		{
			ant = ant->getSiguiente();
		}
	}
	nuevo->setSiguente(NULL);
	ant->setSiguente(nuevo);
	
}
void NodoSimple::inserartluegode(ListaSimple & b, int ingreso, int buscar) 
{

	ListaSimple nuevo = new (NodoSimple);	
	ListaSimple p = new (NodoSimple);
	p = b;
	ListaSimple ant = new (NodoSimple);
	nuevo->setDato(ingreso);
	while (p != NULL) 
	{
		
		if (p->getDato() == buscar) 
		{
			if (p == b)
			{
				b->Insertar(b, ingreso);
				return;
			}
			ant->setSiguente(nuevo);
			nuevo->setSiguente(p);			
		}
		ant = p;
		p = p->getSiguiente();
	}
}
String^ NodoSimple::MostrarDatos(ListaSimple L)
{
	String^ Mensaje = "";
	while (L!=NULL)
	{
		Mensaje += Convert::ToString(L->getDato()) + "\n";
		L = L->getSiguiente();
	}
	return Mensaje;
}
NodoSimple::NodoSimple()
{

}
NodoSimple::~NodoSimple()
{

}

