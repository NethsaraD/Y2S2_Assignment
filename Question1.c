#include <stdio.h>
#include <stdlib.h>
void move(int i, int j, int **grid);

int n, m;
int ways = 0;

int main() {
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the grid values (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    n = n - 1;
    m = m - 1;
    move(0, 0, grid);
    printf("Number of ways : %d\n", ways);

    return 0;
}


void move(int i, int j, int **grid) {
    if (i == n && j == m) {
        ways = ways + 1;
    } else {
        if (i <= n && j <= m && grid[i][j] == 0) {
            if (i + 1 <= n) {
                if (grid[i + 1][j] == 0) {
                    move(i + 1, j, grid);
                } else {
                    move(i + 2, j, grid);
                }
            }
            if (j + 1 <= m) {
                if (grid[i][j + 1] == 0) {
                    move(i, j + 1, grid);
                } else {
                    move(i, j + 2, grid);
                }
            }
        }
    }
}


