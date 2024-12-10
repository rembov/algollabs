package main
import (
	"container/list"
	"fmt"
	"math"
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
			weight := rand.Intn(10) + 1
			graph[i][j] = weight
			graph[j][i] = weight
		}
	}
	return graph
}
func printMatrix(matrix [][]int, header string) {
	fmt.Println(header)
	for i, row := range matrix {
		fmt.Printf("%2d: ", i+1)
		for _, val := range row {
			if val == math.MaxInt32 {
				fmt.Print("∞ ")
			} else {
				fmt.Printf("%2d ", val)
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
func bfsD(v int, size int, dist []int, graph [][]int) {
	q := list.New()
	q.PushBack(v)
	dist[v] = 0
	for q.Len() > 0 {
		front := q.Front()
		v = front.Value.(int)
		q.Remove(front)

		for i := 0; i < size; i++ {
			if graph[v][i] != 0 && dist[v]+graph[v][i] < dist[i] {
				dist[i] = dist[v] + graph[v][i]
				q.PushBack(i)
			}
		}
	}
}
func calculateDistanceMatrix(graph [][]int) [][]int {
	size := len(graph)
	distances := make([][]int, size)
	for i := 0; i < size; i++ {
		dist := make([]int, size)
		for j := 0; j < size; j++ {
			dist[j] = math.MaxInt32
		}
		bfsD(i, size, dist, graph)
		distances[i] = dist
	}

	return distances
}
func printDistances(e []int) {
	min := math.MaxInt32
	max := math.MinInt32
	periphery := []int{}
	center := []int{}
	for _, val := range e {
		if val > max {
			max = val
		}
		if val < min {
			min = val
		}
		fmt.Printf("%d ", val)
	}
	fmt.Println()
	for i, val := range e {
		if val == max {
			periphery = append(periphery, i+1)
		}
		if val == min {
			center = append(center, i+1)
		}
	}

	fmt.Printf("Радиус графа равен: %d\n", min)
	fmt.Printf("Диаметр графа равен: %d\n", max)
	fmt.Print("Центральные вершины: ")
	if len(center) == 0 {
		fmt.Print("null")
	} else {
		for _, v := range center {
			fmt.Printf("%d ", v)
		}
	}
	fmt.Println()
	fmt.Print("Периферийные вершины: ")
	if len(periphery) == 0 {
		fmt.Print("null")
	} else {
		for _, v := range periphery {
			fmt.Printf("%d ", v)
		}
	}
	fmt.Println()
}
func analyzeGraph(distances [][]int) {
	size := len(distances)
	eccentricities := make([]int, size)
	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			if distances[i][j] < math.MaxInt32 && distances[i][j] > eccentricities[i] {
				eccentricities[i] = distances[i][j]
			}
		}
	}

	fmt.Println("\nЭксцентриситеты вершин:")
	printDistances(eccentricities)
}

func main() {
	var size int
	fmt.Print("Введите размер графа: ")
	fmt.Scan(&size)

	graph := generateGraph(size)
	printMatrix(graph, "Матрица смежности графа:")

	distances := calculateDistanceMatrix(graph)
	printMatrix(distances, "Матрица расстояний:")

	analyzeGraph(distances)
}
