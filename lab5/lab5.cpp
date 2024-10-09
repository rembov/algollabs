
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void printAdjacencyMatrix(int** matrix, int size) {
  

    for (int i = 0; i < size; i++) {
        
        for (int j = 0; j < size; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 10;
    srand(time(NULL)); 
    setlocale(LC_ALL, "Ru");
 
    if (vertices <= 0) {
        printf("Количество вершин должно быть больше 0.\n");
        return 1; 
    }

    int** adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    if (adjacencyMatrix == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }
    for (int i = 0; i < vertices; i++) {
        adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
        if (adjacencyMatrix[i] == NULL) {
            printf("Ошибка выделения памяти.\n");
    
            for (int k = 0; k < i; k++) {
                free(adjacencyMatrix[k]);
            }
            free(adjacencyMatrix);
            return 1;
        }
        for (int j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            adjacencyMatrix[i][j] = rand() % 2; 
            adjacencyMatrix[j][i] = adjacencyMatrix[i][j]; 
        }
    }

    printf("Матрица смежности:\n");
    printAdjacencyMatrix(adjacencyMatrix, vertices);

    for (int i = 0; i < vertices; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);

    return 0;
}
