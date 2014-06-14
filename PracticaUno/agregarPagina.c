 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char const *argv[])
{
	
		char *buffer[1024];
        buffer[0] = "";
       
        // Abrimos el fichero.
        FILE *fichero = fopen ("Usuario/Pagina.html", "w");
        if (fichero == NULL) {
                printf( "error: abriendo el archivo." );
                
        }
       
        // Escribimos en el fichero.
        size_t len = strlen("sajdjas hdkh sd ");
        int resultado = fwrite ( "sajdjas hdkh sd ", 1, len, fichero);
        if (resultado != len) {
                printf("error: escribiendo el archivo.");
                
        }


	return 0;
}