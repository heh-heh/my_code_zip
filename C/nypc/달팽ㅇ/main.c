#include <stdio.h>

int main() {
    int a[5][5] = { 0, };
    int num = 1, x = 0, y = 0;
    int i, ii, j;
    int dir = 1;

    for (ii = 0; ii < 5; ++ii) {
        a[y][x] = num++;
        x += dir;
    }
    x -= 1;
    for (i = 5 - 1;i > 0; --i) {
        for (j = 0; j < i; ++j) {
            y += dir;
            a[y][x] = num++;
        }
        dir *= -1;
        for (ii = 0; ii < i; ++ii) {
            x += dir;
            a[y][x] = num++;
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%3d ", a[i][j]);
        }
        printf("\n\n");
    }
}
