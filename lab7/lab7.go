package main

import (
	"fmt"
	"math/rand"
	"time"
)

func generateMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := range matrix {
		matrix[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			if i == j {
				matrix[i][j] = 0
			} else {
				randomEdge := rand.Intn(2)
				matrix[i][j] = randomEdge
				matrix[j][i] = randomEdge
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

func dfs(v int, matrix [][]int, visited []bool) {

	visited[v] = true
	fmt.Printf("%d ", v)

	for i := 0; i < len(matrix); i++ {
		if matrix[v][i] == 1 && !visited[i] {
			dfs(i, matrix, visited)
		}
	}
}

func depthFirstTraversal(matrix [][]int) {
	n := len(matrix)
	visited := make([]bool, n)

	for v := 0; v < n; v++ {
		if !visited[v] {
			dfs(v, matrix, visited)
		}
	}
}
func main() {
	rand.Seed(time.Now().UnixNano())

	n := 5
	matrix := generateMatrix(n)

	fmt.Println("Матрица смежности неориентированного графа:")
	printMatrix(matrix)
	fmt.Println("\nОбход в глубину:")
	depthFirstTraversal(matrix)
}
