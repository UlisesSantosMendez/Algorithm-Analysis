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

void seleccion(int* A, int n){
	int k,p,temp,i;
	for(k=0;k<n;k++){
		p=k;
		for(i=k+1;i<n-1;i++){
			if(A[i]<A[p]){
				p=i;
			}
		}
		temp=A[p];
		A[p]=A[k];
		A[k]=temp;
	}
}

