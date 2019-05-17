/*
 * CuentaPyG.h
 *
 *  Created on: 7 may. 2019
 *      Author: nereasolabarrieta
 */

#ifndef CUENTAPYG_H_
#define CUENTAPYG_H_
namespace cuentapyg
{
class CuentaPyG
{
private:
	float ingresos;
	float gastos;
	float resultado;

public:
	CuentaPyG();
	void leerFichero();
	void imprimirCuentaPyG();
	float getGastos() const;
	float getIngresos() const;
	void setGastos(float valor);
	void setIngresos(float valor);
	void escribir_fic();

	};
}




#endif /* CUENTAPYG_H_ */
