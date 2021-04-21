#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct abit {
    char surname[20];
    char address[40];
    float avgMark;
};

void input(int*, char*);
struct abit* fillAbits(int);
float findAvgMark(struct abit*, int);
void sortAbits(struct abit*, int);
void task(struct abit*, int, float);

void gets(char surname[20]);

int main() {
    int amount;
    input(&amount, "Введите количество:");

    struct abit* abits = fillAbits(amount);

    float avgMarkGlobal = findAvgMark(abits, amount);

    sortAbits(abits, amount);
    task(abits, amount, avgMarkGlobal);
    return 0;
}

void input(int* var, char* str) {
    printf("%s\n", str);
    scanf("%d", var);
    while (*var < 2) {
        printf("%s", "vvedite naturalnoe chislo bolshe 1:\n");
        scanf("%d", var);
    }

    fflush(stdin);
}

struct abit* fillAbits(int amount) {
    struct abit *abits = (struct abit*)malloc(amount * sizeof(struct abit));
    for(int i = 0; i < amount; i++) {
        printf("vvedite familiyu abiturienta %d:\n", i+1);
        gets(abits[i].surname);
        printf("vvedite address abiturienta %d:\n", i+1);
        gets(abits[i].address);
        printf("vvedite srednyuu ocenku abiturienta %d:\n", i+1);
        scanf("%f", &(abits[i].avgMark));
        fflush(stdin);
    }
    return abits;
}

float findAvgMark(struct abit* abits, int amount) {
    float sum = 0;
    for(int i = 0; i < amount; i++) {
        sum += abits[i].avgMark;
    }
    sum /= amount;
    return sum;
}

void sortAbits(struct abit* abits, int amount) {
    int swapped;
    do {
        swapped = 0;
        for(int i = 1; i < amount; i++) {
            if(strcmp(abits[i-1].surname, abits[i].surname) > 0) {
                struct abit temp = abits[i-1];
                abits[i-1] = abits[i];
                abits[i] = temp;
                swapped = 1;
            }
        }
    } while(swapped);
}

void task(struct abit* abits, int amount, float avgMark) {
    printf("\nsrednyaya ocenka po univeru: %.1f\n", avgMark);
    printf("#\tFIO\t\tADR\t\tMARK\n");
    int j = 1;
    for(int i = 0; i < amount; i++) {
        if(abits[i].avgMark < avgMark)
            continue;
        printf("%d\t%s\t\t%s\t\t%.1f\n", j++, abits[i].surname, abits[i].address, abits[i].avgMark);
    }
}