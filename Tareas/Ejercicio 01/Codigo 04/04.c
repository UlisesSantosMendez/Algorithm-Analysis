#include<stdio.h>

int main(){
	int n,j,i,cont=0;
	printf("Ingresa el valor de n: ");
	scanf("%d",&n);
	i=n;
	while(i>=0){
		for(j=n;i<j;i-=2,j/=2){
			cont++;
			printf("%d.- Algoritmos",cont);
		}
	}
	return 0;
}

