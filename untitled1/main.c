#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *word, *t;
    word = (char *) malloc(200);
    printf("%s", "Input string: ");
    scanf("%s", word);
    char *f = strchr(word, 'A');
        while (f) {
        if (*(f + 1) == 'B') {
            t = f;
            while (*(t + 1) != 0) {
                *t = *(t + 2);
                t++;
            }
        } else f++;
        f = strchr(f, 'A');
    }
    printf("%s %s", "\n\"AB\" removed: ", word);
    free(word);
    return 0;
}