#include<stdio.h>
#include<stdlib.h>
//PROTOTIPOS DE FUNCION
int Producto2Mayores(int *,int n);

int main(int argc, char* argv[]){
	int *m1,n,contop,res;
	if (argc!=2) { //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
		printf("\nIndique el tamanio del algoritmo");
		exit(1);
	}
	else{ //Tomar el segundo argumento como tamaño del arreglo
		n=atoi(argv[1]);
	}
	m1=(int*)malloc(sizeof(int)*n);
	res=Producto2Mayores(m1,n);
	printf("El resultado es: %d",res);
	
	return 0;
}

int Producto2Mayores(int *A, int n){
	int mayor1,mayor2,i,totalop,j;
	int cuentacond=0;
	int cuentacond1=0;
	int cuentaasig=0;
	int numit=1000;
	for(j=0;j<numit;j++){
		if(A[0]>A[1]){
			mayor1=A[0];
			mayor2=A[1];
			cuentaasig=cuentaasig+2;
		}
		else{
			mayor1=A[1];
			mayor2=A[0];
			cuentaasig=cuentaasig+2;	
		}
		i=2;
		while(i<=n){
			cuentacond=1+n-2;
			
			if(A[i]>mayor1){
				mayor2=mayor1;
				mayor1=A[i];
				cuentaasig=cuentaasig+2;
			}
			else{
				cuentacond1=n-2;
				if(A[i]>mayor2){
					mayor2=A[i];
					cuentaasig=cuentaasig+1;
				}
			}
			i=i+1;
		}
		totalop=cuentacond+cuentaasig+cuentacond1;
	}
	
	return mayor1*mayor2;
	
}
