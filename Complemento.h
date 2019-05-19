/*
 * Complemento.h
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */

#ifndef COMPLEMENTO_H_
#define COMPLEMENTO_H_
#include "Articulo.h"
using namespace articulo;
#include "Balance.h"
using namespace balance;
#include "Cliente.h"
using namespace cliente;
namespace complemento {
class Complemento: public Articulo {
private:
	int stock;


public:
	Complemento();
	virtual ~Complemento();

	int getStock() const;
	void setStock(int stock);

	void escribir_fic_bin_complementos(Complemento* c, int num_complementos);
	void LeerFic_bin_complementos(Complemento* c);
	virtual void Imprimir();
};
}

#endif /* COMPLEMENTO_H_ */
