﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 10
void generateMatrix(int matrix[N][N]) {
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
void printMatrix(int matrix[N][N]) {
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
void mergeVerticesMatrix(int matrix[N][N], int a, int b) {
    for (int i = 0; i < N; i++) {
        matrix[a][i] |= matrix[b][i];
        matrix[i][a] = matrix[a][i];
    }
    matrix[a][a] = 0;
}
void splitVertexMatrix(int matrix[N][N], int a) {
    if (a >= N - 1) {
        printf("Невозможно расщепить вершину. Недостаточно вершин.\n");
        return;
    }
    int new_vertex = a + 1;
    for (int i = 0; i < N; i++) {
        if (matrix[a][i] == 1) {
            matrix[new_vertex][i] = 1;
            matrix[i][new_vertex] = 1;
            matrix[a][i] = 0;
            matrix[i][a] = 0;
        }
    }
}
void mergeVerticesList(int adjacencyList[N][N], int degrees[N], int a, int b) {
    for (int i = 0; i < degrees[b]; i++) {
        int neighbor = adjacencyList[b][i];
        int found = 0;
        for (int j = 0; j < degrees[a]; j++) {
            if (adjacencyList[a][j] == neighbor) {
                found = 1;
                break;
            }
        }
        if (!found) {
            adjacencyList[a][degrees[a]++] = neighbor;
        }
    }
    degrees[b] = 0;
}

void deleteVertexMatrix(int matrix[N][N], int vertex) {
    if (vertex >= N) {
        printf("Некорректный номер вершины для удаления.\n");
        return;
    }
    for (int i = vertex; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = matrix[i + 1][j];
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = vertex; j < N - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
 
    for (int i = 0; i < N; i++) {
        matrix[N - 1][i] = 0;
        matrix[i][N - 1] = 0;
    }
}
void deleteVertexList(int adjacencyList[N][N], int degrees[N], int vertex) {
    if (vertex >= N) {
        printf("Некорректный номер вершины для удаления.\n");
        return;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < degrees[i]; j++) {
            if (adjacencyList[i][j] == vertex) {
                
                for (int k = j; k < degrees[i] - 1; k++) {
                    adjacencyList[i][k] = adjacencyList[i][k + 1];
                }
                degrees[i]--;
                j--;
            }
            else if (adjacencyList[i][j] > vertex) {
 
                adjacencyList[i][j]--;
            }
        }
    }
 
    degrees[vertex] = 0;
}


void splitVertexList(int adjacencyList[N][N], int degrees[N], int a) {
    if (degrees[a] == 0) return;
    int new_vertex = degrees[a];
    degrees[new_vertex] = 0;
    for (int i = 0; i < degrees[a]; i++) {
        adjacencyList[new_vertex][degrees[new_vertex]++] = adjacencyList[a][i];
    }
    degrees[a] = 0;
}
void unionGraphsMatrix(int result[N][N], int matrix1[N][N], int matrix2[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] | matrix2[i][j];
        }
    }
}
void intersectionGraphsMatrix(int result[N][N], int matrix1[N][N], int matrix2[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] & matrix2[i][j];
        }
    }
}
void ringSumGraphsMatrix(int result[N][N], int matrix1[N][N], int matrix2[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] ^ matrix2[i][j];
        }
    }
}
void cartesianProductGraphsMatrix(int result[N * N][N * N], int matrix1[N][N], int matrix2[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    int idx1 = i * N + k;
                    int idx2 = j * N + l;
                    if ((i == j && matrix2[k][l] == 1) || (k == l && matrix1[i][j] == 1)) {
                        result[idx1][idx2] = 1;
                    }
                    else {
                        result[idx1][idx2] = 0;
                    }
                }
            }
        }
    }
}
void printAdjacencyMatrixCartesian(int matrix[N * N][N * N]) {
    for (int i = 0; i < N * N; i++) {
        for (int j = 0; j < N * N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RU");

    int matrix1[N][N], matrix2[N][N], result[N][N], result1[N * N][N * N];
    int adjacencyList1[N][N], adjacencyList2[N][N];
    int degrees1[N], degrees2[N];


    generateMatrix(matrix1);
    generateMatrix(matrix2);
    printf("Исходная матрица смежности M1:\n");
    printMatrix(matrix1);
    printf("Исходная матрица смежности M2:\n");
    printMatrix(matrix2);


    adjacencyMatrixToList(matrix1, adjacencyList1, degrees1);
    adjacencyMatrixToList(matrix2, adjacencyList2, degrees2);
    printf("\nСписок смежности M1:\n");
    printAdjacencyList(adjacencyList1, degrees1);
    printf("\nСписок смежности M2:\n");
    printAdjacencyList(adjacencyList2, degrees2);

    int choice, a, b, graph_choice;
    do {
        printf("\nВыберите операцию:\n1 - Отождествление вершин\n2 - Стягивание ребра\n3 - Расщепление вершины\n4 - Объединение графов\n5 - Пересечение графов\n6 - Кольцевая сумма графов\n7 - Декартово произведение графов\n8 - Удаление вершины\n0 - выход\n");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("Выберите граф для выполнения операции (1 для M1, 2 для M2): ");
            scanf_s("%d", &graph_choice);
            printf("Введите номера вершин для отождествления (a, b): ");
            scanf_s("%d %d", &a, &b);
            if (graph_choice == 1) {
                mergeVerticesMatrix(matrix1, a, b);
                printf("Матрица смежности M1 после отождествления вершин:\n");
                printMatrix(matrix1);
                mergeVerticesList(adjacencyList1, degrees1, a, b);
                printf("\nСписок смежности M1 после отождествления вершин:\n");
                printAdjacencyList(adjacencyList1, degrees1);
            }
            else {
                mergeVerticesMatrix(matrix2, a, b);
                printf("Матрица смежности M2 после отождествления вершин:\n");
                printMatrix(matrix2);
                mergeVerticesList(adjacencyList2, degrees2, a, b);
                printf("\nСписок смежности M2 после отождествления вершин:\n");
                printAdjacencyList(adjacencyList2, degrees2);
            }
            break;

        case 2:
            printf("Выберите граф для выполнения операции (1 для M1, 2 для M2): ");
            scanf_s("%d", &graph_choice);
            printf("Введите номера вершин для стягивания ребра (a, b): ");
            scanf_s("%d %d", &a, &b);
            if (graph_choice == 1) {
                mergeVerticesMatrix(matrix1, a, b);
                printf("Матрица смежности M1 после стягивания ребра:\n");
                printMatrix(matrix1);
                mergeVerticesList(adjacencyList1, degrees1, a, b);
                printf("\nСписок смежности M1 после стягивания ребра:\n");
                printAdjacencyList(adjacencyList1, degrees1);
            }
            else {
                mergeVerticesMatrix(matrix2, a, b);
                printf("Матрица смежности M2 после стягивания ребра:\n");
                printMatrix(matrix2);
                mergeVerticesList(adjacencyList2, degrees2, a, b);
                printf("\nСписок смежности M2 после стягивания ребра:\n");
                printAdjacencyList(adjacencyList2, degrees2);
            }
            break;

        case 3:
            printf("Выберите граф для выполнения операции (1 для M1, 2 для M2): ");
            scanf_s("%d", &graph_choice);
            printf("Введите номер вершины для расщепления: ");
            scanf_s("%d", &a);
            if (graph_choice == 1) {
                splitVertexMatrix(matrix1, a);
                printf("Матрица смежности M1 после расщепления вершины:\n");
                printMatrix(matrix1);
                splitVertexList(adjacencyList1, degrees1, a);
                printf("\nСписок смежности M1 после расщепления вершины:\n");
                printAdjacencyList(adjacencyList1, degrees1);
            }
            else {
                splitVertexMatrix(matrix2, a);
                printf("Матрица смежности M2 после расщепления вершины:\n");
                printMatrix(matrix2);
                splitVertexList(adjacencyList2, degrees2, a);
                printf("\nСписок смежности M2 после расщепления вершины:\n");
                printAdjacencyList(adjacencyList2, degrees2);
            }
            break;
        case 4:
            unionGraphsMatrix(result, matrix1, matrix2);
            printf("Результат объединения:\n");
            printMatrix(result);
            break;
        case 5:
            intersectionGraphsMatrix(result, matrix1, matrix2);
            printf("Результат пересечения:\n");
            printMatrix(result);
            break;
        case 6:
            ringSumGraphsMatrix(result, matrix1, matrix2);
            printf("Результат кольцевой суммы:\n");
            printMatrix(result);
            break;
        case 7:
            cartesianProductGraphsMatrix(result1, matrix1, matrix2);
            printf("Результат декартова произведения:\n");
            printAdjacencyMatrixCartesian(result1);
            break;
        case 8:
            printf("Выберите граф (1 для M1, 2 для M2): ");
            scanf_s("%d", &graph_choice);
            printf("Введите номер вершины для удаления: ");
            scanf_s("%d", &a);
            if (graph_choice == 1) {
                deleteVertexMatrix(matrix1, a);
                printf("Матрица смежности M1 после удаления вершины:\n");
                printMatrix(matrix1);
                deleteVertexList(adjacencyList1, degrees1, a);
                printf("\nСписок смежности M1 после удаления вершины:\n");
                printAdjacencyList(adjacencyList1, degrees1);
            }
            else {
                deleteVertexMatrix(matrix2, a);
                printf("Матрица смежности M2 после удаления вершины:\n");
                printMatrix(matrix2);
                deleteVertexList(adjacencyList2, degrees2, a);
                printf("\nСписок смежности M2 после удаления вершины:\n");
                printAdjacencyList(adjacencyList2, degrees2);
            }
            break;
        case 0: {
            printf("Выход из программы.\n");
            break;
        }

        default:
            printf("Неправильный ввод. Попробуйте снова.\n");
        }
    }
    while (choice != 0);

    return 0;
}