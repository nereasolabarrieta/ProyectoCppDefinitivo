/*
 * Balance.h
 *
 *  Created on: 7 may. 2019
 *      Author: nereasolabarrieta
 */

#ifndef BALANCE_H_
#define BALANCE_H_
namespace balance {
class Balance {
private:
	float importeStock;
	float importeRealizable;
	float importeDisponible;
	float importeANC;
	float importePC;
	float importePNC;
	float importePN;

public:
	Balance();

	float getStock() const;
	float getRealizable() const;
	float getDisponible() const;
	float getANC() const;
	float getPC() const;
	float getPNC() const;
	float getPN() const;

	void setStock(float valor);
	void setRealizable(float valor);
	void setDisponible(float valor);
	void setANC(float valor);
	void setPC(float valor);
	void setPNC(float valor);
	void setPN(float valor);

	void introducir();
	bool existsFile(char*);
	void leerFichero();
	void escribir_ficBin();
	bool cuadra();
	bool cuadra(float importeStock, float importeRealizable,
			float importeDisponible, float importeANC, float importePC,
			float importePNC, float importePN);
	void calcularRatios();
	void imprimirBalance();
	void modificarBalance();

};
}

#endif /* BALANCE_H_ */
