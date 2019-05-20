/*
 * clsCliente.cpp
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */

#include "Cliente.h"
#include <iostream>
#include <stdio.h>
#include "string.h"
using namespace std;
using namespace cliente;

Cliente::Cliente() {
	this->nom = new char[30];
	this->ape = new char [30];
	this->dni = new char[9];
	dni[0] = '*';
	this->acumulado = 0.0;
}

Cliente::~Cliente() {
	delete[] nom;
	delete[] ape;
	delete[] dni;
}
void Cliente::setNom(char* nom) {
	this->nom = nom;
}
char* Cliente::getNom() const {
	return this->nom;
}
void Cliente::setApe(char* ape) {
	this->ape = ape;
}
char* Cliente::getApe() const {
	return this->ape;
}
void Cliente::setDni(char* dni) {
	this->dni = dni;
}
char* Cliente::getDni() const {
	return this->dni;
}
void Cliente::setAcumulado(float acumulado) {
	this->acumulado = acumulado;
}
float Cliente::getAcumulado() const {
	return this->acumulado;
}

/**
 * Metodo para escribir los clientes en el fichero
 */
void Cliente::escribirFic_bin_clientes(Cliente *c, int num_clientes) {

	FILE *f;
	f = fopen("Clientes.txt", "w");
	fprintf(f, "%i\n", num_clientes);
	for (int i = 0; i < num_clientes; i++) {

		fprintf(f, "%f\n", (c + i)->acumulado);
		fprintf(f, "%i\n", (strlen((c + i)->nom)));
		fprintf(f, "%s\n", (c + i)->nom);
		fprintf(f, "%i\n", strlen((c + i)->ape));
		fprintf(f, "%s\n", (c + i)->ape);
		fprintf(f, "%i\n", strlen((c + i)->dni));
		fprintf(f, "%s\n", (c + i)->dni);

	}
	fclose(f);

}
/**
 * Metodo para leer los clientes del fichero
 */
void Cliente::LeerFic_bin_clientes(Cliente *c) {
	FILE *f;
	f = fopen("Clientes.txt", "r");
	int num_clientes = 0;

	fscanf(f, " %i", &num_clientes);
	int len = 0;
	float acumulado = 0.0;
	for (int i = 0; i < num_clientes; i++) {
		fscanf(f, " %f", &acumulado);

		(c + i)->acumulado = acumulado;

		fscanf(f, "%i", &len);
		(c + i)->nom = new char[len];
		fscanf(f, " %s", (c + i)->nom);

		fscanf(f, "%i", &len);
		(c + i)->ape = new char[len];
		fscanf(f, " %s", (c + i)->ape);

		fscanf(f, "%i", &len);
		(c + i)->dni = new char[len];
		fscanf(f, " %s", (c + i)->dni);

	}
	fclose(f);

}

/**
 * Metodo para imprimir clientes
 */
void Cliente::imprimirCliente() {

	cout << "Nombre: " << this->nom << endl;
	cout << "Apellido: " << this->ape << endl;
	cout << "Dni: " << this->dni << endl;
	cout << "Acumulado: " << this->acumulado << endl;
	cout << endl;
}
