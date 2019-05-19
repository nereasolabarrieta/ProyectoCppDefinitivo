/*
 * Complemento.cpp
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */

#include "Complemento.h"
using namespace complemento;
#include <iostream>
using namespace std;
#include <string.h>
#include <stdbool.h>
Complemento::Complemento() :
		Articulo() {
	this->stock = 0;
}
Complemento::~Complemento() {
}
void Complemento::setStock(int stock) {
	this->stock = stock;
}
int Complemento::getStock() const {
	return this->stock;
}

void Complemento::escribir_fic_bin_complementos(Complemento* c,
		int num_complementos) {

	FILE *f;
	f = fopen("Complementos.txt", "w");
	fprintf(f, "%i\n", num_complementos);
	for (int i = 0; i < num_complementos; i++) {

		fprintf(f, "%i\n", (strlen((c + i)->getCodigo())));
		fprintf(f, "%s\n", (c + i)->getCodigo());

		fprintf(f, "%i\n", (strlen((c + i)->getNombre())));
		fprintf(f, "%s\n", (c + i)->getNombre());

		fprintf(f, "%f\n", (c + i)->getPrecio());
		fprintf(f, "%i\n", (c + i)->stock);

	}
	fclose(f);

}

void Complemento::LeerFic_bin_complementos(Complemento* c) {
	FILE *f;
	f = fopen("Complementos.txt", "r");
	int num_complementos = 0;

	fscanf(f, " %i", &num_complementos);
	char *nom;
	char *codigo;
	int len = 0;
	float precio = 0.0;

	for (int i = 0; i < num_complementos; i++) {

		fscanf(f, "%i", &len);
		codigo = new char[len];
		fscanf(f, " %[^\n]s", codigo);
		(c + i)->setCodigo(codigo);

		fscanf(f, "%i", &len);
		nom = new char[len];
		fscanf(f, " %[^\n]s", nom);
		(c + i)->setNombre(nom);

		fscanf(f, "%f", &precio);
		(c + i)->setPrecio(precio);
		fscanf(f, "%d", &(c + i)->stock);

	}
	fclose(f);
	delete nom;
	delete codigo;

}
void Complemento::Imprimir() {
	Articulo::Imprimir();
	cout << "Stock: " << this->stock << endl;
	cout << endl;
}
