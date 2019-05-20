/*
 * Proveedor.cpp
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */

#include "Proveedor.h"
#include <iostream>
#include "string.h"
using namespace proveedor;
using namespace std;

Proveedor::Proveedor() {
	this->nom = new char[30];
	this->NIF = new char[9];
	NIF[0]= '*';
	NIF[1]= '*';
	NIF[2]= '*';
	NIF[3]= '*';
	NIF[4]= '*';
	NIF[5]= '*';
	NIF[6]= '*';
	NIF[7]= '*';
	NIF[8]= '*';

}
Proveedor::~Proveedor() {

	delete[] nom;
	delete[] NIF;
}
void Proveedor::setNom(char* nom) {
	this->nom = nom;
}
char* Proveedor::getNom() {
	return this->nom;
}
void Proveedor::setNIF(char* NIF) {
	this->NIF = NIF;
}
char* Proveedor::getNIF() {
	return this->NIF;
}

/**
 * Metodo para guardar los proveedores en el fichero
 */
void Proveedor::escribirFic_bin_proveedores(Proveedor* p, int num_proveedores) {
	FILE *f;
	f = fopen("Proveedores.txt", "w");
	fprintf(f, "%i\n", num_proveedores);
	for (int i = 0; i < num_proveedores; i++) {

		fprintf(f, "%i\n", strlen((p + i)->nom));
		fprintf(f, "%s\n", (p + i)->nom);

		fprintf(f, "%i\n", strlen((p + i)->NIF));
		fprintf(f, "%s\n", (p + i)->NIF);

	}
	fclose(f);

}

/**
 * Metodo para leer proveedor del fichero
 */
void Proveedor::leerFic_bin_proveedores(Proveedor *p) {

	FILE *f;
	f = fopen("Proveedores.txt", "r");
	int num_proveedores = 0;

	fscanf(f, " %i", &num_proveedores);

	int len = 0;

	for (int i = 0; i < num_proveedores; i++) {

		fscanf(f, "%i", &len);
		(p + i)->nom = new char[len];
		fscanf(f, " %[^\n]s", (p + i)->nom);

		fscanf(f, "%i", &len);
		(p + i)->NIF = new char[len];
		fscanf(f, " %[^\n]s", (p + i)->NIF);

	}
	fclose(f);

}
/**
 * Metodo para imprimir Proveedor
 */
void Proveedor::ImprimirProveedor() {

	cout << "Nombre: " << this->nom << endl;
	cout << "NIF: " << this->NIF << endl;
	cout << endl;
}
