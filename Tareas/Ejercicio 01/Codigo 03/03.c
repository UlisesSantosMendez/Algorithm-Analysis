#include<stdio.h>

int main(){
	int n,j,i,k,cont=0;
	printf("Ingresa el valor de n: ");
	scanf("%d",&n);
	for(i=0;i<n*5;i+=2){
		for(j=0;j<2*n;j++){
			for(k=j;k<n;k++){
				cont++;
				printf("%d.- Algoritmos\n",cont);
			}
		}
	}
	return 0;
}

