
# Kruskal's Algorithm Implementation in C++

## Overview

Kruskal's Algorithm is a greedy algorithm used for finding the Minimum Spanning Tree (MST) of a connected, undirected graph. It works by sorting all edges of the graph in non-decreasing order of their weights, then adding edges one by one to the MST, ensuring no cycles are formed using the Disjoint Set Union (DSU) technique (Union-Find).

## Theory

Kruskal’s algorithm follows these steps:

1. **Sort all edges** in the graph by their weight.
2. **Initialize the MST** as an empty set of edges.
3. **Iterate through sorted edges** and add them to the MST if they don’t form a cycle. To check for cycles, a Disjoint Set (Union-Find) is used.
4. **Stop when the MST contains n-1 edges**, where n is the number of vertices.

This results in the Minimum Spanning Tree that connects all vertices with the minimum total edge weight.

## Features

- Implements **Kruskal's Algorithm** for finding the Minimum Spanning Tree (MST).
- Uses **Union-Find** data structure to efficiently check and manage cycles.
- Implements a **Min-Heap** for efficient edge selection based on weight.


## Explanation of Code

1. **Edge Structure:** 
   The `Edge` structure holds information about an edge, including the two vertices `u` and `v`, and the edge's `weight`.

2. **Find Function:** 
   A recursive function to find the parent of a vertex using path compression. It helps in detecting cycles by identifying the root parent of a vertex.

3. **Union Function:** 
   This function performs the union of two sets. It uses union by rank to keep the tree flat, which helps in optimizing the find operation.

4. **Heapify and Min-Heap Construction:** 
   The `Heapify` function ensures that the edges are ordered based on their weight. The `BuildMinHeap` function constructs the heap from a given list of edges.

5. **Kruskal's Function:** 
   The main function that implements Kruskal's Algorithm. It extracts edges in increasing order of weight, checks for cycles using the Union-Find structure, and builds the MST.

## Example

Consider the following graph with 5 nodes (0, 1, 2, 3, 4) and 7 edges, each with a specific weight:

```cpp
int n = 5;  // Number of vertices
vector<Edge> edges = {
    {0, 1, 2},
    {0, 3, 6},
    {1, 2, 3},
    {1, 3, 8},
    {1, 4, 5},
    {2, 4, 7},
    {3, 4, 9}
};
```

### Explanation of the Example:

We have a graph with 5 vertices and 7 edges. The edges and their respective weights are:

```
(0, 1, 2)  -> edge between vertex 0 and vertex 1 with weight 2
(0, 3, 6)  -> edge between vertex 0 and vertex 3 with weight 6
(1, 2, 3)  -> edge between vertex 1 and vertex 2 with weight 3
(1, 3, 8)  -> edge between vertex 1 and vertex 3 with weight 8
(1, 4, 5)  -> edge between vertex 1 and vertex 4 with weight 5
(2, 4, 7)  -> edge between vertex 2 and vertex 4 with weight 7
(3, 4, 9)  -> edge between vertex 3 and vertex 4 with weight 9
```

### Steps in Kruskal's Algorithm:

1. **Sort edges by weight**:
   After sorting, the edges become:
   ```
   (0, 1, 2), (1, 2, 3), (1, 4, 5), (0, 3, 6), (2, 4, 7), (1, 3, 8), (3, 4, 9)
   ```

2. **Start adding edges to the MST**:
   We begin with an empty MST and consider each edge one by one:

   - **Edge (0, 1, 2)**: This edge does not form a cycle, so we add it to the MST.
   - **Edge (1, 2, 3)**: No cycle, so we add this edge to the MST.
   - **Edge (1, 4, 5)**: No cycle, so we add this edge to the MST.
   - **Edge (0, 3, 6)**: No cycle, so we add this edge to the MST.

   At this point, we have selected 4 edges, which is enough for an MST with 5 vertices.

3. **MST Result**:
   The edges in the MST are:
   ```
   (0, 1, 2), (1, 2, 3), (1, 4, 5), (0, 3, 6)
   ```

   The total weight of the MST is:
   ```
   2 + 3 + 5 + 6 = 16
   ```

   So, the output will be:

   ```
   Minimum Cost of Spanning Tree: 16
   Edges in MST:
   0 - 1
   1 - 2
   1 - 4
   0 - 3
   ```

## Contact

For any questions or issues, feel free to open an issue in the repository or contact the author.

---
