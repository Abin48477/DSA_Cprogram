#include <stdio.h>
#define INF 9999
#define V 5  // number of vertices

void primMST(int graph[V][V]) {
    int selected[V] = {0};
    int edgeCount = 0;
    selected[0] = 1;

    printf("Edge \tWeight\n");

    while (edgeCount < V - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d\t%d\n", x, y, graph[x][y]);
        selected[y] = 1;
        edgeCount++;
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}

