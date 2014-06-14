#include "listaWeb.h"

char **
mostrarlista_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	char *buffer[2048];
	size_t resultado;
    long lSize;


	printf("Mostrando Lista de Páginas Web\n");
	
	FILE *fichero;

	fichero =fopen("Archivos/listaPaginas.html", "r");
	
	if (fichero==NULL){
		result = "Es posible que el archivo no Exista verifique el nombre\nNo es necesario escribir la extencion";

	}else{
	
	    fseek(fichero,0,SEEK_END);
	    lSize = ftell(fichero);
	    rewind(fichero);

	    buffer[0] = (char*)malloc(sizeof(char)*lSize);

	    resultado = fread(buffer[0], 1, lSize, fichero);
		
		result = buffer[0];	

		fclose(fichero);

	}

	return &result;

	
}

char **
mostrarcodigo_1_svc(nombreArchivo *argp, struct svc_req *rqstp)
{
	
	static char * result;

	char *buffer[2048];
	size_t resultado;
    long lSize;
    char ruta[80] = "Archivos/";

    strcat(ruta, argp->nombreAr);
	FILE *fichero;

	printf("Código Web\n");
	

	fichero =fopen(ruta, "r");
	
	if (fichero==NULL){

	}else{
		
		fseek(fichero,0,SEEK_END);
	    lSize = ftell(fichero);
	    rewind(fichero);

	    buffer[0] = (char*)malloc(sizeof(char)*lSize);

	    resultado = fread(buffer[0], 1, lSize, fichero);
		
		result = buffer[0];	

		fclose(fichero);

	}
	return &result;


}
