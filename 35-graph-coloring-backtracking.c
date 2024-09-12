#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Function to print the solution
void printSolution(int color[], int V) {
    printf("Solution Exists: Following are the assigned colors\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }
}

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, bool graph[MAX][MAX], int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// A recursive utility function to solve the m coloring problem
bool graphColoringUtil(bool graph[MAX][MAX], int m, int color[], int v, int V) {
    // If all vertices are assigned a color then return true
    if (v == V) {
        return true;
    }

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is fine
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;

            // Recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution then remove it (BACKTRACK)
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return false;
}

// This function solves the m Coloring problem using backtracking
bool graphColoring(bool graph[MAX][MAX], int m, int V) {
    int color[MAX] = {0}; // Initialize all color values as 0 (unassigned)

    // Call graphColoringUtil() for vertex 0
    if (!graphColoringUtil(graph, m, color, 0, V)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(color, V);
    return true;
}

int main() {
    int V, E, m;
    bool graph[MAX][MAX] = {false};

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v) one by one:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = true;
        graph[v][u] = true; // Assuming undirected graph
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    return 0;
}
