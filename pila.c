#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
//#include <>

int *crearpila(int elemento){
    int *arreglo = (int*)calloc(elemento, sizeof(int)*elemento);//da la memoria al arreglo, y calloc llena el arreglo con 0ros
    return arreglo;//regresa el arreglo
}
int arreglovacio(int *arreglo){//si arreglo vacio
    if(arreglo[1] == 0){
        return 0;
    }else{
        return 1;
    }
}
void push(int *arreglo,int valor){//mete en la ultima pos un valor int
    int i;
    for(i=0;arreglo[i]!=0 ;i++);
    arreglo[i]=valor;
}


int pop(int *arreglo){//saca un valor y en la pos le mete un 0
    int i;
    int ultimo;
    int esVacio;
    esVacio = arreglovacio(arreglo);
    if(esVacio != 0){
        for(i=0;arreglo[i+1]!=0 ;i++);
        ultimo = arreglo[i];
        arreglo[i] = 0;
        return ultimo;
    }else{
        return 0;
    }
}

int top(int *arreglo){//muestra el ultimo valor del arreglo
    int i;
    int ultimo;
    for(i=0;arreglo[i+1]!=0 ;i++);
    ultimo = arreglo[i];
    return ultimo;

}
