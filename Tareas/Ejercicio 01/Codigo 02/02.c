#include<stdio.h>

int main(){
	int n,j,i,cont=0;
	printf("Ingresa el valor de n: ");
	scanf("%d",&n);
	for(j=n;j>1;j/=2){
		if(j<(n/2)){
			for(i=0;i<n;i+=2){
				cont++;
				printf("%d.- Algoritmos\n",cont);
			}
		}
	}
	return 0;
}

