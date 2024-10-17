#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 5  

void generateAdjacencyMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (i == j) {
                matrix[i][j] = 0; 
            }
            else {
                int randomEdge = rand() % 2;  
                matrix[i][j] = randomEdge;
                matrix[j][i] = randomEdge;  
            }
        }
    }
}

void printAdjacencyMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void adjacencyMatrixToList(int matrix[N][N], int adjacencyList[N][N], int degrees[N]) {
    for (int i = 0; i < N; i++) {
        degrees[i] = 0;
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                adjacencyList[i][degrees[i]] = j;
                degrees[i]++;
            }
        }
    }
}

void printAdjacencyList(int adjacencyList[N][N], int degrees[N]) {
    for (int i = 0; i < N; i++) {
        printf("Вершина %d: ", i);
        for (int j = 0; j < degrees[i]; j++) {
            printf("%d ", adjacencyList[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));  
    setlocale(LC_ALL, "RU");
    int matrix1[N][N], matrix2[N][N];
    int adjacencyList1[N][N], adjacencyList2[N][N];
    int degrees1[N], degrees2[N];  

    printf("Матрица смежности графа G1:\n");
    generateAdjacencyMatrix(matrix1);
    printAdjacencyMatrix(matrix1);

    printf("\nМатрица смежности графа G2:\n");
    generateAdjacencyMatrix(matrix2);
    printAdjacencyMatrix(matrix2);

    adjacencyMatrixToList(matrix1, adjacencyList1, degrees1);
    adjacencyMatrixToList(matrix2, adjacencyList2, degrees2);

    printf("\nСписок смежности графа G1:\n");
    printAdjacencyList(adjacencyList1, degrees1);

    printf("\nСписок смежности графа G2:\n");
    printAdjacencyList(adjacencyList2, degrees2);

    return 0;
}
