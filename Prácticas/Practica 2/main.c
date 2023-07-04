/* Main.c 
Funcion principal, en la cual se mandan a llamar a todas las funciones necesarias para que se ordene un arreglo
Fecha: 15/04/22
Autor: Santos M�ndez Ulises Jes�s
Version 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodos.h"
#include "tiempo.h"

/*main recibe dos argumentos, con el primero se selecciona el algoritmo que se desea usar para 
ordenar los números y el segundo indica la cantidad de numeros a ordenar.
*/

int main(int argc, char* argv[]){
	int n,algoritmo,x;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	if(argc!=4){
		printf("NO se recibieron los parametros necesarios\n");
		exit(0);
	}
	else{
		n=atoi(argv[1]);
		x=atoi(argv[2]);
		algoritmo=atoi(argv[3]);
	}
	int* numeros;
		numeros=malloc(n*sizeof(int));
	leerNumeros(n,numeros);
	//imprimir(numeros,n);
	uswtime(&utime0, &stime0, &wtime0);
	seleccionAlgortimo(algoritmo,numeros,n,x);
	uswtime(&utime1, &stime1, &wtime1);
	//imprimir(numeros,n);
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	
	
	printf("\n");
	printf("////////////////////////////////////////////////////////////////////////////////////////////\n");
	exit(0);
}
