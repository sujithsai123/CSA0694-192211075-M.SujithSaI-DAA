#include <stdio.h>
#include <limits.h>

#define N 4  // Number of cities

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the minimum cost of visiting all cities using dynamic programming
int tsp(int dist[N][N]) {
    int n = N;
    int VISITED_ALL = (1 << n) - 1;

    // dp[mask][i] will hold the minimum cost of visiting all nodes in 'mask' ending at node 'i'
    int dp[1 << N][N];

    // Initialize dp array with infinity
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            dp[mask][i] = INT_MAX;
        }
    }

    // Start at the first city, with only the first city visited
    dp[1][0] = 0;

    // Iterate over all subsets of cities
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {  // Check if 'i' is in the subset represented by 'mask'
                for (int j = 0; j < N; j++) {
                    if (!(mask & (1 << j))) {  // Check if 'j' is not in the subset
                        int newMask = mask | (1 << j);
                        if (dp[mask][i] != INT_MAX && dist[i][j] != INT_MAX) {
                            dp[newMask][j] = min(dp[newMask][j], dp[mask][i] + dist[i][j]);
                        }
                    }
                }
            }
        }
    }

    // Find the minimum cost to visit all cities and return to the starting city
    int minCost = INT_MAX;
    for (int i = 1; i < N; i++) {
        if (dp[VISITED_ALL][i] != INT_MAX && dist[i][0] != INT_MAX) {
            minCost = min(minCost, dp[VISITED_ALL][i] + dist[i][0]);
        }
    }

    return minCost;
}

int main() {
    // Example distance matrix (symmetric matrix)
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    printf("The minimum cost to visit all cities is %d\n", tsp(dist));

    return 0;
}
