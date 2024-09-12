#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

void printSolution(int path[]);

// Function to check if the current vertex can be added to the path
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive function to find Hamiltonian Circuit
bool hamiltonianCircuitUtil(bool graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // And if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            printSolution(path);
            return true;
        } else {
            return false;
        }
    }

    // Try different vertices as the next candidate in Hamiltonian Circuit
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamiltonianCircuitUtil(graph, path, pos + 1))
                return true;

            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find Hamiltonian Circuit in a given graph
void hamiltonianCircuit(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from the first vertex (0 as the starting vertex)
    path[0] = 0;

    if (!hamiltonianCircuitUtil(graph, path, 1)) {
        printf("Hamiltonian Circuit does not exist\n");
    }
}

// Function to print the Hamiltonian Circuit
void printSolution(int path[]) {
    printf("Hamiltonian Circuit found: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // Print the first vertex again to complete the cycle
}

int main() {
    // Example adjacency matrix of the graph
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCircuit(graph);

    return 0;
}
