/*
 * Articulo.h
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_
#include "Cliente.h"
using namespace cliente;
namespace articulo {
class Articulo {
private:
	char *codigo;
	char *nombre;
	float precio;

public:
	Articulo();
	virtual ~Articulo();

	char* getCodigo() const;
	char* getNombre() const;
	float getPrecio() const;

	void setCodigo(char* codigo);
	void setNombre(char* nombre);
	void setPrecio(float precio);
	virtual void Imprimir();
	void enviarImporte(float precio, int cantidad, Cliente * cliente);
};
}
#endif /* ARTICULO_H_ */
