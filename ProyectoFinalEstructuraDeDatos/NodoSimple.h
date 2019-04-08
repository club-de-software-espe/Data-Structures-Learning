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
class NodoSimple
{
private:
	int Dato;
	NodoSimple *Siguiente;
public:
	typedef NodoSimple *ListaSimple;
	NodoSimple();
	virtual ~NodoSimple();
	void setDato(int);
	int getDato();
	void setSiguente(ListaSimple);
	NodoSimple *getSiguiente();
	void Insertar(ListaSimple &, int);		
	void Borrar(ListaSimple &, int);
	void ingresarfinal(ListaSimple &, int);
	void inserartluegode(ListaSimple &, int, int);
	String^ MostrarDatos(ListaSimple);
};
typedef NodoSimple *ListaSimple;
