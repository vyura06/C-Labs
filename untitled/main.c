#include <math.h>
#include <stdio.h>

void isNatural(int n) {
    if (n > 0) {
        printf("Number is natural: ");
        printf("N = %d", n);
    }
}

int main() {
    int n;
    double x, y;
    printf(" Input natural number N: ");
    scanf("%d", &n);
    isNatural(n);
    for (int i = 1; i <= n; i++) {
        x = 1 / pow(i, 2);
        y = pow(-1, i) / (2 * i + 1) * i;
    }
    printf("\n X = %f", x);
    printf("\n Y = %f", y);
    return 0;

}

