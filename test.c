#include <stdio.h>
#include "libreria.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
int main ( int argc, char *argv[]){
	//Número de líneas pedidas
	int n;
	//Comprueba el número de argumentos
	if(argc>3 || argc==1){
		fprintf(stderr,"Error.Número incorrecto de argumentos. Uso %s función [int]\n",argv[0]);
		return 1;
	}
	else{
		//Pone el valor por defecto
		if(argc==2){
			n=10;
		}
		//Guarda N y comprueba si es un entero
		else {
			n= atoi(argv[2]);
			if(n==0){
				fprintf(stderr,"Error. Argumentos incorrectos. Uso: %s funcion [int]\n",argv[0]);
			}
		}
		//LLama a la función deseada
		if(strcmp(argv[1],"head")==0){
				head(n);
		}
		else if(strcmp(argv[1],"tail")==0){
                                tail(n);
                }
		else if(strcmp(argv[1],"longlines")==0){
                                longlines(n);
      		}
		else{
			fprintf(stderr,"Error, no se encuentra la función\n");
			return 1;
		}
	}

return 0;
}
