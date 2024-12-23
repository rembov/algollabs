﻿#include <stdio.h>
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


void mergeVerticesMatrix(int matrix[N][N], int a, int b) {
    for (int i = 0; i < N; i++) {
        matrix[a][i] |= matrix[b][i];  
        matrix[i][a] = matrix[a][i];
    }
    matrix[a][a] = 0; 
}


void contractEdgeMatrix(int matrix[N][N], int a, int b) {
    mergeVerticesMatrix(matrix, a, b);
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


void contractEdgeList(int adjacencyList[N][N], int degrees[N], int a, int b) {
    mergeVerticesList(adjacencyList, degrees, a, b);
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

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RU");

    int matrix1[N][N], matrix2[N][N];
    int adjacencyList1[N][N], adjacencyList2[N][N];
    int degrees1[N], degrees2[N];

    
    generateAdjacencyMatrix(matrix1);
    generateAdjacencyMatrix(matrix2);
    printf("Исходная матрица смежности M1:\n");
    printAdjacencyMatrix(matrix1);
    printf("Исходная матрица смежности M2:\n");
    printAdjacencyMatrix(matrix2);

    
    adjacencyMatrixToList(matrix1, adjacencyList1, degrees1);
    adjacencyMatrixToList(matrix2, adjacencyList2, degrees2);
    printf("\nСписок смежности M1:\n");
    printAdjacencyList(adjacencyList1, degrees1);
    printf("\nСписок смежности M2:\n");
    printAdjacencyList(adjacencyList2, degrees2);

    int choice, a, b, graph_choice;

    printf("\nВыберите операцию:\n1 - Отождествление вершин\n2 - Стягивание ребра\n3 - Расщепление вершины\n");
    scanf_s("%d", &choice);

    printf("Выберите граф для выполнения операции (1 для M1, 2 для M2): ");
    scanf_s("%d", &graph_choice);

    switch (choice) {
    case 1:
        printf("Введите номера вершин для отождествления (a, b): ");
        scanf_s("%d %d", &a, &b);
        if (graph_choice == 1) {
            mergeVerticesMatrix(matrix1, a, b);
            printf("Матрица смежности M1 после отождествления вершин:\n");
            printAdjacencyMatrix(matrix1);
            mergeVerticesList(adjacencyList1, degrees1, a, b);
            printf("\nСписок смежности M1 после отождествления вершин:\n");
            printAdjacencyList(adjacencyList1, degrees1);
        }
        else {
            mergeVerticesMatrix(matrix2, a, b);
            printf("Матрица смежности M2 после отождествления вершин:\n");
            printAdjacencyMatrix(matrix2);
            mergeVerticesList(adjacencyList2, degrees2, a, b);
            printf("\nСписок смежности M2 после отождествления вершин:\n");
            printAdjacencyList(adjacencyList2, degrees2);
        }
        break;

    case 2:
        printf("Введите номера вершин для стягивания ребра (a, b): ");
        scanf_s("%d %d", &a, &b);
        if (graph_choice == 1) {
            contractEdgeMatrix(matrix1, a, b);
            printf("Матрица смежности M1 после стягивания ребра:\n");
            printAdjacencyMatrix(matrix1);
            contractEdgeList(adjacencyList1, degrees1, a, b);
            printf("\nСписок смежности M1 после стягивания ребра:\n");
            printAdjacencyList(adjacencyList1, degrees1);
        }
        else {
            contractEdgeMatrix(matrix2, a, b);
            printf("Матрица смежности M2 после стягивания ребра:\n");
            printAdjacencyMatrix(matrix2);
            contractEdgeList(adjacencyList2, degrees2, a, b);
            printf("\nСписок смежности M2 после стягивания ребра:\n");
            printAdjacencyList(adjacencyList2, degrees2);
        }
        break;

    case 3:
        printf("Введите номер вершины для расщепления: ");
        scanf_s("%d", &a);
        if (graph_choice == 1) {
            splitVertexMatrix(matrix1, a);
            printf("Матрица смежности M1 после расщепления вершины:\n");
            printAdjacencyMatrix(matrix1);
            splitVertexList(adjacencyList1, degrees1, a);
            printf("\nСписок смежности M1 после расщепления вершины:\n");
            printAdjacencyList(adjacencyList1, degrees1);
        }
        else {
            splitVertexMatrix(matrix2, a);
            printf("Матрица смежности M2 после расщепления вершины:\n");
            printAdjacencyMatrix(matrix2);
            splitVertexList(adjacencyList2, degrees2, a);
            printf("\nСписок смежности M2 после расщепления вершины:\n");
            printAdjacencyList(adjacencyList2, degrees2);
        }
        break;

    default:
        printf("Неверная операция.\n");
        break;
    }

    return 0;
}
