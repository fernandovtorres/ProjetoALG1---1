void copy_array(int n, int *src, int *dest);
int first_unvisited(int n, int *visited);
void tsp(int n, int **graph, int *path, int *min_path, int *visited, int pos, int cost, int *min_cost);
void solve_tsp(int n, int **graph, int *min_path, int *min_cost);