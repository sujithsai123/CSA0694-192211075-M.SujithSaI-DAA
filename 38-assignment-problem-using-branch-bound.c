#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4 // Number of workers (and tasks), adjust as needed

// Function to find the minimum cost assignment using branch and bound
void assignmentProblem(int costMatrix[N][N]) {
    int assigned[N];    // Array to store assignment of tasks to workers
    bool visited[N];    // Array to track visited workers
    int minCost = 0;    // Minimum cost of assignment

    // Initialize arrays
    for (int i = 0; i < N; i++) {
        assigned[i] = -1;
        visited[i] = false;
    }

    // Greedy initialization: Assign tasks to workers based on minimum cost
    for (int worker = 0; worker < N; worker++) {
        // Find the minimum cost task for this worker
        int minCostTask = -1;
        int minCostValue = INT_MAX;
        for (int task = 0; task < N; task++) {
            if (!visited[task] && costMatrix[worker][task] < minCostValue) {
                minCostValue = costMatrix[worker][task];
                minCostTask = task;
            }
        }
        visited[minCostTask] = true;
        assigned[worker] = minCostTask;
        minCost += minCostValue;
    }

    // Print initial assignment
    printf("Initial Assignment (Greedy Heuristic):\n");
    for (int worker = 0; worker < N; worker++) {
        printf("Worker %d -> Task %d\n", worker + 1, assigned[worker] + 1);
    }
    printf("Initial Minimum Cost: %d\n\n", minCost);

    // Branch and Bound (TODO: Implement branch and bound optimization)
    // Placeholder for further refinement using branch and bound approach
}

int main() {
    // Example cost matrix (adjust values as needed)
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    assignmentProblem(costMatrix);

    return 0;
}
