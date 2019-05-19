/*
 * Balance.cpp
 *
 *  Created on: 7 may. 2019
 *      Author: nereasolabarrieta
 */
#include "Balance.h"
#include <iostream>
using namespace std;
using namespace balance;
Balance::Balance() {
	this->importeANC = 0.0;
	this->importeDisponible = 0.0;
	this->importePC = 0.0;
	this->importePN = 0.0;
	this->importePNC = 0.0;
	this->importeRealizable = 0.0;
	this->importeStock = 0.0;
}

float Balance::getStock() const {
	return this->importeStock;
}
float Balance::getRealizable() const {
	return this->importeRealizable;
}
float Balance::getDisponible() const {
	return this->importeDisponible;
}
float Balance::getANC() const {
	return this->importeANC;
}
float Balance::getPC() const {
	return this->importePC;
}
float Balance::getPNC() const {
	return this->importePNC;
}
float Balance::getPN() const {
	return this->importePN;
}

void Balance::setStock(float valor) {
	this->importeStock = valor;
}
void Balance::setRealizable(float valor) {
	this->importeRealizable = valor;
}
void Balance::setDisponible(float valor) {
	this->importeDisponible = valor;
}
void Balance::setANC(float valor) {
	this->importeANC = valor;
}
void Balance::setPC(float valor) {
	this->importePC = valor;
}
void Balance::setPNC(float valor) {
	this->importePNC = valor;
}
void Balance::setPN(float valor) {
	this->importePN = valor;
}
/**
 * Metodo para introucir los datos al balance
 */
void Balance::introducir() {

	do {
		cout << "Introducir STOCK\n" << endl;
		cin >> this->importeStock;
		cout << endl;

		cout << "Introducir REALIZABLE" << endl;
		cin >> this->importeRealizable;
		cout << endl;

		cout << "Introducir DISPONIBLE" << endl;
		cin >> this->importeDisponible;
		cout << endl;

		cout << "Introducir ACTIVO NO CORRIENTE" << endl;
		cin >> this->importeANC;
		cout << endl;

		cout << "Introducir PASIVO CORRIENTE" << endl;
		cin >> this->importePC;
		cout << endl;

		cout << "Introducir PASIVO NO CORRIENTE" << endl;
		cin >> this->importePNC;
		cout << endl;

		cout << "Introducir PATRIMONIO NETO" << endl;
		cin >> this->importePN;
		cout << endl;

		if (!this->cuadra()) {
			cout
					<< "El balance no cuadra. Por favor, introduce otra vez los datos:"
					<< endl;
		}

	} while (!this->cuadra());

	this->escribir_ficBin();
}
/**
 * Metodo para comprobar si existe algun fichero con ese nombre
 */
bool Balance::existsFile(char* filename) {
	FILE* f = NULL;
	f = fopen(filename, "r");
	if (f == NULL)
		return false;
	else {
		fclose(f);
		return true;
	}
	fclose(f);
}
/**
 * Metodo para imprimir el balance
 */
void Balance::imprimirBalance() {
	float totalA = this->importeANC + this->importeDisponible
			+ this->importeStock + this->importeRealizable;
	float totalP = this->importePC + this->importePN + this->importePNC;
	cout << "BALANCE: " << endl;
	cout << endl;
	cout << "TOTAL ACTIVO: " << totalA << endl;
	cout << "Activo no corriente:  " << this->importeANC << endl;
	cout << "Activo corriente:  "
			<< this->importeDisponible + this->importeStock
					+ this->importeRealizable << endl;
	cout << "Stock:  " << this->importeStock << endl;
	cout << "Realizable:  " << this->importeRealizable << endl;
	cout << "Disponible:  " << this->importeDisponible << endl;

	cout << "--------------------------" << endl;

	cout << "TOTAL PASIVO Y PATRIMONIO NETO:  " << totalP << endl;
	cout << "Patrimonio neto:  " << this->importePN << endl;
	cout << "Pasivo no corriente:  " << this->importePNC << endl;
	cout << "Pasivo corriente:  " << this->importePC << endl;
}
/**
 * Metodo para leer el fichero del balance.dat
 */
void Balance::leerFichero() {
	FILE *f;
	f = fopen("Balance.dat", "rb");
	fread(&(this->importeANC), sizeof(float), 1, f);
	fread(&(this->importeStock), sizeof(float), 1, f);

	fread(&(this->importeRealizable), sizeof(float), 1, f);
	fread(&(this->importeDisponible), sizeof(float), 1, f);
	fread(&(this->importePN), sizeof(float), 1, f);
	fread(&(this->importePNC), sizeof(float), 1, f);
	fread(&(this->importePC), sizeof(float), 1, f);
	fclose(f);
}
/**
 * Metodo para escribir el balance en el fichero
 */
void Balance::escribir_ficBin() {
	FILE *f;
	f = fopen("Balance.dat", "wb");

	fwrite(&(this->importeANC), sizeof(float), 1, f);
	fwrite(&(this->importeStock), sizeof(float), 1, f);
	fwrite(&(this->importeRealizable), sizeof(float), 1, f);
	fwrite(&(this->importeDisponible), sizeof(float), 1, f);
	fwrite(&(this->importePN), sizeof(float), 1, f);
	fwrite(&(this->importePNC), sizeof(float), 1, f);
	fwrite(&(this->importePC), sizeof(float), 1, f);

	fclose(f);
}
/**
 * Metodo para comprobar si el balance cuadra
 */
bool Balance::cuadra() {
	float activo = this->importeStock + this->importeRealizable
			+ this->importeDisponible + this->importeANC;
	float pasivo = this->importePC + this->importePNC + this->importePN;
	if (activo == pasivo)

		return true;
	else

		return false;
}

/**
 * Metodo para comprobar si el balance cuadra al modificar
 */
bool Balance::cuadra(float importeStock, float importeRealizable,
		float importeDisponible, float importeANC, float importePC,
		float importePNC, float importePN) {
	float activo = importeStock + importeRealizable + importeDisponible
			+ importeANC;
	float pasivo = importePC + importePNC + importePN;
	if (activo == pasivo)

		return true;
	else

		return false;
}
/**
 * Mediante este metodo se calcularan los ratios
 */
void Balance::calcularRatios() {
	float exigible = this->importePC + this->importePNC;
	float AC = this->importeDisponible + this->importeRealizable
			+ this->importeStock;
	float endeudamiento = exigible / this->importePN;
	float solvencia = AC / this->importePC;
	float acid_test = (this->importeDisponible + this->importeRealizable)
			/ this->importePC;
	float liquidez = this->importeDisponible / this->importePC;

	cout << endl;
	cout << "RATIOS:" << endl;
	cout << endl;
	cout << "Endeudamiento:" << endeudamiento << endl;
	cout << "Solvencia:" << solvencia << endl;
	cout << "Acid test:" << acid_test << endl;
	cout << "Liquidez:" << liquidez << endl;
	cout << endl;
}
/**
 * Metodo para modificar los valores del balance. Llamara al metodo cuadra, para ver si cuadran el activo y el pasivo.
 */
void Balance::modificarBalance() {

	char opcion;
	bool cuadra = true;
	float importeStock, importeRealizable, importeDisponible, importeANC,
			importePC, importePNC, importePN;
	importePNC = this->importePNC;
	importeANC = this->importeANC;
	importePC = this->importePC;
	importeStock = this->importeStock;
	importeDisponible = this->importeDisponible;
	importeRealizable = this->importeRealizable;

	importePN = this->importePN;

	//do {
	do {

		cout << "Que quieres modificar del balance?" << endl;
		cout << " 1. Activo no corriente" << endl;
		cout << " 2. Stock" << endl;
		cout << " 3. Disponible" << endl;
		cout << " 4. Realizable" << endl;
		cout << " 5. Patrimonio neto" << endl;
		cout << " 6. Pasivo corriente" << endl;
		cout << " 7. Pasivo no corriente" << endl;
		cout << " a. GUARDAR CAMBIOS" << endl;
		cout << " c. CANCELAR" << endl;

		cout << "  Introduzca una opcion del 1-7:" << endl;

		cin >> opcion;
		cout << endl;
		switch (opcion) {
		case '1': {
			cout << "Introducir cantidad" << endl;
			cin >> importeANC;
			cout << endl;
		}
			break;
		case '2': {
			cout << "Introducir cantidad" << endl;
			cin >> importeStock;
			cout << endl;
		}
			break;
		case '3': {
			cout << "Introducir cantidad" << endl;
			cin >> importeDisponible;
			cout << endl;
		}
			break;
		case '4': {
			cout << "Introducir cantidad" << endl;
			cin >> importeRealizable;
			cout << endl;
		}
			break;
		case '5': {
			cout << "Introducir cantidad" << endl;
			cin >> importePN;
			cout << endl;
		}
			break;
		case '6': {
			cout << "Introducir cantidad" << endl;
			cin >> importePC;
			cout << endl;
		}
			break;
		case '7': {
			cout << "Introducir cantidad" << endl;
			cin >> importePNC;
			cout << endl;
		}
			break;
		case 'c': {
			cout << "Saliendo.." << endl;
			break;
		}
		case 'a': {
			cout << "Guardando.." << endl;
			if (!this->cuadra(importeStock, importeRealizable,
					importeDisponible, importeANC, importePC, importePNC,
					importePN)) {
				cout
						<< "El balance no cuadra. Por favor, introduce otra vez los datos:"
						<< endl;
				cuadra = false;
			} else {
				this->importeANC = importeANC;
				this->importeDisponible = importeDisponible;
				this->importePC = importePC;
				this->importePN = importePN;
				this->importePNC = importePNC;
				this->importeStock = importeStock;
				this->importeRealizable = importeRealizable;
				cuadra = true;
			}
		}
			break;
		default:
			cout << "Esa opcion no esta disponible" << endl;
			break;
		}
	} while (opcion != 'c' && (opcion != 'a' || cuadra == false));

	this->escribir_ficBin();
}
