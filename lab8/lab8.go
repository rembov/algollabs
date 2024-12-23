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
		for j := i + 1; j < n; j++ {
			randomEdge := rand.Intn(2)
			matrix[i][j] = randomEdge
			matrix[j][i] = randomEdge
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

func bfsMatrix(matrix [][]int) {
	n := len(matrix)
	visited := make([]bool, n)

	for v := 0; v < n; v++ {
		if !visited[v] {
			queue := []int{v}
			visited[v] = true
			bfs(matrix, queue, visited)
		}
	}
}

func bfs(matrix [][]int, queue []int, visited []bool) {
	if len(queue) == 0 {
		return
	}

	v := queue[0]
	queue = queue[1:]

	fmt.Printf("%d ", v)

	for i := 0; i < len(matrix); i++ {
		if matrix[v][i] == 1 && !visited[i] {
			queue = append(queue, i)
			visited[i] = true
		}
	}

	bfs(matrix, queue, visited)
}

func main() {
	rand.Seed(time.Now().UnixNano())

	n := 5
	matrix := generateMatrix(n)

	fmt.Println("Матрица смежности неориентированного графа:")
	printMatrix(matrix)
	fmt.Println("\nОбход в ширину (матрица смежности):")
	bfsMatrix(matrix)

}
