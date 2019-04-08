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
struct nodo
{
	int  nombre;

	struct nodo *siguiente;

	struct nodo *anterior;
};

struct nodo *primero, *ultimo;

int numNodos;

int pos;

void inicializar();
void insertar_ultimo(int);
void insertar_primero(int);
void insertar_intermedio(int, int);
void visualizar_inicio_final();
void buscar();
void eliminar();

void inicializar() {
	primero = NULL;
	ultimo = NULL;
	numNodos = 0;
}

void insertar_ultimo(int dato)
{
	struct nodo *nuevo;
	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->nombre = dato;
	nuevo->siguiente = primero;
	if (primero == NULL)
	{
		primero = nuevo;
		ultimo = nuevo;
		nuevo->siguiente = primero;
		nuevo->anterior = ultimo;
	}
	else {
		nuevo->siguiente = primero;

		nuevo->anterior = ultimo;

		ultimo->siguiente = nuevo;

		ultimo = nuevo;

		primero->anterior = ultimo;
	}

	numNodos++;
}

void insertar_primero(int dato)
{
	struct nodo *nuevo;
	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->nombre = dato;
	ultimo->siguiente = nuevo;
	nuevo->anterior = ultimo;
	nuevo->siguiente = primero;
	primero->anterior = nuevo;
	primero = nuevo;
	numNodos++;

}

void insertar_intermedio(int dato, int posici)
{
	struct nodo *actual;
	struct nodo *nuevo;
	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	if (nuevo == NULL)
		return;
	if (numNodos < 2)
		return;
		
	else {
		int pos_insertar;
		nuevo->nombre = dato;
		(pos_insertar = posici);
		if ((pos_insertar > 1) && (pos_insertar <= numNodos))
		{
			actual = primero;
			for (pos = 2; pos <pos_insertar; ++pos)
				actual = actual->siguiente;
			nuevo->siguiente = actual->siguiente;
			nuevo->anterior = actual;
			actual->siguiente->anterior = nuevo;
			actual->siguiente = nuevo;
			numNodos++;
		}
	}
}

void visualizar_inicio_final()
{

	struct nodo *actual;

	pos = 1;

	actual = primero;

	while (pos <= numNodos)
	{
		printf(" %d.- ", pos);

		

		actual = actual->siguiente;

		pos++;
	}
}