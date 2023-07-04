/* Metodos.c 
Incluye todas las funciones utilizadas en el main.c y para ordenar el arreglo de numeros, asi mismo contiene los algoritmos para el ordenamiento.
*/
#include "metodos.h"

int indice=-1;

/*SeleccionAlgoritmo recibe dos parametros, el primero incica el algoritmo a utilizar y elsegundo la cantidad de numeros a ordenar.
Descricion de funcionamiento: se compara el primer parametro que se recibe para seleccionar el algoritmo a utilizar y una vez que se encuentra la opcion, se llama la funcion del algoritmo y se le pasa los parametros para comenzar a ordenar.
Error: Se produce un error cuando el numero para seleccionar el algortmo a utilizar es invalido.*/

int seleccionAlgortimo(int algoritmo,int* numeros, int n, int x){
	
	int res=0;

	if(algoritmo==1){
		res=search(numeros,x,n);
		printf("Algoritmo: Busqueda Lineal\n	numero a buscar=%d\n",n);
		if(res>=0)
    		printf("\n Encontrado... ");
  		else
    		printf("\n No encontrado...");
	}
	else if(algoritmo==2){
		struct abb *arbol = NULL;
		for(int i=0; i<n; i++){arbol = insertar(arbol, numeros[i]);}
		buscarABB(arbol,n);
		printf("Algoritmo: Busqueda Binaria Arbol\n 	numero a buscar=%d\n",n);
		if(res>=0)
    		printf("\n Encontrado... ");
  		else
    		printf("\n No encontrado...");

	}else if(algoritmo==3){
		res=binarySearch(numeros,0,x-1,n);
		printf("Algoritmo: Busqueda Binaria\n	numero a buscar=%d\n",n);
		if(res>=0)
    		printf("\n Encontrado... ");
  		else
    		printf("\n No encontrado...");
	}
	else if(algoritmo==4){
		res=exponentialSearch(numeros,x,n);
		printf("Algoritmo: Busqueda Exponencial\n	numero a buscar=%d\n",n);
		if(res>=0)
    		printf("\n Encontrado... ");
  		else
    		printf("\n No encontrado...");
	}
	else{
		res=fibMonaccianSearch(numeros, n, x);
		printf("Algoritmo: Busqueda Fibonacci\n	numero a buscar=%d\n",n);
		if(res>=0)
    		printf("\n Encontrado... ");
  		else
    		printf("\n No encontrado...");
	}
	
	return 0;
}

/* leerNumeros recibe dos parametros, n que es la cantidad de numeros a ordenar y un apuntador a un arreglo en el cual se van a almacenar los numeros leidos
Descipcion de funcionamiento: con un for se leen los numero contenidos en el archivo y asi se les asigna un lugar en el arreglo.
*/

int leerNumeros(int n,int* numeros){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&numeros[i]);
	}
	return 0;
}

/*imprimir recibe dos parametros un apuntador al arreglo que contiene los numeros y la cantidad de numeros que contiene este arreglo, asi impime el contenido del arreglo
Descripcion de funcionamiento: Con ayuda de un for se van imprimiento todos los numeros que cotiene el arreglo.*/
int imprimir(int* numeros,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d \n",numeros[i]);	
	}
	return 0;
}

/*search recibe tres parametros un apuntador al arreglo que contiene los numeros, el numer a buscar y el tamano de n
Descripcion de funcionamiento: Con ayuda de un for se van buscando el numeroen todos los numeros que cotiene el arreglo.*/
int search(int* numeros, int x, int n)
{
    int i;
    for (i = 0; i < x; i++)
        if (numeros[i] == n)
            return i;
    return -1;
}

/*binarysearch recibe cuatro parametros un apuntador al arreglo que contiene los numeros, el numer a buscar y los numero de ambos lados
Descripcion de funcionamiento: Con ayuda de un for se van buscando el numeroen todos los numeros que cotiene el arreglo.*/
int binarySearch(int* numeros, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (numeros[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (numeros[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}

/*search recibe tres parametros un apuntador al arreglo que contiene los numeros, el numer a buscar y el tamano de n
Descripcion de funcionamiento: Con el while se obtiene la mitad para hacer llamado a la funcion searchbinary
 .*/
int exponentialSearch(int* numeros, int x, int n)
{
    // If x is present at first location itself
    if (numeros[0] == n)
        return 0;
 
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < x && numeros[i] <= n)
        i = i*2;
 
    //  Call binary search for the found range.
    return binarySearch(numeros, i/2, min(i, x-1), n);
}

/*search recibe dos parametros que son dos numeros
Descripcion de funcionamiento: Con ayuda de la funcion min obtiene el numero menor de ambos.*/
int min(int x, int y) 
{ 
	return (x <= y) ? x : y; 
}
 
/*search recibe tres parametros un apuntador al arreglo que contiene los numeros, el numer a buscar y el tamano de n
Descripcion de funcionamiento: Con ayuda de un for se van buscando el numeroen todos los numeros que cotiene el arreglo.*/ 
/* Returns index of x if present,  else returns -1 */
int fibMonaccianSearch(int* numeros, int x, int n)
{
    /* Initialize fibonacci numbers */
    int fibMMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci
 
    /* fibM is going to store the smallest Fibonacci
       Number greater than or equal to n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
 
    // Marks the eliminated range from front
    int offset = -1;
 
    /* while there are elements to be inspected. Note that
       we compare arr[fibMm2] with x. When fibM becomes 1,
       fibMm2 becomes 0 */
    while (fibM > 1) {
        // Check if fibMm2 is a valid location
        int i = min(offset + fibMMm2, n - 1);
 
        /* If x is greater than the value at index fibMm2,
           cut the subarray array from offset to i */
        if (numeros[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
 
        /* If x is greater than the value at index fibMm2,
           cut the subarray after i+1  */
        else if (numeros[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 
        /* element found. return index */
        else
            return i;
    }
 
    /* comparing the last element with x */
    if (fibMMm1 && numeros[offset + 1] == x)
        return offset + 1;
 
    /*element not found. return -1 */
    return -1;
}

/* Funcion para crear un nuevo nodo */
struct abb* nuevoNodo(int dato){
	//Asignamos memoria al nuevo nodo
    struct abb* nuevo = (struct abb*)malloc(sizeof(struct abb));
    nuevo->dato = dato; //Asignamos el nodo
    nuevo->derecha = nuevo->izquierda = NULL; //Apuntamos a nulo el sub arbol derecho e izquierdo
    return nuevo; //Retornamos el nuevo nodo
}

/* Funcion para insertar un nuevo nodo al arbol */
struct abb* insertar(struct abb* nodo, int dato){

    struct abb *aux = nodo; //variable auxiliar para ir recorriendo el abb
	int i=1; //variable pde control para el while
	
    if(aux == NULL)
        return nuevoNodo(dato); //Creamos el nodo

	//Ciclo while para hacer iterativo el algoritmo
    while(i){

	
        if(dato < aux->dato)
            if(aux->izquierda == NULL){
                aux->izquierda = nuevoNodo(dato);
				i = 0; //para terminar el while
			} else aux = aux->izquierda;
        else if (dato > aux->dato){
        	if(aux->derecha == NULL){
                    aux->derecha = nuevoNodo(dato);
					i = 0; //para terminar el while
			} else aux = aux->derecha;
        }
    }


    return nodo; 
}

/* Funcion que hace un recorrido por el arbol en busca del dato que se busca */
void buscarABB(struct abb* root, int dato){
    while(root != NULL){
	
        if(root->dato < dato)
            root = root->derecha;
		else if(root->dato > dato)
            root = root->izquierda;   
			else{
				break;
			}
    }

}

/* Funcion para recorrido inorder */
void inorder(struct abb* root){
	if(root != NULL){
		inorder(root->izquierda);
		printf("%d \n", root->dato);
		inorder(root->derecha);
	}
}