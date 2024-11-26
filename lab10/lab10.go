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

func analyzeGraph(distances [][]int) {
	size := len(distances)
	eccentricities := make([]int, size)
	radius := int(^uint(0) >> 1) 
	diameter := 0

	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			if distances[i][j] > eccentricities[i] {
				eccentricities[i] = distances[i][j]
			}
		}
		if eccentricities[i] > diameter {
			diameter = eccentricities[i]
		}
		if eccentricities[i] < radius && eccentricities[i] != 0 {
			radius = eccentricities[i]
		}
	}

	var centralVertices, peripheralVertices []int
	for i, e := range eccentricities {
		if e == radius {
			centralVertices = append(centralVertices, i+1)
		}
		if e == diameter {
			peripheralVertices = append(peripheralVertices, i+1)
		}
	}

	// Print results
	fmt.Printf("\nРадиус графа: %d\n", radius)
	fmt.Printf("Диаметр графа: %d\n", diameter)
	fmt.Printf("Центральные вершины: %v\n", centralVertices)
	fmt.Printf("Периферийные вершины: %v\n", peripheralVertices)

	// Reset distances
	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			if distances[i][j] != 0 {
				distances[i][j] = -1
			}
		}
	}
}

func main() {
	size := 6
	graph := generateGraph(size)

	printMatrix(graph)
	distances := calculateDistanceMatrix(graph)

	fmt.Println("\nМатрица расстояний:")
	printMatrix(distances)

	analyzeGraph(distances)

}
