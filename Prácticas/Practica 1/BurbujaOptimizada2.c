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
void BurbujaOptimizada2(int* A, int n){
	int i=0,j,aux,cambios=1;
	while(i<n && cambios!=0){
		cambios=0;
		for(j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]){
				aux=A[j];
				A[j]=A[j+1];
				A[j+1]=aux;
				cambios=1;
			}
		}
		i=i+1;
	}
}

