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

func bfsD(matrix [][]int, start int) []int {
	n := len(matrix)
	distances := make([]int, n)
	for i := range distances {
		distances[i] = -1
	}

	queue := list.New()
	queue.PushBack(start)
	distances[start] = 0
	for queue.Len() > 0 {
		element := queue.Front()
		v := element.Value.(int)
		queue.Remove(element)

		for i := 0; i < n; i++ {
			if matrix[v][i] == 1 && distances[i] == -1 {
				distances[i] = distances[v] + 1
				queue.PushBack(i)
			}
		}
	}

	return distances
}

func main() {
	rand.Seed(time.Now().UnixNano())

	n := 5
	matrix := generateMatrix(n)

	// Печатаем матрицу смежности
	fmt.Println("Матрица смежности неориентированного графа:")
	printMatrix(matrix)

	start := 0
	fmt.Printf("\nРасстояния от вершины %d:\n", start)
	distances := bfsD(matrix, start)

	for v, distance := range distances {
		if distance == -1 {
			fmt.Printf("До вершины %d нет пути.\n", v)
		} else {
			fmt.Printf("Расстояние до вершины %d: %d\n", v, distance)
		}
	}
}
