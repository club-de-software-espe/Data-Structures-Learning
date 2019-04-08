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
#include<iostream>
using namespace System;
class NodoCircular
{
	int Dato;
	NodoCircular *Siguiente;
public:
	typedef NodoCircular *ListaCircular;
	NodoCircular();
	virtual ~NodoCircular();
	int getDato();
	void setDato(int);
	ListaCircular getSiguiente();
	void setSiguiente(ListaCircular);
	void Insertar(ListaCircular &, int);
	void Borrar(ListaCircular &, int);	
	void InsertarFinal(ListaCircular &, int);
	void InsertarDespuesDe(ListaCircular &, int, int);
	String^ MostrarDatos(ListaCircular);
};
typedef NodoCircular *ListaCircular;


