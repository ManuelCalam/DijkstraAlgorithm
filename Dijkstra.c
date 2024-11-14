#include <stdio.h>
#include <limits.h>

#define graphLenght 10

void main(){
    //int graphLenght = 10;
    int Infinito = INT_MAX;
    int minDistance[graphLenght] = {0, Infinito, Infinito, Infinito, Infinito, Infinito, Infinito, Infinito, Infinito, Infinito};
    int currentNode = 0;
    int visitedNode[graphLenght] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int previousNode[graphLenght] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    int graph[10][10] = {
    //   A  B  C  D  E  F  G  H  I  J
        {0, 3, 8, 5, 0, 0, 0, 0, 0, 0}, //A
        {3, 0, 5, 0, 0, 7, 0, 0, 0, 0}, //B
        {8, 5, 0, 2, 8, 5, 0, 0, 0, 0}, //C
        {5, 0, 2, 0, 0, 0, 4, 0, 0, 0}, //D
        {0, 0, 8, 0, 0, 5, 6, 1, 3, 0}, //E
        {0, 7, 5, 0, 5, 0, 0, 6, 0, 0}, //F
        {0, 0, 0, 4, 6, 0, 0, 0, 4, 0}, //G
        {0, 0, 0, 0, 1, 6, 0, 0, 0, 2}, //H
        {0, 0, 0, 0, 3, 0, 4, 0, 0, 6}, //I
        {0, 0, 0, 0, 0, 0, 0, 2, 6, 0}, //J
    };

    //goToNextNode

    do{
        if (visitedNode[0] == 0){
            visitedNode[0] = 1;
            currentNode = 0;
        }

        // Buscar las conexiones vecinas a partir de la matriz
        int smallerNumber = 0;
        int smallerNumberPos = 0;
        int accumulatedDistance;
        for(int i = 0; i<graphLenght; i++){
            //Actualizar el array con distancias acumuladas
            accumulatedDistance = (minDistance[currentNode] + graph[currentNode][i]);
            if(graph[currentNode][i] != 0){
                if(accumulatedDistance < minDistance[i]){
                    minDistance[i] = accumulatedDistance;
                    previousNode[i] = currentNode;
                }
            }
            printf("%d, ", minDistance[i]);
        }

        smallerNumber = Infinito;
        for (int i = 0; i < graphLenght; i++)
        {
            if(visitedNode[i]==0){
                if(minDistance[i] < smallerNumber){
                    smallerNumber = minDistance[i];
                    smallerNumberPos = i;
                }
            }
        }

        printf("\nNumero menor: %d en la posicion: %d \n", smallerNumber, smallerNumberPos);


        //Cambiar a mejor ruta
        currentNode = smallerNumberPos;
        visitedNode[smallerNumberPos] = 1;

        //printf("\nCurrent Node: %d\n", currentNode);
    }while(visitedNode[graphLenght-1] == 0);

    printf("\nDistancias finales desde el nodo 0:\n");
    for (int i = 0; i < graphLenght; i++) {
        printf("Distancia a %c: %d\n", 'A' + i, minDistance[i]);
    }


    int destination = graphLenght-1;
    int path[graphLenght]; //
    int pathIndex = 0;

    // Retrocede desde el nodo de destino
    while (destination != -1) {
        path[pathIndex++] = destination;
        destination = previousNode[destination]; // Mueve al nodo anterior
    }

    // Imprime el camino en orden inverso
    printf("Ruta mas corta: ");
    for (int i = pathIndex - 1; i >= 0; i--) {
        printf("%c ", 'A' + path[i]);
    }

}
