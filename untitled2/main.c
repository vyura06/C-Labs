#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 5

int sort(int *array) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    int a[N][M];
    int sc[M];
    int x, y;
    srand(time(NULL));
    for (x = 0; x < M; x++) sc[x] = 0;
    for (x = 0; x < N; x++) {
        for (y = 0; y < M; y++) {
            a[x][y] = rand() % 10;
            printf("%5d", a[x][y]);
            sc[y] += a[x][y];
        }
        printf("\n");
    }
    for (x = 0; x < M; x++)
        printf("%5s", "--");
    printf("\n");
    for (x = 0; x < M; x++)
        printf("%5d", sc[x]);
    printf("\n");
    int m[5];
    for (int z = 0; z < M; z++) {
        m[z] = sc[z];
    }
    sort(m);
    for (x = 0; x < M; x++)
        printf("%5s", "--");
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%5d", m[i]);
    }
    printf("\n");
    return 0;
}

