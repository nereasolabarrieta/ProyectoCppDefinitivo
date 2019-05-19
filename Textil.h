/*
 * Textil.h
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */

#ifndef TEXTIL_H_
#define TEXTIL_H_
#include "Articulo.h"
using namespace articulo;
namespace textil {
class Textil: public Articulo {
private:
	int stockXS;
	int stockS;
	int stockM;
	int stockL;
	char* color;


public:
	Textil();
	virtual ~Textil();
	int getStockXS() const;
	int getStockS() const;
	int getStockM() const;
	int getStockL() const;
	char* getColor() const;

	void setStockXS(int stockXS);
	void setStockS(int stockS);
	void setStockM(int stockM);
	void setStockL(int stockL);
	void setColor(char* color);

	void escribir_fic_bin_textil(Textil* t, int num_complementos);
	void LeerFic_bin_textil(Textil* t);

	virtual void Imprimir();
};
}

#endif /* TEXTIL_H_ */
