#import "../brute.h"

#define INF 2147483647

// Function to copy array elements from source to destination
void copy_array(int n, int *src, int *dest) {
    for(int i=0; i<n; i++)
        dest[i] = src[i];
}

// Function to find the first unvisited city
int first_unvisited(int n, int *visited) {
    for(int i=0; i<n; i++)
        if(!visited[i])
            return i;
    return -1;
}

// Recursive function to solve the TSP problem
void tsp(int n, int **graph, int *path, int *min_path, int *visited, int pos, int cost, int *min_cost) {
    visited[pos] = 1; // Mark the current city as visited
    path[pos] = n - 1 - first_unvisited(n, visited); // Update the path with the current city

    // If all cities are visited and there is a path from the current city to the starting city
    if(first_unvisited(n, visited) == -1 && graph[pos][0]) {
        // If the total cost of the current path is less than the minimum cost found so far
        if(cost + graph[pos][0] < *min_cost) {
            copy_array(n, path, min_path); // Update the minimum path
            *min_cost = cost + graph[pos][0]; // Update the minimum cost
        }
    }

    // For all cities
    for(int i=0; i<n; i++) {
        // If the city is unvisited and there is a path from the current city to the city
        if(!visited[i] && graph[pos][i]) {
            // Recur for the city
            tsp(n, graph, path, min_path, visited, i, cost + graph[pos][i], min_cost);
        }
    }

    visited[pos] = 0; // Mark the current city as unvisited for other recursive calls
}

// Function to solve the TSP problem
void solve_tsp(int n, int **graph, int *min_path, int *min_cost) {
    int path[n]; // Array to store the current path
    int visited[n]; // Array to mark cities as visited or unvisited
    for(int i=0; i<n; i++)
        visited[i] = 0; // Initially, all cities are unvisited

    *min_cost = INF; // Initialize the minimum cost as infinity
    tsp(n, graph, path, min_path, visited, 0, 0, min_cost); // Start the TSP from the first city
}