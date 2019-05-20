/*
 * clsMenuPrincipal.cpp
 *
 *  Created on: 11/5/2019
 *      Author: ALUMNO
 */

#include "Balance.h"
#include "clsMenuPrincipal.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Articulo.h"
#include "Textil.h"
#include "Complemento.h"
#include "CuentaPyG.h"
#include <iostream>
#include "string.h"
using namespace std;
using namespace balance;
using namespace cuentapyg;
using namespace cliente;
using namespace proveedor;
using namespace textil;
using namespace complemento;
const int NUM_PROV = 20;
const int NUM_CLIENTES = 100;
const int NUM_ARTIC = 30;

Cliente* cltes;
Proveedor* provs;
Balance *nuestro_balance;
CuentaPyG *cuentaPyG;
Complemento *complementos;
Textil *textiles;
char *a = new char[9];

/**
 * Se comprueba si existe el balance. Si no exite, llama al metodo para introducirlo, si existe, lee los ficheros Cliente, Proveedor, Complemento y Textil.
 * A continuacion, se muestra el menu.
 */
void clsMenuPrincipal::menu(void) {
	nuestro_balance = new Balance();
	cltes = new Cliente[NUM_CLIENTES];
	provs = new Proveedor[NUM_PROV];

	cuentaPyG = new CuentaPyG();
	complementos = new Complemento[NUM_ARTIC];
	textiles = new Textil[NUM_ARTIC];
	a="*********";

	if (!nuestro_balance->existsFile("Balance.dat")) {
		nuestro_balance->introducir();

	} else {
		if (nuestro_balance->existsFile("Clientes.txt")) {
			cltes->LeerFic_bin_clientes(cltes);
		}
		if (nuestro_balance->existsFile("Proveedores.txt")) {
			provs->leerFic_bin_proveedores(provs);
		}
		if (nuestro_balance->existsFile("Complementos.txt")) {
			complementos->LeerFic_bin_complementos(complementos);
		}
		if (nuestro_balance->existsFile("Textiles.txt")) {
			textiles->LeerFic_bin_textil(textiles);
		}
		if (nuestro_balance->existsFile("CuentaPyG.dat")) {
			cuentaPyG->leerFichero();
		}
		nuestro_balance->leerFichero();
	}

	char opcion;

	do {

		cout << "1. Introducir cliente" << endl;
		cout << "2. Introducir proveedor" << endl;
		cout << "3. Contabilizar venta" << endl;
		cout << "4. Contabilizar compra" << endl;
		cout << "5. Visualizar estado contable" << endl; //AnyADIR GASTOS Y INGRESOS A PYG
		cout << "6. Visualizar todos los clientes" << endl;
		cout << "7. Visualizar todos los proveedores" << endl;
		cout << "8. Visualizar todos los complementos" << endl;
		cout << "9. Visualizar todos los textiles" << endl;
		cout << "*. Editar balance" << endl;
		cout << "0. Salir" << endl;
		cout << endl;
		cout << "Introduzca una opcion del 0-*:" << endl;

		cin >> opcion;

		switch (opcion) {
		case '1':

			anyadirCliente();
			break;
		case '2':
			anyadirProveedor();
			break;
		case '3':
			ContabilizarVenta();
			break;
		case '4': {
			compra();
		}
			break;
		case '5':
			nuestro_balance->imprimirBalance();
			nuestro_balance->calcularRatios();
			cuentaPyG->imprimirCuentaPyG();
			break;
		case '6':
			imprimirTodosClientes();

			break;
		case '7':
			imprimirTodosProveedores();
			break;
		case '8':
			imprimirTodosComplementos();
			break;
		case '9':
			imprimirTodosTextiles();
			break;
		case '*':
			nuestro_balance->modificarBalance();
			break;
		case '0':

			delete[]cltes;
			delete[]provs;
			delete[]textiles;
			delete[]complementos;

			cout << "Agur" << endl;
			break;
		default:
			cout << "Esa opcion no esta disponible" << endl;

		}
	} while (opcion != '0');

}
/**
 * Pide los datos para anyadir un nuevo cliente
 */
void clsMenuPrincipal::anyadirCliente() {
	char *dni = new char[10];
	char *nom = new char[30];
	char *ape = new char[30];

	cin.ignore();
	cout << "Introduce NOMBRE: ";
	cin.getline(nom, 30);
	cout << endl;

	cout << "Introduce APELLIDO: ";
	cin.getline(ape, 30);
	cout << endl;

	cout << "Introduce DNI:";
	cin.getline(dni, 10);
	cout << endl;

	if (!ComprobarClte(dni)) {

		for (int i = 0; i < NUM_CLIENTES; i++) {

			if (((strcmp((cltes + i)->getDni(), a)) == 0)) {

				(cltes + i)->setNom(nom);
				(cltes + i)->setApe(ape);
				(cltes + i)->setDni(dni);
				cltes->escribirFic_bin_clientes(cltes, i + 1);
				return;
			}

		}
	}

}

/**
 * Metodo para comprobar si existe el cliente
 */
bool clsMenuPrincipal::ComprobarClte(char *dni) {

	for (int i = 0; i < NUM_CLIENTES; i++) {

		if ((strcmp(dni, (cltes + i)->getDni()) == 0)) {
			cout << "Este cliente ya esta registrado" << endl << endl;
			return true;
		}

	}

	return false;
}

/**
 * Metodo para imprimir todos los clientes
 */
void clsMenuPrincipal::imprimirTodosClientes() {
	bool existen_clientes = false;

	for (int i = 0; i < NUM_CLIENTES; i++)
	{

		if (((strcmp((cltes + i)->getDni(), a)) != 0))
		{
			(cltes + i)->imprimirCliente();
			existen_clientes = true;
		}
	}
	if (!existen_clientes) {
		cout << "No exiten clientes dados de alta" << endl;
		cout << endl;
	}
}

/**
 * Pide los datos para anyadir un nuevo proveedor y llama al metodo ComprobarProv para comprobar si existe.
 */
void clsMenuPrincipal::anyadirProveedor() {
	char *NIF = new char[10];
	char *nom = new char[30];

	cin.ignore();
	cout << "Introduce NOMBRE: ";
	cin.getline(nom, 30);
	cout << endl;

	cout << "Introduce NIF: ";
	cin.getline(NIF, 10);
	cout << endl;

	if (!ComprobarProv(NIF)) {

		for (int i = 0; i < NUM_PROV; i++) {

			if (((strcmp((provs + i)->getNIF(), a)) == 0)) {

				(provs + i)->setNom(nom);
				(provs + i)->setNIF(NIF);
				provs->escribirFic_bin_proveedores(provs, i + 1);
				return;

			}

		}
	}

}

/**
 * Metodo para comprobar si existe el proveedor introducido por el usuario.
 */
bool clsMenuPrincipal::ComprobarProv(char *NIF) {

	for (int i = 0; i < NUM_PROV; i++) {

		if ((strcmp(NIF, (provs + i)->getNIF()) == 0)) {
			cout << "Este proveedor ya esta registrado" << endl << endl;
			return true;
		}
	}

	return false;
}
/**
 * Metodo para imprimir todos los proveedores guardados.
 */
void clsMenuPrincipal::imprimirTodosProveedores() {
	for (int i = 0; i < NUM_PROV; i++) {

		if (!((strcmp((provs + i)->getNIF(), a)) == 0)) {

			(provs + i)->ImprimirProveedor();

			cout << endl;

		}
	}
}

/**
 * Metodo para realizar una compra.
 */
void clsMenuPrincipal::compra() {
	int opcion;

	do {

		cout << "Que tipo de articulo desea introducir?" << endl;
		cout << "1-Complemento" << endl;
		cout << "2-Textil" << endl;
		cout << "0-Cancelar" << endl;
		fflush(stdin);
		cin >> opcion;
		switch (opcion) {
		case 1:
			anyadirComplemento();
			break;
		case 2:
			anyadirTextil();
			break;
		case 0:
			cout << "Operacion cancelada" << endl;
			break;
		default:
			cout << "Esa opcion no existe." << endl;
		}
	} while (opcion != 1 && opcion != 2 && opcion != 0);

}

/**
 * Metodo para anyadir un complemento. LLama al metodo comprobar complemento para comprobar si existe.
 */
void clsMenuPrincipal::anyadirComplemento() {

	char *codigo = new char[10];
	char *nom = new char[30];
	cin.ignore();
	cout << "Introduce el codigo: " << endl;
	cin.getline(codigo, 10);
	cout << endl;

	if (comprobar_complemento(codigo)) {
		for (int i = 0; i < NUM_ARTIC; i++) {
			if (strcmp(((complementos + i))->getCodigo(), a) == 0) {

				cout << "Introduce el nombre:" << endl;
				cin.getline(nom, 30);
				cout << endl;

				float precio;
				cout << "Introduce el precio:" << endl;
				cin >> precio;
				cout << endl;

				int stock;
				cout << "Introduce stock" << endl;
				cin >> stock;
				cout << endl;
				cin.ignore();

				(complementos + i)->setCodigo(codigo);
				(complementos + i)->setNombre(nom);
				(complementos + i)->setPrecio(precio);
				(complementos + i)->setStock(stock);
				complementos->escribir_fic_bin_complementos(complementos,
						i + 1);
				Contabilizar_complemento((complementos + i), stock);

				break;
			}
		}

	} else {
		for (int i = 0; i < NUM_ARTIC; i++) {
			if (strcmp((complementos + i)->getCodigo(), codigo) == 0) {
				cout << "El articulo que ha comprado es el siguiente:" << endl;
				(complementos + i)->Imprimir();
				cout << "Cuantos articulos ha comprado?" << endl;

				int compra;
				cin >> compra;
				cout << endl;
				(complementos + i)->setStock(
						(complementos + i)->getStock() + compra);

				complementos->escribir_fic_bin_complementos(complementos,
						i + 1);
				Contabilizar_complemento((complementos + i), compra);

			}

		}
	}
	delete[] codigo;
	delete[] nom;
}
void clsMenuPrincipal::ContabilizarVenta() {
	bool existe = false;
	char *dni = new char[10];
	do {
		cout << "Introduce el DNI del cliente que ha realizado la compra:"
				<< endl;

		cin >> dni;
		cout << endl;

		for (int i = 0; i < NUM_CLIENTES; i++) {
			if (strcmp((cltes + i)->getDni(), dni) == 0) {
				cout
						<< "El cliente correspondiente a este DNI es el siguiente: "
						<< endl;
				(cltes + i)->imprimirCliente();
				existe = true;
				char opcion;
				do {

					cout << "Que tipo de venta desea contabilizar?" << endl;
					cout << "1-Complemento" << endl;
					cout << "2-Textil" << endl;
					cout << "0-Salir" << endl;
					cin.ignore();
					cin >> opcion;
					cout << endl;
					switch (opcion) {
					case '1':
						VentaComplemento(NUM_ARTIC, (cltes + i));
						cltes->escribirFic_bin_clientes(cltes, i + 1);
						break;
					case '2':
						VentaTextil(NUM_ARTIC, (cltes + i));
						cltes->escribirFic_bin_clientes(cltes, i + 1);
						break;
					case '0':
						cout << "Salir" << endl;
						break;
					default:
						cout << "Esa opcion no existe." << endl;
					}
				} while (!(opcion == '1' || opcion == '2' || opcion == '0'));
				break;
			}
		}
		if (existe == false) {
			cout << "No existe ningun cliente con ese DNI" << endl;
		}

	} while (existe == false);
	delete[] dni;

}
void clsMenuPrincipal::VentaTextil(int tamanyo, Cliente * cliente) {
	char *codigo = new char[10];
	int cantidadXS;
	int cantidadS;
	int cantidadM;
	int cantidadL;
	bool disponible = false;
	int TOTAL;
	do {
		cout << "Introduce el codigo del articulo:" << endl;

		cin >> codigo;
		cout << endl;

		if (comprobar_textil(codigo)) {

			cout << "No existe ningun complemento con ese codigo." << endl;

		} else {

			for (int i = 0; i < tamanyo; i++) {

				if (strcmp((textiles + i)->getCodigo(), codigo) == 0) {

					cout << "El articulo que ha vendido es el siguiente: "
							<< endl;

					(textiles + i)->Imprimir();

					do {
						cout << "Cuantos articulos de talla XS ha vendido?"
								<< endl;
						cin >> cantidadXS;
						cout << endl;

						if (((textiles + i)->getStockXS()) < cantidadXS) {
							cout
									<< "No tiene suficiente stock para realizar esa venta."
									<< endl;
							disponible = false;
						} else {
							(textiles + i)->setStockXS(
									(textiles + i)->getStockXS() - cantidadXS);
							disponible = true;

						}
					} while (disponible == false);
					do {
						cout << "Cuantos articulos de talla S ha vendido?"
								<< endl;
						cin >> cantidadS;
						cout << endl;

						if (((textiles + i)->getStockS()) < cantidadS) {
							cout
									<< "No tiene suficiente stock para realizar esa venta."
									<< endl;
							disponible = false;
						} else {
							(textiles + i)->setStockS(
									(textiles + i)->getStockS() - cantidadS);
							disponible = true;
						}
					} while (disponible == false);
					do {
						cout << "Cuantos articulos de talla M ha vendido?"
								<< endl;
						cin >> cantidadM;
						cout << endl;

						if (((textiles + i)->getStockM()) < cantidadM) {
							cout
									<< "No tiene suficiente stock para realizar esa venta."
									<< endl;
							disponible = false;
						} else {
							(textiles + i)->setStockM(
									(textiles + i)->getStockM() - cantidadM);
							disponible = true;

						}
					} while (disponible == false);
					do {
						cout << "Cuantos articulos de talla L ha vendido?"
								<< endl;
						cin >> cantidadL;
						cout << endl;

						if (((textiles + i)->getStockL()) < cantidadL) {
							cout
									<< "No tiene suficiente stock para realizar esa venta."
									<< endl;
							disponible = false;
						} else {
							(textiles + i)->setStockL(
									(textiles + i)->getStockL() - cantidadL);
							disponible = true;

						}
					} while (disponible == false);

					TOTAL = cantidadXS + cantidadS + cantidadM + cantidadL;
					textiles->escribir_fic_bin_textil(textiles, i + 1);

					textiles->enviarImporte((textiles + i)->getPrecio(), TOTAL,
							cliente);
					Contabilizar_Ventatextil((textiles + i), TOTAL);

				}

			}
			cout << "La venta se ha guardado correctamente" << endl;
		}

	} while (comprobar_textil(codigo));
	delete[] codigo;
}
void clsMenuPrincipal::Contabilizar_Ventatextil(Textil *textil, int cantidad) {
	float precio = textil->getPrecio();
	float cuantia = cantidad * precio;
	(nuestro_balance->setDisponible(nuestro_balance->getDisponible() + cuantia));
	(nuestro_balance->setStock(nuestro_balance->getStock() - cuantia));
	cuentaPyG->setIngresos(cuantia);
	cuentaPyG->escribir_fic();
	nuestro_balance->escribir_ficBin();

}
/**
 * Metodo para comprobar si existe el complemento introducido.
 */
bool clsMenuPrincipal::comprobar_complemento(char * codigo) {

	for (int i = 0; i < NUM_ARTIC; i++) {
		if (strcmp(((complementos + i))->getCodigo(), a) != 0) {
			if (strcmp(((complementos + i))->getCodigo(), codigo) == 0) {
				return false;
			}
		}
	}
	return true;
}
void clsMenuPrincipal::VentaComplemento(int tamanyo, Cliente * cliente) {

	char *codigo = new char[10];
	int cantidad;
	bool disponible = false;
	do {
		cout << "Introduce el codigo del complemento:" << endl;
		cin >> codigo;
		cout << endl;

		if (comprobar_complemento(codigo)) {

			cout << "No existe ningun complemento con ese codigo." << endl;

		} else {

			for (int i = 0; i < tamanyo; i++) {

				if (strcmp((complementos + i)->getCodigo(), codigo) == 0) {

					cout << "El articulo que ha vendido es el siguiente: "
							<< endl;

					(complementos + i)->Imprimir();

					do {
						cout << "Cuantos articulos ha vendido?" << endl;
						cin >> cantidad;

						if (((complementos + i)->getStock()) < cantidad) {
							cout
									<< "No tiene suficiente stock para realizar esa venta."
									<< endl;
							disponible = false;
						} else {
							(complementos + i)->setStock(
									(complementos + i)->getStock() - cantidad);
							complementos->escribir_fic_bin_complementos(
									complementos, i + 1);
							Contabilizar_Ventacomplemento((complementos + i),
									cantidad);
							disponible = true;
						}
						complementos->enviarImporte(
								(complementos + i)->getPrecio(), cantidad,
								cliente);
					} while (disponible == false);

				}

			}
			cout << "La venta se ha guardado correctamente" << endl;
		}

	} while (comprobar_complemento(codigo));
	delete[] codigo;

}

/**
 * Metodo para imprimir todos los complementos
 */
void clsMenuPrincipal::imprimirTodosComplementos() {

	for (int i = 0; i < NUM_ARTIC; i++) {

		if (!((strcmp((complementos + i)->getCodigo(), a)) == 0)) {

			(complementos + i)->Imprimir();

			cout << endl;

		}
	}
}
/**
 * Metodo para anyadir textil. LLama al metodo comprobar_texitil para comprobar si existe
 */
void clsMenuPrincipal::anyadirTextil() {
	char *codigo = new char[10];
	char *nom = new char[30];
	char *color = new char[20];

	cin.ignore();
	cout << "Introduce el codigo:" << endl;
	cin.getline(codigo, 10);
	cout << endl;

	if (comprobar_textil(codigo)) {
		for (int i = 0; i < NUM_ARTIC; i++) {

			if (strcmp((textiles + i)->getCodigo(), a) == 0) {

				cout << "Introduce el nombre:" << endl;
				cin.getline(nom, 30);
				cout << endl;

				float precio;
				cout << "Introduce el precio:" << endl;
				cin >> precio;
				cout << endl;

				int stockXS;
				cout << "Introduce stock de talla XS" << endl;
				cin >> stockXS;
				cout << endl;

				int stockS;
				cout << "Introduce stock de talla S" << endl;
				cin >> stockS;
				cout << endl;

				int stockM;
				cout << "Introduce stock de talla M" << endl;
				cin >> stockM;
				cout << endl;

				int stockL;
				cout << "Introduce stock de talla L" << endl;
				cin >> stockL;
				cout << endl;

				cin.ignore();
				cout << "Introduce color del articulo" << endl;
				cin.getline(color, 20);
				cout << endl;

				(textiles + i)->setCodigo(codigo);
				(textiles + i)->setNombre(nom);
				(textiles + i)->setPrecio(precio);
				(textiles + i)->setColor(color);
				(textiles + i)->setStockXS(stockXS);
				(textiles + i)->setStockS(stockS);
				(textiles + i)->setStockM(stockM);
				(textiles + i)->setStockL(stockL);

				textiles->escribir_fic_bin_textil(textiles, i + 1);
				int compra = stockXS + stockS + stockM + stockL;
				Contabilizar_textil((textiles + i), compra);

				break;
			}
		}

	} else {
		for (int i = 0; i < NUM_ARTIC; i++) {
			if (strcmp((*(textiles + i)).getCodigo(), codigo) == 0) {
				cout << "El articulo que ha comprado es el siguiente: " << endl;
				(textiles + i)->Imprimir();
				int compraXS;
				int compraS;
				int compraM;
				int compraL;

				cout << "Cuantos articulos ha comprado de la talla XS?" << endl;
				cin >> compraXS;
				cout << endl;

				cout << "Y de la talla S?" << endl;
				fflush(stdin);
				cin >> compraS;
				cout << endl;

				cout << "Y de la talla M?" << endl;
				cin >> compraM;
				cout << endl;

				cout << "Y de la talla L?" << endl;
				cin >> compraL;
				cout << endl;

				(textiles + i)->setStockXS((textiles + i)->getStockXS() + compraXS);
				(textiles + i)->setStockS((textiles + i)->getStockS() + compraS);
				(textiles + i)->setStockM((textiles + i)->getStockM() + compraM);
				(textiles + i)->setStockL((textiles + i)->getStockL() + compraL);
				textiles->escribir_fic_bin_textil(textiles, i + 1);

				int compra = compraXS + compraS + compraM + compraL;
				Contabilizar_textil((textiles + i), compra);

			}

		}
	}
	delete[] nom;
	delete[] codigo;
	delete[] color;
}
/**
 * Metodo para comprobar si existe el textil introducido
 */
bool clsMenuPrincipal::comprobar_textil(char * codigo) {

	bool unico = true;
	for (int i = 0; i < NUM_ARTIC; i++) {
		if (strcmp(((textiles + i))->getCodigo(), a) != 0) {
			if (strcmp(((textiles + i))->getCodigo(), codigo) == 0) {
				unico = false;
			}

		}
	}
	return unico;
}
/**
 * Metodo para imprimir todos los textiles
 */
void clsMenuPrincipal::imprimirTodosTextiles() {

	for (int i = 0; i < NUM_ARTIC; i++) {

		if (!((strcmp((textiles + i)->getCodigo(), a)) == 0)) {

			(textiles + i)->Imprimir();

			cout << endl;

		}
	}
}
void clsMenuPrincipal::Contabilizar_complemento(Complemento *complemento,
		int cantidad) {

	float precio = complemento->getPrecio();
	float cuantia = cantidad * precio;
	nuestro_balance->setPC(nuestro_balance->getPC() + cuantia);
	nuestro_balance->setStock(nuestro_balance->getStock() + cuantia);
	cuentaPyG->setGastos(cuantia);
	cuentaPyG->escribir_fic();
	nuestro_balance->escribir_ficBin();
}
void clsMenuPrincipal::Contabilizar_Ventacomplemento(Complemento *complemento,
		int cantidad) {

	float precio = complemento->getPrecio();
	float cuantia = cantidad * precio;
	(nuestro_balance->setDisponible(nuestro_balance->getDisponible() + cuantia));
	(nuestro_balance->setStock(nuestro_balance->getStock() - cuantia));
	cuentaPyG->setIngresos(cuantia);
	cuentaPyG->escribir_fic();
	nuestro_balance->escribir_ficBin();

}

void clsMenuPrincipal::Contabilizar_textil(Textil *textil, int cantidad) {
	float precio = textil->getPrecio();
	float cuantia = cantidad * precio;
	nuestro_balance->setPC(nuestro_balance->getPC() + cuantia);
	nuestro_balance->setStock(nuestro_balance->getStock() + cuantia);
	cuentaPyG->setGastos(cuantia);
	cuentaPyG->escribir_fic();
	nuestro_balance->escribir_ficBin();

}
