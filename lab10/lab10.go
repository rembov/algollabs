package main

import (
	"fmt"
	"math"
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

func calculateRadiusDiameter(matrix [][]int) (int, int, []int, []int) {
	n := len(matrix)
	radius := math.MaxInt
	diameter := 0
	peripheral := []int{}
	central := []int{}

	distances := make([][]int, n)
	for i := 0; i < n; i++ {
		distances[i] = bfsDistance(matrix, i)
	}

	for i := 0; i < n; i++ {
		maxDist := 0
		for j := 0; j < n; j++ {
			if distances[i][j] == -1 {
				maxDist = math.MaxInt
			}
			maxDist = int(math.Max(float64(maxDist), float64(distances[i][j])))
		}

		diameter = int(math.Max(float64(diameter), float64(maxDist)))

		radius = int(math.Min(float64(radius), float64(maxDist)))
	}

	for i := 0; i < n; i++ {
		maxDist := 0
		for j := 0; j < n; j++ {
			if distances[i][j] == -1 {
				maxDist = math.MaxInt
			}
			maxDist = int(math.Max(float64(maxDist), float64(distances[i][j])))
		}
		if maxDist == diameter {
			peripheral = append(peripheral, i)
		}
	}

	for i := 0; i < n; i++ {
		maxDist := 0
		for j := 0; j < n; j++ {
			if distances[i][j] == -1 {
				maxDist = math.MaxInt
			}
			maxDist = int(math.Max(float64(maxDist), float64(distances[i][j])))
		}
		if maxDist == radius {
			central = append(central, i)
		}
	}

	return radius, diameter, peripheral, central
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
	radius, diameter, peripheral, central := calculateRadiusDiameter(matrix)

	fmt.Printf("\nРадиус графа: %d\n", radius)
	fmt.Printf("Диаметр графа: %d\n", diameter)
	fmt.Printf("Периферийные вершины: %v\n", peripheral)
	fmt.Printf("Центральные вершины: %v\n", central)
}
