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
func generateList(n int) map[int][]int {
	adjList := make(map[int][]int)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			randomEdge := rand.Intn(2)
			if randomEdge == 1 {
				adjList[i] = append(adjList[i], j)
				adjList[j] = append(adjList[j], i)
			}
		}
	}
	return adjList
}

func printList(adjList map[int][]int) {
	for node, neighbors := range adjList {
		fmt.Printf("%d: %v\n", node, neighbors)
	}
}

func d(matrix [][]int) {
	n := len(matrix)
	visited := make([]bool, n)

	for v := 0; v < n; v++ {
		if !visited[v] {
			dfs(v, matrix, visited)
		}
	}
}

func dfs1(v int, adjList map[int][]int, visited map[int]bool) {
	visited[v] = true
	fmt.Printf("%d ", v)

	for _, neighbor := range adjList[v] {
		if !visited[neighbor] {
			dfs1(neighbor, adjList, visited)
		}
	}
}

func d1(adjList map[int][]int) {
	visited := make(map[int]bool)

	for v := range adjList {
		if !visited[v] {
			dfs1(v, adjList, visited)
		}
	}
}

func dfsI(start int, matrix [][]int, visited []bool) {
	stack := []int{start}

	for len(stack) > 0 {

		v := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if !visited[v] {
			visited[v] = true
			fmt.Printf("%d ", v)
		}

		for i := len(matrix) - 1; i >= 0; i-- {
			if matrix[v][i] == 1 && !visited[i] {
				stack = append(stack, i)
			}
		}
	}
}
func d2(matrix [][]int) {
	n := len(matrix)
	visited := make([]bool, n)

	for v := 0; v < n; v++ {
		if !visited[v] {
			dfsI(v, matrix, visited)
		}
	}
}
func main() {
	rand.Seed(time.Now().UnixNano())

	n := 5
	matrix := generateMatrix(n)
	List1 := generateList(n)
	fmt.Println("Матрица смежности неориентированного графа:")
	printMatrix(matrix)
	fmt.Println("Список смежности неориентированного графа:")
	printList(List1)

	fmt.Println("\nОбход в глубину матрицы:")
	d(matrix)
	fmt.Println("\nОбход в глубину (нерекурсивный):")
	d2(matrix)
	fmt.Println("\nОбход в глубину списка:")
	d1(List1)
}
