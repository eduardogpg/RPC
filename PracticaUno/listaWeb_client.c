#include "listaWeb.h"
#include <stdio.h>
#include <stdlib.h> 

void crearEjecutarArchivo( char *nombre, char *mensaje){
	
 		char *buffer[1024];
        buffer[0] = "";
       	
       	char ruta[80] ="/var/www/html/"; 
       	strcat(ruta,nombre);
        FILE *fichero = fopen (ruta, "w");
       
        size_t len = strlen(mensaje);
        int resultado = fwrite (mensaje, 1, len, fichero);
       
        fclose (fichero);
        return;
}

void ejecutarPaginaWeb(char *nombre){

	char comando[80] = "sudo firefox localhost/";
	strcat(comando, nombre);
	printf("%s\n",comando );
	system("cd /var/www/html/");
	system(comando);
	return;
}
void creditos(void){
	printf ("García Pérez Eduardo Ismael 113015\n");
	printf ("Carlos Alberto Ruiz Robles 121002\n");
	printf ("Ingenieria Desarrollo Software");
	printf ("\n15 de Mayo 2014");
	printf ("\nPractica Numero Uno");
	printf ("\nJuan Carlos López Pimentel");
	printf ("\nPractica RGP");


	printf ("\n\nSe pueden observar los creditos más a detalle en la página web\nOpcion número dos");
	printf("\n______________\n\n");
	return;
}

void
servidorweb_1(char *host)
{
	CLIENT *clnt;
	char * *result_1;
	char *mostrarlista_1_arg;
	char * *result_2;
	nombreArchivo  mostrarcodigo_1_arg;
	
	int bandera;
	int opcion;
	bandera = 0;

#ifndef	DEBUG
	clnt = clnt_create (host, SERVIDORWEB, VER_SERVIDOR, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */



	while (bandera == 0){
		printf("\nOpciones : \n");
		printf("1-Mostra lista páginas\n");
		printf("2-Ver código fuente \n");
		printf("3-Creditos\n");
		printf("4-salir\n");

		printf("\nOpcion : ");
		scanf("%d", &opcion);

		if (opcion == 4 )
			bandera = 1;
		else if (opcion == 3){
			system("clear");
			creditos();

		}else if(opcion == 1){
			
			system("clear");
			result_1 = mostrarlista_1((void*)&mostrarlista_1_arg, clnt);
			if (result_1 == (char **) NULL) {
				printf("El sevidor no se encuentra en linea \n");
				bandera= 1;
			}else{
				printf("La lista contiene :\n\n%s", *result_1);
				printf("\n______________\n\n");
			}

		}else if(opcion == 2){
			system("clear");
			
			result_1 = mostrarlista_1((void*)&mostrarlista_1_arg, clnt);
			if (result_1 == (char **) NULL) {
				printf("El sevidor no se encuentra en linea \n");
				bandera = 1;
			}else{
				printf("Opciones  :\n\n%s", *result_1);
				printf("\n______________\n\n");
			}

			char fichero[80]; 
		
			printf ("Coolocar el nombre del fichero: ");
			scanf ("%s", fichero); 
			
			strcat(fichero, ".php");
			mostrarcodigo_1_arg.nombreAr = fichero;

			result_2 = mostrarcodigo_1(&mostrarcodigo_1_arg, clnt);
			if (result_2 == (char **) NULL) {
				printf("El posible que el archivo no exista (No es necesario colocar la extencion) \n");
			}else{
				system("clear");
				printf("El código es :\n");
				printf("%s\n", *result_2 );
				
				crearEjecutarArchivo(fichero, *result_2);
				ejecutarPaginaWeb(fichero);

			  	printf("\n______________\n\n");
		        
			}

		}
		else
			bandera = 1;
	} 

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	servidorweb_1 (host);
exit (0);
}
