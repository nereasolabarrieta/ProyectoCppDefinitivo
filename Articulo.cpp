/*
 * Articulo.cpp
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */

#include "Articulo.h"
using namespace articulo;
#include <iostream>
using namespace std;
#include "string.h"


Articulo::Articulo()
{
	this->codigo= new char[9];
	char * cod_vacio="*********";
	strcpy(this->codigo ,cod_vacio);

	this->nombre= new char[30];
	this->precio = 0.0;

}
Articulo::~Articulo()
{
	delete[] codigo;
	delete[] nombre;
}
void Articulo::setCodigo(char* cod)
{
	this->codigo= new char[10];
	strcpy(this->codigo, cod);

}
char* Articulo::getCodigo() const
{
	return this->codigo;
}
void Articulo::setNombre(char* nom)
{
	this->nombre= new char[30];
	strcpy(this->nombre, nom);
}
char* Articulo::getNombre() const
{
	return this->nombre;
}
void Articulo::setPrecio(float precio)
{
	this->precio =precio;
}
float Articulo::getPrecio() const
{
	return this->precio;
}

void Articulo::enviarImporte(float precio, int cantidad, Cliente *cliente) {

	float acumulado =0.0;
	acumulado = precio * cantidad;

	float importe = cliente->getAcumulado() + acumulado;

	if (importe > 100)
	{

		float descuento = importe * 0.1;
		cliente->setAcumulado(importe-descuento);
	}
	else
	{
		cliente->setAcumulado(importe);
	}
}
void Articulo::Imprimir()
{
	cout << "Nombre: " << this->nombre << endl;
	cout << "Codigo: " <<this->codigo << endl;
	cout << "Precio: " << this->precio << endl;

}

