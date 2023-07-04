#include<stdio.h>

int main(){
	int n,j,i,cont=0;
	printf("Ingresa el valor de n: ");
	scanf("%d",&n);
	for(i=1;i<4*n;i*=2){
		for(j=i;j<5*n;j+=3){
			cont++;
			printf("%d.- Algoritmos\n",cont);
		}
	}
	return 0;
}

