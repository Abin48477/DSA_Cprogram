// Kruskal’s Algorithm
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct Edge {
    int src, dest, weight;
};

int parent[MAX];

int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(struct Edge edges[], int n, int vertices) {
    struct Edge result[MAX];
    int e = 0, i = 0;

    for (int v = 0; v < vertices; v++)
        parent[v] = v;

    printf("Edge \tWeight\n");

    while (e < vertices - 1 && i < n) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        if (find(src) != find(dest)) {
            result[e++] = edges[i];
            unionSet(src, dest);
        }
        i++;
    }

    for (i = 0; i < e; i++)
        printf("%d - %d\t%d\n", result[i].src, result[i].dest, result[i].weight);
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

int main() {
    struct Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    int vertices = 4;
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    qsort(edges, edgeCount, sizeof(edges[0]), compare);

    kruskal(edges, edgeCount, vertices);

    return 0;
}

