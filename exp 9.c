#include <stdio.h>

#define SIZE 4

int main() {
    int puzzle[SIZE][SIZE];
    int count = 0;

    printf("Enter the 4x4 puzzle matrix (0 for empty tile):\n");

    for (int i = 0; i < SIZE * SIZE; i++) {
        int row = i / SIZE;
        int col = i % SIZE;

        if (scanf("%d", &puzzle[row][col]) != 1) return 1;

        // Count misplaced tiles (ignoring the last empty spot/position 16)
        if (i < SIZE * SIZE - 1 && puzzle[row][col] != i + 1) {
            count++;
        }
    }

    // Print the puzzle grid cleanly
    printf("\nGiven Initial State:\n");
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            printf("%2d ", puzzle[r][c]);
        }
        printf("\n");
    }

    printf("\nMisplaced tiles = %d\n", count);
    printf("Initial cost     = %d\n", count);

    return 0;
}