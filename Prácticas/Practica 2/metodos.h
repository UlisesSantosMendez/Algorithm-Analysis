#ifndef __METODOS_H__
#define __METODOS_H__

#include <stdio.h>
#include <stdlib.h>

int seleccionAlgortimo(int,int*, int, int );
int leerNumeros(int,int*);
int imprimir(int*,int);
int search(int*, int , int);
int binarySearch(int*, int , int , int );
int exponentialSearch(int*, int , int );
int min(int , int );
int fibMonaccianSearch(int*, int, int); 

struct abb{
    int dato; //guarda numeros del arbol
    struct abb *derecha, *izquierda; //genera las ramas iz, y derecha
};

struct abb* Nodo(int dato);
struct abb* insertar(struct abb* nodo, int dato);
void buscarABB(struct abb* root, int dato);
void inorder(struct abb* root);


#endif
