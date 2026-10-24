#include <stdio.h>

#define INF 999

int main() {
    int n, d[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter matrix (999 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("Shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", d[i][j]);
        printf("\n");
    }

    return 0;
}