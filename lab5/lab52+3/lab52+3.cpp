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
                printf("Вершина %d: Обычная вершина \n", i);
            }
        }
    }

int main() {
    int vertices = 100;
    int rebra = (vertices * (vertices - 1)) / 2;
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
    printf("Мощность %d:\n",rebra);
    analyzeGraph(adjacencyMatrix, vertices);

    for (int i = 0; i < vertices; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);

    return 0;
}