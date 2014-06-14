struct nombreArchivo{
	string nombreAr<2048>;	
};
program SERVIDORWEB{
	version VER_SERVIDOR{
		string mostrarLista()=1;
		string mostrarCodigo(nombreArchivo)=2;
	}=1;

}=0x20000001;
