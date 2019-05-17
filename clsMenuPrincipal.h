/*
 * clsMenuPrincipal.h
 *
 *  Created on: 11/5/2019
 *      Author: ALUMNO
 */



#include "CuentaPyG.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Complemento.h"
using namespace complemento;
#include "Textil.h"
using namespace textil;
using namespace cliente;
using namespace proveedor;
#include <iostream>
using namespace std;

class clsMenuPrincipal
{
private:
	 Cliente* clientes;
	 Proveedor* proveedores;

public:
	void anyadirCliente();
	bool ComprobarClte(char*);
	bool ComprobarProv(char*);
	void menu(void);
	void imprimirTodosClientes();
	void Contabilizar_Ventatextil(Textil *textil, int cantidad);
	void VentaTextil( int tamanyo,Cliente * cliente);
	void Contabilizar_Ventacomplemento(Complemento *complemento, int cantidad);
	void ContabilizarVenta();
	void VentaComplemento( int tamanyo,Cliente * cliente);
	void imprimirTodosProveedores();
	void Contabilizar_complemento(Complemento *complemento, int cantidad);
	void Contabilizar_textil(Textil *textil, int cantidad);
	void compra();
	void anyadirProveedor();
	void imprimirProveedores();
	bool comprobar_complemento(char * codigo);
	void anyadirComplemento();
	bool comprobar_textil( char * codigo);
	void anyadirTextil();
	void imprimirTodosComplementos();
	void imprimirTodosTextiles();
};


