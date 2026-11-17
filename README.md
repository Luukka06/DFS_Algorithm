# DFS (Deep First Search) Algorithm 

## Overview
Depth-First Search (DFS) is a graph traversal algorithm that explores as deeply as possible along each path before backtracking. This implementation uses recursion.

## Data Structures
- `N` – Number of vertices.
- `time` – Tracks the traversal time.
- `adj` – Adjacency list.
- `visited` – Tracks visited vertices.
- `parent` – Stores each vertex's parent.
- `GrayTime` – Discovery time of each vertex.
- `BlackTime` – Finishing time of each vertex.

## Helper Functions
- `Graph(int N)` – Initializes the graph and its data structures.
- `~Graph()` – Releases dynamically allocated memory.
- `AddEdge(u, v)` – Adds a directed edge.
- `printGraph()` – Displays the adjacency list.
- `DFS()` – Initializes DFS and visits all vertices.
- `DFS_Visit(u, visited)` – Recursively explores adjacent vertices.

## How DFS Works
1. Checks if the graph is empty.
2. Initializes all vertices as unvisited and sets their parents to `-1`.
3. Resets the traversal time to `0`.
4. Iterates through all vertices and calls `DFS_Visit()` for each unvisited vertex.
5. Marks the current vertex as visited and records its discovery time (`GrayTime`).
6. Recursively visits all unvisited adjacent vertices.
7. After exploring all neighbors, records the finishing time (`BlackTime`).
8. Prints each vertex's discovery time, finishing time, and parent.

## Discovery and Finishing Times
- `GrayTime` – The time when a vertex is first visited.
- `BlackTime` – The time when a vertex has finished processing.
- White – Unvisited vertex.
- Gray – Currently being explored.
- Black – Fully processed vertex.

## Example Output
```text
vertex 0: 1/10, parent=-1
vertex 1: 2/7, parent=0
vertex 2: 8/9, parent=0
vertex 3: 3/6, parent=1
vertex 4: 4/5, parent=3
```

# Important Notes
- DFS uses recursion to explore the graph.
- The visited array prevents revisiting vertices.
- The parent vector stores the DFS tree structure.
- Discovery and finishing times help track the traversal process.
- The outer loop ensures that disconnected components are also visited.
- AddEdge() creates directed edges.
# Complexity Analysis
- Time Complexity: O(V + E)
- Space Complexity: O(V + E)
Where:
- V – Number of vertices.
- E – Number of edges.
# Usage
```
Graph g(5);

g.AddEdge(0, 1);
g.AddEdge(0, 2);
g.AddEdge(1, 3);
g.AddEdge(2, 3);
g.AddEdge(3, 4);

g.printGraph();
g.DFS();
```
