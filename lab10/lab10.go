package main

import (
	"container/list"
	"fmt"
	"math/rand"
	"time"
)

func generateGraph(size int) [][]int {
	rand.Seed(time.Now().UnixNano())
	graph := make([][]int, size)
	for i := range graph {
		graph[i] = make([]int, size)
	}
	for i := 0; i < size; i++ {
		for j := i + 1; j < size; j++ {
			weight := rand.Intn(10)
			graph[i][j] = weight
			graph[j][i] = weight
		}
	}
	return graph
}
func printMatrix(matrix [][]int) {
	for _, row := range matrix {
		for _, val := range row {
			fmt.Printf("%d ", val)
		}
		fmt.Println()
	}
}

func bfs(graph [][]int, start int) []int {
	size := len(graph)
	DIST := make([]int, size)
	for i := range DIST {
		DIST[i] = -1
	}

	queue := list.New()
	queue.PushBack(start)
	DIST[start] = 0

	for queue.Len() > 0 {
		v := queue.Remove(queue.Front()).(int)
		for i := 0; i < size; i++ {
			if graph[v][i] > 0 && DIST[i] == -1 {
				DIST[i] = DIST[v] + graph[v][i]
				queue.PushBack(i)
			}
		}
	}

	return DIST
}
func calculateDistanceMatrix(graph [][]int) [][]int {
	size := len(graph)
	distances := make([][]int, size)

	for i := 0; i < size; i++ {
		distances[i] = bfs(graph, i)
	}

	return distances
}
func analyzeGraph(distances [][]int) (int, int, []int, []int) {
	size := len(distances)
	eccentricities := make([]int, size)

	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			if distances[i][j] > eccentricities[i] {
				eccentricities[i] = distances[i][j]
			}
		}
	}

	radius := int(^uint(0) >> 1)
	diameter := 0

	for _, e := range eccentricities {
		if e > diameter {
			diameter = e
		}
		if e < radius && e != 0 {
			radius = e
		}
	}

	var centralVertices, peripheralVertices []int
	for i, e := range eccentricities {
		if e == radius {
			centralVertices = append(centralVertices, i)
		}
		if e == diameter {
			peripheralVertices = append(peripheralVertices, i)
		}
	}

	return radius, diameter, centralVertices, peripheralVertices
}

func main() {
	size := 6
	graph := generateGraph(size)

	printMatrix(graph)
	distances := calculateDistanceMatrix(graph)

	fmt.Println("\nМатрица расстояний:")
	printMatrix(distances)

	radius, diameter, centralVertices, peripheralVertices := analyzeGraph(distances)

	fmt.Printf("\nРадиус графа: %d\n", radius)
	fmt.Printf("Диаметр графа: %d\n", diameter)
	fmt.Printf("Центральные вершины: %v\n", centralVertices)
	fmt.Printf("Периферийные вершины: %v\n", peripheralVertices)
}
