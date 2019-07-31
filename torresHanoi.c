#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void *crearDiscos(int *arreglo,int tamanno){//llena el arreglo con int esto para saber el peso de los discos
    int i;
    int contador = tamanno;
    for(i=0; i <= tamanno ;i++){
        push(arreglo,contador);//hace push(mete)los pesos de los discos
        contador--;
    }
    return arreglo;
}
void *imprimirJuego(int *arregloA, int *arregloB, int *arregloC, int tamanno){
    int i,j,k,t,w;
    int p=tamanno;
    for(i=p; p != arregloA[i] ;i--){
        if(arregloA[tamanno]!=0){
            for(j=tamanno+1; j > 1 ;j--){//espacios para hacer el triangulo
                printf(" ");
            }
            for(k=-1;k < arregloA[tamanno]-1;k++){//es el tamanno de los discos
                printf("*");
            }
            for(k=0;k < p;k++){
                printf(" ");//es el tamanno de los discos
            }
        }else{//deja los espacios para que no se desordene los discos
            for(k=0;k < p*2;k++){
                printf(" ");
            }
        }
        if(arregloB[tamanno]!=0){
            for(t=tamanno+1; t > 1 ;t--){
                printf(" ");
            }
            for(w=-1;w < arregloB[tamanno]-1;w++){
                printf("*");//es el tamanno de los discos
            }
            for(k=-1;k < p-1;k++){
                printf(" ");
            }
        }else{//deja los espacios para que no se desordene los discos
            for(k=0;k < p*2;k++){
                printf(" ");
            }
        }
        if(arregloC[tamanno]!=0){
            for(t=tamanno+1; t > 1 ;t--){
                printf(" ");
            }
            for(w=-1;w < arregloC[tamanno]-1;w++){
                printf("*");//es el tamanno de los discos
            }
        }
        tamanno--;
        printf("\n");
    }
}
void *movimientos(int a, int b, int *arregloA, int *arregloB, int *arregloC){//valida todos los movimientos posibles para mover los discos
    if(a==1 & b==2){// mueve de A->B
        if(top(arregloA) <= top(arregloB)||arregloB[1]==0){//valida si se puede mover
            int valor = pop(arregloA);
            push(arregloB,valor);
        }
    }
    if(a==1 & b==3){// mueve de A->C
        if(top(arregloA) <= top(arregloC)||arregloC[1]==0){//valida si se puede mover
            int valor = pop(arregloA);
            push(arregloC,valor);
        }
    }
    if(a==2 & b==3){// mueve de B->C
        if(top(arregloB) <= top(arregloC)||arregloC[1]==0){//valida si se puede mover
            int valor = pop(arregloB);
            push(arregloC,valor);
        }
    }
    if(a==2 & b==1){// mueve de B->A
        if(top(arregloB) <= top(arregloA)||arregloA[1]==0){//valida si se puede mover
            int valor = pop(arregloB);
            push(arregloA,valor);
        }
    }
    if(a==3 & b==2){// mueve de C->B
        if(top(arregloC) <= top(arregloB)||arregloB[1]==0){//valida si se puede mover
            int valor = pop(arregloC);
            push(arregloB,valor);
        }
    }
    if(a==3 & b==1){// mueve de C->A
        if(top(arregloC) <= top(arregloA)||arregloA[1]==0){//valida si se puede mover
            int valor = pop(arregloC);
            push(arregloA,valor);
        }
    }
}
void gameover(int *arregloA,int *arregloB){
    if( arreglovacio(arregloA) == 0 & arreglovacio(arregloB) == 0 ){//valida si valor == tamanno entondes ya gano y se termina el juego
        printf("GAME OVER, YOU WIN!");
        system("clear");
    }
}
int main(){
    printf("Ingrese el numero de discos que desea: ");
    int opcion;
    int valor1=0;
    int valor2=0;
    int salir=0;
    scanf("%d", &opcion);//pide el tamanno de los arreglos
    opcion++;
    int *arregloA = crearpila(opcion);//pide memoria para guardar el largo o tamano del arreglo que necesaitamos
    int *arregloB = crearpila(opcion);//pide memoria para guardar el largo o tamano del arreglo que necesaitamos
    int *arregloC = crearpila(opcion);//pide memoria para guardar el largo o tamano del arreglo que necesaitamos
    crearDiscos(arregloA, opcion);//llena el arreglo de los discos par jugar
    push(arregloB,1);
    push(arregloC,1);
    imprimirJuego(arregloA,arregloB,arregloC,opcion);//imprime el juego inicial
    do{//Ciclo para jugar y preguntar a donde va a mover el disco
        printf("Digite la posicion");
        scanf("%d", &valor1);
        printf("Digite para donde desea mover");
        scanf("%d", &valor2);
        movimientos(valor1, valor2, arregloA, arregloB, arregloC);//valida los movimientos
        system("clear");//Limpia la consola
        imprimirJuego(arregloA,arregloB,arregloC,opcion);//imprime el juego
        gameover(arregloA, arregloB);
    }while(salir != 4);
};


