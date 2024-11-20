package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Queue struct {
	elements []int
}

func (q *Queue) Enq(value int) {
	q.elements = append(q.elements, value)
}

func (q *Queue) Deq() (int, bool) {
	if len(q.elements) == 0 {
		return 0, false
	}
	value := q.elements[0]
	q.elements = q.elements[1:]
	return value, true
}

func (q *Queue) IsEmpty() bool {
	return len(q.elements) == 0
}

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

func bfs(matrix [][]int, start int) []int {
	n := len(matrix)
	distances := make([]int, n)
	for i := range distances {
		distances[i] = -1
	}

	queue := &Queue{}
	queue.Enq(start)
	distances[start] = 0

	for !queue.IsEmpty() {
		v, _ := queue.Deq()

		for i := 0; i < n; i++ {
			if matrix[v][i] == 1 && distances[i] == -1 {
				distances[i] = distances[v] + 1
				queue.Enq(i)
			}
		}
	}

	return distances
}

func main() {
	rand.Seed(time.Now().UnixNano())
	n := 5
	matrix := generateMatrix(n)
	fmt.Println("Матрица смежности неориентированного графа:")
	printMatrix(matrix)
	start := 0
	distances := bfs(matrix, start)
	for v, distance := range distances {
		if distance == -1 {
			fmt.Printf("До вершины %d нет пути.\n", v)
		} else {
			fmt.Printf("Расстояние до вершины %d: %d\n", v, distance)
		}
	}
}
