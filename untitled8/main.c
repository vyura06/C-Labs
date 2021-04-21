#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Введите 5-тизначное число: ");
    char *x;
    x = (char*)malloc(5);
    scanf("%s",x);
    char *y=0;
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
           x[i] = y[j];
            printf("a= \n", y[j]);
        }
    }
    return 0;
}
