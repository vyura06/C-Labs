#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])

{
    printf("Enter number of options: ");

    int k = atoi(argv[1]);

    printf("Enter phone number: ");

    int x = atoi(argv[2]);

    if (argc != 3) {
        printf("Error!\n", stderr);
        exit(1);
    }

    if (strlen(argv[2]) != 7) {
        printf("Enter a seven-digit number!\n", stderr);
        exit(1);
    }

    int N = x % (k) + 1;

    printf("%d\n", N);

    return 0;

}