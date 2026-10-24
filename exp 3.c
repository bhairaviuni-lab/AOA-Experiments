#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0, temp[50];

    while (i <= m && j <= r)
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++) a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {12, 11, 13, 5, 6, 7}, n = 6;

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}