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
class NodoDoble
{
	int Dato;
	NodoDoble *Siguiente;
	NodoDoble *Anterior;
public:
	typedef NodoDoble *ListaDoble;
	NodoDoble();
	virtual ~NodoDoble();
	void setDato(int);
	int getDato();
	void setSiguente(ListaDoble);
	void setAnterior(ListaDoble);
	NodoDoble *getSiguiente();
	NodoDoble *getAnterior();
	void insertarluegode(ListaDoble &, int, int);
	void insertarincio(ListaDoble&, int);	
	void Borrar(ListaDoble &, int);
	void Insertar(ListaDoble &, int Insertar);	
	String^ MostrarDatos(ListaDoble);
};
typedef NodoDoble *ListaDoble;