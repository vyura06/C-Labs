#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Person {
    char name;
    char *teamName;
    int weight;
};

char *nameMiddleWeightTeam;

 /*char *randChar() {
    char line = ('a' + rand() % ('z' - 'a'));//(char)('a' + rand() % ('z' - 'a' + 1));
    return line;
}*/

 char *randChar() {
     char *line = malloc(sizeof(char) * 9);
     for (int i = 0; i <= 8; i++) {
         if (i == 8) {
             line[i] = '\000';
         } else {
             line[i] = (char) ('a' + rand() % ('z' - 'a'));
         }
     }
     return line;
 }

double searchMiddleWeight(const char *teamName, struct Person *people) {
    double weight = 0;
    int sizePerson = 0;
    for (int i = 0; i < 10; i++) {
        if (people[i].teamName == teamName) {
            weight += people[i].weight;
            sizePerson++;
        }
    }
    return weight / sizePerson;
}

double searchWeight(struct Person *people) {
    double weight = searchMiddleWeight(people[0].teamName, people);
    nameMiddleWeightTeam = people[0].teamName;
    double thisWeight;
    char *teamName;
    for (int i = 1; i < 10; i++) {
        teamName = people[i].teamName;
        thisWeight = searchMiddleWeight(teamName, people);
        if (weight > thisWeight) {
            weight = thisWeight;
            nameMiddleWeightTeam = teamName;
        }
    }
    return weight;
}

void fillStruct(struct Person people[10]) {
    for (int i = 0; i < 10; i++) {
        srand(time(0));
        people[i].name = randChar();
        people[i].teamName = randChar();
        people[i].weight = rand() % 200;
    }
}

void printResult(double middleWeight) {
    printf_s("Middle weight %f\nTeam name: %s\n", middleWeight, nameMiddleWeightTeam);
}


int main() {
    struct Person teams[10];
    fillStruct(teams);
    double middleWeight = searchWeight(teams);
    printResult(middleWeight);
    return 0;
}