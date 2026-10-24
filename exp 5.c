#include <stdio.h>

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    float w[n], v[n], r[n], W, profit = 0;
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value: ");
        scanf("%f%f", &w[i], &v[i]);
        r[i] = v[i] / w[i];
    }

    printf("Enter capacity: ");
    scanf("%f", &W);

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (r[i] < r[j]) {
                float t;
                t=r[i]; r[i]=r[j]; r[j]=t;
                t=w[i]; w[i]=w[j]; w[j]=t;
                t=v[i]; v[i]=v[j]; v[j]=t;
            }

    for (int i = 0; i < n && W > 0; i++) {
        float take = (w[i] < W) ? w[i] : W;
        profit += take * r[i];
        W -= take;
    }

    printf("Maximum profit = %.2f\n", profit);
    return 0;
}