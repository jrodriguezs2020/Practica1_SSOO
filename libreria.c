#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int head (int n) {
	//Variable que cuenta el número de líneas leídas
	int i = 0;
	//Variable que contiene la línea leída
	char linea[1024];
	//Muestra las líneas leídas hasta N o llegar a EOF
	while ((i<n) && (fgets(linea,1024,stdin) != NULL)) {
		fprintf(stdout,"%s",linea);
		i++;
	}

	return 0;
}


int tail (int n) {
	//Cuenta las líneas leídas hasta N
        int i = 0;
	//COntiene la línea leída
        char linea[1024];
	//Guarda todas las líneas necesarias
        char **a = (char **) malloc(n*sizeof(linea));
	//Sigue leyendo hasta llegar a un EOF
	 while (fgets(linea,1024,stdin) != NULL) {
		//Si se han leído menos de N se guarda la línea
		if (i<n) {
                	a[i] = strdup(linea);
                	i++;
		}
		else {
			//Libera la primera línea y muevo una posición
			free(a[0]);
			for (int j=0; j<n-1; j++) {
				a[j] = a[j+1];
			}
			a[n-1] = strdup(linea);
		}
        }
	//Muestra todas las líneas guardadas
        for (int k=0; k<i; k++) {
                fprintf(stdout,"%s",a[k]);
        }
	//Libera memoria
        for (int x=0; x<n; x++) {
                        free(a[x]); 
        }
	free(a);
	return 0;
}


int longlines (int n) {
	//Cuenta las líneas léidas hasta N
        int i = 0;
	//Itera hasta encontrar la posición donde guardará la línea
	int j;
	//Variable auxiliar para diferenciar entre si está lleno o no
	int aux;
	//Contiene la línea leída
        char linea[1024];
	//Guarda las líneas 
        char **a = (char **) malloc(n*sizeof(linea));
	//Sigue leyendo hasta EOF
        while (fgets(linea,1024,stdin) != NULL) {
		//Si es la primera línea leído se guarda
                if (i==0) {
			a[i] = strdup(linea);
		}
		else {
			//Comprueba que se debe guardar la línea
			if (i<n || strlen(a[i-1])<strlen(linea)) { 
				j = 0;
				//Busca la posición donde colocar la nueva línea
				while (j<i) {
					if (strlen(a[j])<strlen(linea)) {
						if (i<n) {
							aux = i;
						}
						else {
							aux = n-1;
							free(a[n-1]);
						}
						//Modifico las posiciones
						for (int z=aux; z>j; z--) {
							a[z] = a[z-1];
						}
						a[j] = strdup(linea);
						break;
					}
					j++;
				}
				//Caso que no este lleno y la línea leída se de menor longitud
				if (j==i) {
					a[i] = strdup(linea);
				}
			}
		}
		if (i<n) {
			i++;
		}
        }

	//Muestra las líneas guardadas
        for (int k=0; k<i; k++) {
                fprintf(stdout,"%s",a[k]);
        }
	//Libera memoria
        for (int x=0; x<n; x++) { 
                        free(a[x]);
        }
	free(a);
	return 0;

}
