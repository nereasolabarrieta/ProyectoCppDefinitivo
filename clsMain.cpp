/*
 * clsMain.cpp
 *
 *  Created on: 13 may. 2019
 *      Author: nereasolabarrieta
 */
#include "clsMenuPrincipal.h"

/**
 * Desde aqui se ejecuta el programa. Al ejecutar le pedira el balance que puede ser asi para que cuadre:
 * STOCK 1
 * REALIZABLE 2
 * DISPONIBLE 3
 * ACTIVO NO CORRIENTE 6
 * PASIVO NO CORRIENTE 6
 * PASIVO CORRIENTE 5
 * PATRIMONIO NETO 1
 */
int main(void) {
	clsMenuPrincipal *a = new clsMenuPrincipal();
	a->menu();
	return 0;
}

