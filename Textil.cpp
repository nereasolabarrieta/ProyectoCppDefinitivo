/*
 * Textil.cpp
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */
#include "Textil.h"
using namespace textil;
#include <iostream>
#include <string.h>
using namespace std;

Textil::Textil() :
		Articulo() {
	this->stockXS = 0;
	this->stockS = 0;
	this->stockM = 0;
	this->stockL = 0;
	this->color = NULL;

}
Textil::~Textil() {
	delete[] color;

}
void Textil::setStockL(int stockL) {
	this->stockL = stockL;
}
int Textil::getStockL() const {
	return this->stockL;
}
void Textil::setStockM(int stockM) {
	this->stockM = stockM;
}
int Textil::getStockM() const {
	return this->stockM;
}
void Textil::setStockXS(int stockXS) {
	this->stockXS = stockXS;
}
int Textil::getStockXS() const {
	return this->stockXS;
}
void Textil::setStockS(int stockS) {
	this->stockS = stockS;
}
int Textil::getStockS() const {
	return this->stockS;
}
void Textil::setColor(char* color) {
	this->color = new char[strlen(color)];
	this->color = color;
}
char* Textil::getColor() const {
	return this->color;
}
void Textil::escribir_fic_bin_textil(Textil* t, int num_textil) {
	FILE *f;
	f = fopen("Textiles.txt", "w");
	fprintf(f, "%i\n", num_textil);
	for (int i = 0; i < num_textil; i++) {
		fprintf(f, "%i\n", (strlen((t + i)->getCodigo())));
		fprintf(f, "%s\n", (t + i)->getCodigo());

		fprintf(f, "%i\n", (strlen((t + i)->getNombre())));
		fprintf(f, "%s\n", (t + i)->getNombre());

		fprintf(f, "%f\n", (t + i)->getPrecio());
		fprintf(f, "%i\n", (t + i)->stockXS);
		fprintf(f, "%i\n", (t + i)->stockS);
		fprintf(f, "%i\n", (t + i)->stockM);
		fprintf(f, "%i\n", (t + i)->stockL);
		fprintf(f, "%i\n", strlen((t + i)->color));
		fprintf(f, "%s\n", (t + i)->color);

	}
	fclose(f);

}
void Textil::LeerFic_bin_textil(Textil* t) {
	FILE *f;
	f = fopen("Textiles.txt", "r");
	int num_textiles = 0;

	fscanf(f, " %i", &num_textiles);
	char *nom;
	char *codigo;
	char *color;
	int len = 0;
	float precio = 0.0;

	for (int i = 0; i < num_textiles; i++) {

		fscanf(f, "%i", &len);
		codigo = new char[len];
		fscanf(f, " %[^\n]s", codigo);
		(t + i)->setCodigo(codigo);

		fscanf(f, "%i", &len);
		nom = new char[len];
		fscanf(f, " %[^\n]s", nom);
		(t + i)->setNombre(nom);

		fscanf(f, "%f", &precio);
		(t + i)->setPrecio(precio);

		fscanf(f, "%d", &(t + i)->stockXS);
		fscanf(f, "%d", &(t + i)->stockS);
		fscanf(f, "%d", &(t + i)->stockM);
		fscanf(f, "%d", &(t + i)->stockL);

		fscanf(f, "%i", &len);

		(t + i)->color = new char[len];
		color = new char[len];

		fscanf(f, "%s", color);
		strcpy((t + i)->color, color);
	}
	fclose(f);
	delete color;
	delete nom;
	delete codigo;
}
/**
 * Metodo para imprimir textil
 */
void Textil::Imprimir() {
	Articulo::Imprimir();
	cout << "Color: " << this->color << endl;
	cout << "Stock XS: " << this->stockXS << endl;
	cout << "Stock S: " << this->stockS << endl;
	cout << "Stock M: " << this->stockM << endl;
	cout << "Stock L: " << this->stockL << endl;
	cout << endl;
}
