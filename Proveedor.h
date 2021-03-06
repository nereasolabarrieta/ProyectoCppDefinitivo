/*
 * Proveedor.h
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */

#ifndef PROVEEDOR_H_
#define PROVEEDOR_H_
namespace proveedor {
class Proveedor {
private:
	char* nom;
	char* NIF;

public:
	Proveedor();
	~Proveedor();

	char* getNom();
	char* getNIF();

	void setNom(char* nom);
	void setNIF(char* NIF);

	void escribirFic_bin_proveedores(Proveedor* p, int num_proveedores);
	void leerFic_bin_proveedores(Proveedor *p);
	void ImprimirProveedor();

};
}

#endif /* PROVEEDOR_H_ */
