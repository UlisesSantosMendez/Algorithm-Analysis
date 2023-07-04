#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	int *numeros;
	if (argc!=2) { //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
		printf("\nIndique el tamanio del algoritmo");
		exit(1);
	}
	else{ //Tomar el segundo argumento como tamaño del arreglo
		n=atoi(argv[1]);
	}
	numeros=malloc(sizeof(int)*n);
	return 0;
}
void BurbujaSimple(int* A, int n){
	int i,j,aux;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(A[j]>A[j+1]){
				aux=A[j];
				A[j]=A[j+1];
				A[j+1]=aux;
			}
		}
	}	
}

