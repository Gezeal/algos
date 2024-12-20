#include <stdio.h>
#include <limits.h>

#define MAX 10

// Function to calculate the minimum cost and route for TSP using a greedy method
void travelingSalesmanGreedy(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int path[MAX];
    int total_cost = 0;

    // Start at the starting node
    int current = start;
    visited[current] = 1;
    path[0] = current;

    printf("Best route: %d -> ", current);

    for (int count = 1; count < n; count++) {
        int next_node = -1;
        int min_cost = INT_MAX;

        // Find the nearest unvisited node
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current][i] > 0 && graph[current][i] < min_cost) {
                min_cost = graph[current][i];
                next_node = i;
            }
        }

        // Move to the next node
        if (next_node != -1) {
            visited[next_node] = 1;
            path[count] = next_node;
            total_cost += min_cost;
            current = next_node;
            printf("%d -> ", current);
        }
    }

    // Add the cost of returning to the starting node
    if (graph[current][start] > 0) {
        total_cost += graph[current][start];
        printf("%d\n", start);
    } else {
        printf("No path back to start node!\n");
    }

    printf("Minimum cost: %d\n", total_cost);
}

int main() {
    int graph[MAX][MAX] = {
        {0, 3, 2, 4},
        {3, 0, 1, 2},
        {2, 1, 0, 3},
        {4, 2, 3, 0}
    };

    int n = 4; // Number of nodes
    int start_node = 0; // Starting node

    travelingSalesmanGreedy(graph, n, start_node);

    return 0;
}
