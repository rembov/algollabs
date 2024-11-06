package main

import (
	"fmt"
	"math/rand"
	"time"
)

func generateMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if rand.Intn(2) == 1 {
				matrix[i][j] = 1
				matrix[j][i] = 1
			}
		}
	}
	return matrix
}

func printMatrix(matrix [][]int) {
	for _, row := range matrix {
		for _, val := range row {
			fmt.Printf("%d ", val)
		}
		fmt.Println()
	}
}

func bfsDistance(matrix [][]int, start int) []int {
	n := len(matrix)
	dist := make([]int, n)
	for i := 0; i < n; i++ {
		dist[i] = -1
	}
	dist[start] = 0

	queue := []int{start}

	for len(queue) > 0 {

		v := queue[0]
		queue = queue[1:]

		for i := 0; i < n; i++ {
			if matrix[v][i] > 0 && dist[i] == -1 {
				queue = append(queue, i)
				dist[i] = dist[v] + matrix[v][i]
			}
		}
	}

	return dist
}

func main() {
	rand.Seed(time.Now().UnixNano())

	n := 5
	matrix := generateMatrix(n)

	fmt.Println("Матрица смежности для графа:")
	printMatrix(matrix)

	start := 0

	distances := bfsDistance(matrix, start)

	fmt.Printf("\nРасстояния от вершины %d:\n", start)
	for i, d := range distances {
		if d == -1 {
			fmt.Printf("До вершины %d нет пути.\n", i)
		} else {
			fmt.Printf("Расстояние до вершины %d: %d\n", i, d)
		}
	}
}
