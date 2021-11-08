int search(int **graph, int length, int node1, int node2) {
    if(node1 > length || node2 > length) return 0;
    return graph[node1][node2];
}

int main() {

    int graph[4][4] = {
        [0][0] = 0,
        [0][1] = 1,
        [0][2] = 1,
        [0][3] = 0,
        [1][0] = 1,
        [1][1] = 0,

        [1][2] = 0,
        [1][3] = 0,
        [2][0] = 1,
        [2][1] = 0,
        [2][2] = 0,

        [2][3] = 1,
        [3][0] = 0,
        [3][1] = 0,
        [3][2] = 1,
        [3][3] = 0,
    };
}