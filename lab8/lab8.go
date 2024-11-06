package main

import (
	"container/list"
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
			bfs(v, matrix, visited)
		}
	}
}

func bfs(start int, matrix [][]int, visited []bool) {
	queue := list.New()
	queue.PushBack(start)
	visited[start] = true

	for queue.Len() > 0 {
		element := queue.Front()
		v := element.Value.(int)
		queue.Remove(element)

		fmt.Printf("%d ", v)

		for i := 0; i < len(matrix); i++ {
			if matrix[v][i] == 1 && !visited[i] {
				queue.PushBack(i)
				visited[i] = true
			}
		}
	}
}

func generateList(matrix [][]int) map[int][]int {
	adjList := make(map[int][]int)
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			if matrix[i][j] == 1 {
				adjList[i] = append(adjList[i], j)
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

func bfsList(adjList map[int][]int) {
	visited := make(map[int]bool)

	for v := range adjList {
		if !visited[v] {
			bfs1(v, adjList, visited)
		}
	}
}

func bfs1(start int, adjList map[int][]int, visited map[int]bool) {
	queue := list.New()
	queue.PushBack(start)
	visited[start] = true

	for queue.Len() > 0 {
		element := queue.Front()
		v := element.Value.(int)
		queue.Remove(element)

		fmt.Printf("%d ", v)

		for _, neighbor := range adjList[v] {
			if !visited[neighbor] {
				queue.PushBack(neighbor)
				visited[neighbor] = true
			}
		}
	}
}

func main() {
	rand.Seed(time.Now().UnixNano())

	n := 5
	matrix := generateMatrix(n)

	fmt.Println("Матрица смежности неориентированного графа:")
	printMatrix(matrix)
	fmt.Println("\nОбход в ширину (матрица смежности):")
	bfsMatrix(matrix)

	adjList := generateList(matrix)
	fmt.Println("\n\nСписок смежности неориентированного графа:")
	printList(adjList)

	fmt.Println("\nОбход в ширину (список смежности):")
	bfsList(adjList)
}
