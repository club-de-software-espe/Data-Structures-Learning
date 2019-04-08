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
#include <iostream>
using namespace System;
struct nodo
{
	int nro;
	struct nodo *sgte;
};
struct cola
{
	nodo *delante;
	nodo *atras;
};
void encolar(struct cola &q, int valor)
{
	struct nodo *aux = new(struct nodo);
	aux->nro = valor;
	aux->sgte = NULL;
	if (q.delante == NULL)
		q.delante = aux;   // encola el primero elemento
	else
		(q.atras)->sgte = aux;
	q.atras = aux;        // puntero que siempre apunta al ultimo elemento
}
int desencolar(struct cola &q)
{
	int num;
	struct nodo *aux;
	aux = q.delante;      // aux apunta al inicio de la cola
	num = aux->nro;
	q.delante = (q.delante)->sgte;
	delete(aux);          // libera memoria a donde apuntaba aux
	return num;
}
String ^muestraCola(struct cola q)
{
	struct nodo *aux;
	String^ Mensaje = "";
	aux = q.delante;
	while (aux != NULL)
	{
		Mensaje += Convert::ToString(aux->nro)+"\n";
		aux = aux->sgte;	
	}
	return Mensaje;
}
void vaciaCola(struct cola &q)
{
	struct nodo *aux;

	while (q.delante != NULL)
	{
		aux = q.delante;
		q.delante = aux->sgte;
		delete(aux);
	}
	q.delante = NULL;
	q.atras = NULL;
}
