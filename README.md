# Dijkstra's Algorithm in C

This C code implements Dijkstra's algorithm for finding the shortest path in a graph. The algorithm calculates the shortest distance from a given source vertex to all other vertices in the graph.

## Usage

To use this code, follow the steps below:

1. Include the necessary header files:
   - `<stdio.h>`: for standard input/output operations.
   - `<stdlib.h>`: for memory allocation and deallocation.

2. Define the required data structures:
   - `struct Node`: represents a node in the adjacency list. It contains the vertex number, weight, and a pointer to the next node.
   - `struct AdjList`: represents the adjacency list for a vertex. It contains a pointer to the head node of the list.
   - `struct Graph`: represents the graph. It contains the number of vertices and an array of adjacency lists.

3. Implement helper functions:
   - `createNode()`: creates a new node with the given vertex and weight.
   - `createGraph()`: creates a new graph with the specified number of vertices.
   - `addEdge()`: adds an edge between two vertices with the given weight.
   - `minDistance()`: finds the vertex with the minimum distance value.
   - `printPath()`: prints the shortest path from the source vertex to the destination vertex.
   - `printSolution()`: prints the shortest distance and path from the source vertex to all other vertices.
   - `dijkstra()`: performs Dijkstra's algorithm to find the shortest paths.

4. Implement a function to free the memory allocated for the graph:
   - `freeGraph()`: frees the memory allocated for the graph and its nodes.

5. Define a test function to demonstrate the usage of Dijkstra's algorithm:
   - `TestDijkstra()`: creates a sample graph, adds edges, and calls the `dijkstra()` function.

6. In the `main()` function, call the test function to execute Dijkstra's algorithm and print the shortest paths.

## Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Data structures and functions described above...

int main() {
    TestDijkstra();
    return 0;
}
```

## Contributors

- OUSSAMA ABBOU
- SALMA EL HAFIANI
- MARYAM CHOUKI
- KHAOULA ELHOUAT

## License

This code is released under the [MIT License](LICENSE). Feel free to use, modify, and distribute it according to the terms of the license.
