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
#pragma once
using namespace System;
class Pila
{
private:
	int dato;
	Pila *Siguiente;
public:
	Pila();
	~Pila();
	typedef Pila *Pila_simple;
	void setDato(int);
	int getDato();
	void setSiguente(Pila_simple);
	Pila *getSiguiente();
	void Push(Pila_simple &, int);
	String^ Mostrar(Pila_simple);
	int Pop(Pila_simple &);
	
};
typedef Pila *Pila_simple;
