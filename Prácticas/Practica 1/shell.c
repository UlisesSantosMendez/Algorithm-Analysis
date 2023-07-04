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

void shell(int* A, int n){
	int k,p,temp,i;
	k=n/2;
	while(k>=1){
		b=1;
		while(b!=0){
			b=0;
			for(i=k;i<n-1;i++){
				if(A[i-k]>A[i]){
					temp=A[i];
					A[i]=A[i-k];
					A[i-k]=temp;
					b++;
				}
			}
		}
		k/=2;
	}
}
