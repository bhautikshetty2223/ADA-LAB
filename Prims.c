#include<stdio.h>
#include<stdbool.h>
#include<time.h>

#define INF 9999999

int main() {
    clock_t start_t, end_t;
    double total_t;

    int V;

    // input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int G[V][V];

    // input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    int no_edge;

    int selected[V];

    // initialize selected array to false (0)
    for(int i = 0; i < V; i++)
        selected[i] = 0;

    no_edge = 0;

    // start from vertex 0
    selected[0] = 1;

    int x, y;

    printf("Edge : Weight\n");

    start_t = clock();

    while (no_edge < V - 1) {

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = 1;
        no_edge++;
    }

    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("\nTime taken: %f", total_t);

    return 0;
}
