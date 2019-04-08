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
struct nodoarbol
{                        //ESTRUCTURA DEL ARBOL
	struct nodoarbol *izqnodo;
	int info;
	struct nodoarbol *dernodo;
};
typedef struct nodoarbol NODO;    //DEFINICION DE TIPO NODO
typedef NODO *ARBOL;

void preorden(ARBOL rarbol, String^ &Texto) 
{
	if (rarbol != NULL) 
	{
		Texto += Convert::ToString(rarbol->info)+"\t";
		preorden(rarbol->izqnodo,Texto);
		preorden(rarbol->dernodo, Texto);
	}
}

void inorden(ARBOL rarbol, String^ &Texto)
{
	if (rarbol != NULL) 
	{		
		inorden(rarbol->izqnodo,Texto);
		Texto += Convert::ToString(rarbol->info)+ "\t";
		inorden(rarbol->dernodo,Texto);
	}
}
void postorden(ARBOL rarbol,String^&Texto) 
{
	if (rarbol != NULL) 
	{
		postorden(rarbol->izqnodo,Texto);
		postorden(rarbol->dernodo,Texto);
		Texto += Convert::ToString(rarbol->info)+ "\t";
	}
}
