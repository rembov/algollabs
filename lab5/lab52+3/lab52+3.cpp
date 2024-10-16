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

void printIncidenceMatrix(int** incidenceMatrix, int vertices, int edges) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < edges; j++) {
            printf("%2d ", incidenceMatrix[i][j]);
        }
        printf("\n");
    }
}


void analyzeGraph(int** matrix, int size) {
    printf("Анализ графа:\n");

    for (int i = 0; i < size; i++) {
        int degree = 0;
        for (int j = 0; j < size; j++) {
            degree += matrix[i][j];
        }

        if (degree == 0) {
            printf("Вершина %d: Изолированная вершина\n", i);
        }
        else if (degree == 1) {
            printf("Вершина %d: Конечная вершина\n", i);
        }
        else if (degree == size - 1) {
            printf("Вершина %d: Доминирующая вершина\n", i);
        }
        else {
            printf("Вершина %d: Обычная вершина\n", i);
        }
    }
}

int main() {
    
    srand(time(NULL));
    setlocale(LC_ALL, "Ru");
    int vertices = rand()/1000;


    int** adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    if (adjacencyMatrix == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }
    for (int i = 0; i < vertices; i++) {
        adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
        if (adjacencyMatrix[i] == NULL) {
            free(adjacencyMatrix);
            return 1;
        }
        for (int j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    int edgeCount = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            adjacencyMatrix[i][j] = rand() % 2;
            adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
            if (adjacencyMatrix[i][j] == 1) {
                edgeCount++;
            }
        }
    }

    printf("Матрица смежности:\n");
    printAdjacencyMatrix(adjacencyMatrix, vertices);
    int** incidenceMatrix = (int**)malloc(vertices * sizeof(int*));
    if (incidenceMatrix == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }
    for (int i = 0; i < vertices; i++) {
        incidenceMatrix[i] = (int*)malloc(edgeCount * sizeof(int));
        if (incidenceMatrix[i] == NULL) {
            free(incidenceMatrix);
            return 1;
        }
        for (int j = 0; j < edgeCount; j++) {
            incidenceMatrix[i][j] = 0;
        }
    }

    int rebra;

    int edgeIndex = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                incidenceMatrix[i][edgeIndex] = 1;
                incidenceMatrix[j][edgeIndex] = 1;
                edgeIndex++;
            }
        }
    }

    printf("Матрица инцидентности:\n");
    printIncidenceMatrix(incidenceMatrix, vertices, edgeCount);

    printf("Матрица смежности:\n");
    analyzeGraph(adjacencyMatrix, vertices);
    printf("Матрица инцидентности:\n");
    analyzeGraph(incidenceMatrix, vertices);
    rebra = ((vertices * (vertices - 1)) / 2);

    printf("Мощность: %d\n",rebra);
    for (int i = 0; i < vertices; i++) {
        free(adjacencyMatrix[i]);
        free(incidenceMatrix[i]);
    }
    free(adjacencyMatrix);
    free(incidenceMatrix);

    return 0;
}
