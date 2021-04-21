#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubble(char *chars, int length);

int toRemoveDuplicate(char *text, int length){
    int j=0;
        for(int i=0;i<length;i++){
            if(text[i]!=text[i+1]){
                text[j]=text[i];
                j++;
            }
        }
        text[j] = 0;
    return 0;
    }

int main() {
    int size = 80;
    char *text = (char *) malloc(size * sizeof(char));
    FILE *input = fopen("D:\\101.txt", "r");
    FILE *output = fopen("D:\\102.txt", "w");
    if (input != NULL && output != NULL) {
        for (int i = 0; i < size; i++)
            text[i] = '\0';
        fgets(text, size, input);
        bubble(text, strlen(text));
        toRemoveDuplicate(text,strlen(text));
        fputs(text, output);
        fclose(input);
        fclose(output);
        free(text);
        printf("%s","String transfer complete");
    }
}

void bubble(char *chars, int length) {
    int i, j;
    char temp;
    for (i = 0; i < length - 1; i++) {
        for (j = length - 2; j >= i; j--) {
            if (chars[j] > chars[j + 1]) {
                temp = chars[j];
                chars[j] = chars[j + 1];
                chars[j + 1] = temp;
            }
        }
    }
}