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
#include "Pila.h"
#include<iostream>
void Pila::setDato(int _Dato)
{
	this->dato = _Dato;
}
int Pila::getDato() { return dato; }

void Pila::setSiguente(Pila_simple _Siguiente)
{
	Siguiente = _Siguiente;
	return;
}
Pila * Pila::getSiguiente() { return Siguiente; }
void Pila::Push(Pila_simple &P, int  ingreso)
{
	Pila_simple Nueva = new (Pila);
	Nueva->setDato(ingreso);
	if (P == NULL)
	{
		Nueva->setSiguente(NULL);
		P = Nueva;
	}
	else
	{
		Nueva->setSiguente(P);	
		P = Nueva;
	}	
	return;
}
String^ Pila::Mostrar(Pila_simple N)
{
	Pila_simple Nueva = new (Pila);
	Nueva = N;
	String^ Mensaje = "";
	while (Nueva != NULL)
	{
		Mensaje += Convert::ToString(Nueva->getDato())+"\n";
		Nueva = Nueva->getSiguiente();
	}
	return Mensaje;
}
int Pila::Pop(Pila_simple &P)
{
	Pila_simple Aux = new(Pila);
	Aux = P;
	int Valor = 0;
	if (P == NULL) //probamos si la lista  esta vacia
	{		
		return NULL;
	}
	else
	{
		Valor = this->getDato();
		P=Aux->getSiguiente();		
	}
	return Valor;
}
Pila::Pila()
{
}
Pila::~Pila()
{
}
