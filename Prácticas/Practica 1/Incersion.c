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
void Insercion(int* A, int n){
	int i,n,j,temp;
	for(i=0;i<n-1;i++){
		j=i-1;
		temp=A[i];
		while((j>0) && (temp<A[j-1])){
			A[j]=A[j-1];
			j--;
		}
		A[j]=temp;
	}
}
