/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "factorial.h"

int *
factorial_1_svc(fact *argp, struct svc_req *rqstp)
{
	static int  result;
	int numero;
	int miResultado;

	printf("Servidor en Linea \n");
	printf("El numero es %d \n", argp->numeroFactorial );

	numero = argp->numeroFactorial;
	miResultado = 1;

	while(numero>0){

		miResultado = miResultado * numero;
		numero = numero -1;
	}
	result = miResultado;

	printf("El resultado final es %d\n", result);

	return &result;
}