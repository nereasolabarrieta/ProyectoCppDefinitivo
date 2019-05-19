/*
 * clsCliente.h
 *
 *  Created on: 5 may. 2019
 *      Author: nereasolabarrieta
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
namespace cliente {
class Cliente {
private:
	char *nom;
	char *ape;
	char *dni;
	float acumulado;

public:
	Cliente();

	~Cliente();

	char* getNom() const;
	char* getApe() const;
	char* getDni() const;
	float getAcumulado() const;

	void setNom(char* nom);
	void setApe(char* ape);
	void setDni(char* dni);
	void setAcumulado(float acumulado);

	void escribirFic_bin_clientes(Cliente *c, int num);
	void LeerFic_bin_clientes(Cliente *c);
	void introducirCliente();
	void imprimirCliente();

};
}
#endif /* CLIENTE_H_ */
