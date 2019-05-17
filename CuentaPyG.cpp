/*
 * CuentaPyG.cpp
 *
 *  Created on: 7 may. 2019
 *      Author: nereasolabarrieta
 */
#include "CuentaPyG.h"
#include <iostream>
using namespace std;
using namespace cuentapyg;

CuentaPyG::CuentaPyG()
{
	this->gastos = 0.0;
	this->ingresos = 0.0;
	this->resultado = 0.0;
}
/**
 * Metodo para imprimir la cuenta de PyG
 */
void CuentaPyG::imprimirCuentaPyG()
{
	cout <<"CUENTA DE PERDIDAS Y GANACIAS: " << endl;
	cout << endl;
	cout <<"GASTOS: " <<this->gastos<< endl;
	cout <<"INGRESOS:  "<<this->ingresos<< endl;
	this->resultado = this->ingresos - this->gastos;
	cout <<"RESULTADO: " <<this->resultado << endl;
}
/**
 * Metodo para leer la cuenta de PyG del fichero
 */
void CuentaPyG::leerFichero() {
	FILE *f;
	f = fopen("CuentaPyG.dat", "rb");
	fread(&(this->gastos), sizeof(float), 1, f);
	fread(&(this->ingresos), sizeof(float), 1, f);
	this->resultado = this->ingresos - this->gastos;
	fclose(f);
}
/**
 * Metodo para escribir la cuenta de PyG en el fichero
 */
void CuentaPyG::escribir_fic() {
	FILE *f;
	f = fopen("CuentaPyG.dat", "wb");

	fwrite(&(this->gastos), sizeof(float), 1, f);
	fwrite(&(this->ingresos), sizeof(float), 1, f);
	fclose(f);
}

float CuentaPyG::getGastos() const
{
	return this->gastos;
}
float CuentaPyG::getIngresos() const
{
	return this->ingresos;
}
void CuentaPyG::setGastos(float valor)
{
	this->gastos = this->gastos + valor;
}
void CuentaPyG::setIngresos(float valor)
{
	this->ingresos =this->ingresos + valor;
}
