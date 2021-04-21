#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[64];
    char author[64];
    char studens[64];
    int price;
} teams;

int main (void)
{
    int numbers;
    printf("Enter the number of teams = ");
    scanf("%d", &numbers);
    if (numbers < 1) {
        printf("Error! \n""Wrong amount.\n");
        return 1;
    }
    teams * a = NULL;
    if ((a = (teams *) malloc (numbers * sizeof(teams))) == NULL) {
        printf("Error allocate memory.\n");
        return 1;
    }

    int i;
    char scrap[80];
    for (i=0; i<numbers; i++)
    {
        fgets(scrap, 80, stdin);
        printf("\nInput information about teams %d:\n", i+1);
        printf("author:\n");   fgets(a[i].author, 64, stdin);
        printf("name:\n");   fgets(a[i].name, 64, stdin);
        printf("price:\n ");   scanf("%d", &a[i].price);
    }

    int max = 0;            // находим максимальную цену
    for (i=1; i<numbers; i++)
        if (a[i].price > a[max].price)
            max = i;

    printf("\nresult:\n\tmost price: %d\n", a[max].price);
    printf("\tauthor: %s", a[max].author);
    printf("\tname: %s", a[max].name);

    free(a);                // освобождаем память и выходим
    return 0;
}