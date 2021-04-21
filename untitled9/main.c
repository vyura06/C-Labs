#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


struct Books {
    char author[100];
    char bookTitle[100];
    int year;
};

/*void output(int num, struct Books books[]) {
int i = 0;
do {
printf("Author: ");
printf("%s", books[i].author);
printf("; ");
printf("Book title: ");
printf("%s", books[i].bookTitle);
printf("; ");
printf("Book year: ");
printf("%d", books[i].year);
printf("; \n");
i++;
} while (i < num);
}*/

void output(struct Books books[], int i) {
    printf("Author: ");
    printf("%s", books[i].author);
    printf("; ");
    printf("Book title: ");
    printf("%s", books[i].bookTitle);
    printf("; ");
    printf("Book year: ");
    printf("%d", books[i].year);
    printf("; \n");
}

void searchBooks(int number, struct Books *books) {
    char author[100] = "";
    printf("Enter author(search): \n");
    scanf("%s", author);
    int i = 0;
    do {
        if (strcmp(books[i].author, author) == 0) {
            output(books, i);
        }
        i++;
    } while (i < number);
}

int getDigit() {
    int year = 0;
    do {
        printf("Enter book year: \n");
        scanf("%d", &year);
        fflush(stdin);
    } while (year < 1 || year > 2020);
    return year;
}

void input(int num, struct Books books[]) {
    int i = 0;
    do {
        struct Books book;
        printf("%s\n", "Enter author: ");
        scanf("%s", book.author);
        printf("%s\n", "Enter book title: ");
        scanf("%s", book.bookTitle);
        book.year = getDigit();
        books[i] = book;
        i++;
    } while (i < num);
}

int inputNum() {
    int num = 0;
    do {
        printf("%s\n", "Enter number of book: ");
        scanf("%d", &num);
        fflush(stdin);
    } while (num < 1);
    return num;
}

char *randChar() {
    char *line = malloc(sizeof(char) * 9);
    for (int i = 0; i <= 8; i++) {
        if (i == 8) {
            line[i] = '\000';
        } else {
            line[i] = (char) ('a' + rand() % ('z' - 'a' + 1));
        }
    }
    return line;
}

int main() {
    int number = inputNum();
    struct Books books[number];
    input(number, books);
    searchBooks(number, books);
    return 0;
}