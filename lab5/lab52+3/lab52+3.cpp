#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void printAdjacencyMatrix(int** matrix, int size) {
    printf("   ");
    for (int i = 0; i < size; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("%2d ", i);
        for (int j = 0; j < size; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void findVertices(int** matrix, int size) {
    printf("Изолированные вершины: ");
    for (int i = 0; i < size; i++) {
        int isIsolated = 1; 
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {
                isIsolated = 0; 
                break;
            }
        }
        if (isIsolated) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Концевые вершины: ");
    for (int i = 0; i < size; i++) {
        int degree = 0;  
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {
                degree++;
            }
        }
        if (degree == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Доминирующие вершины: ");
    for (int i = 0; i < size; i++) {
        int isDominating = 1; 
        for (int j = 0; j < size; j++) {
            if (i != j && matrix[i][j] == 0) {
                isDominating = 0;  
                break;
            }
        }
        if (isDominating) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int vertices;
    float density;
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    vertices = rand() % 10 + 3;
    density = (float)rand() / RAND_MAX;

    int** adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if ((float)rand() / RAND_MAX < density) {
                adjacencyMatrix[i][j] = 1;
                adjacencyMatrix[j][i] = 1;
            }
        }
    }

    printf("Размер графа: %d\n", vertices);
    printf("Плотность графа: %.2f\n", density);
    printf("Матрица смежности:\n");
    printAdjacencyMatrix(adjacencyMatrix, vertices);
    findVertices(adjacencyMatrix, vertices);

    for (int i = 0; i < vertices; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);

    return 0;
}
