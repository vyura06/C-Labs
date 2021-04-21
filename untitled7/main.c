#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Person {
    char *name;
    char *teamName;
    int weight;
};

char *nameTeamMinMiddleWeight;

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
    for (int i = 0; i < 20; i++) {
        if (people[i].teamName == teamName) {
            weight += people[i].weight;
            sizePerson++;
        }
    }
    return weight / sizePerson;
}

double searchWeight(struct Person *people) {
    double weight = searchMiddleWeight(people[0].teamName, people);
    nameTeamMinMiddleWeight = people[0].teamName;
    double thisWeight;
    char *teamName;
    for (int i = 1; i < 10; i++) {
        teamName = people[i].teamName;
        thisWeight = searchMiddleWeight(teamName, people);
        if (weight > thisWeight) {
            weight = thisWeight;
            nameTeamMinMiddleWeight = teamName;
        }
    }
    return weight;
}

void fillStruct(struct Person people[20]) {
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        people[i].name = randChar();
        people[i].teamName = randChar();
        people[i].weight = rand() % 200;
    }
}

void printStructPeople(struct Person people[10]) {
    printf_s("\nName\t\tTeam Name\t\tWeight\n\n");
    for (int i = 0; i < 20; i++) {
        printf_s("%s\t", people[i].name);
        printf_s("%s\t", people[i].teamName);
        printf_s("\t%d", people[i].weight);
        printf_s("\n");
    }
}


void printResult(double middleWeight) {
    printf_s("Middle weight %f\nTeam name: %s\n\n", middleWeight, nameTeamMinMiddleWeight);
}


int main() {
    struct Person people[10];
    fillStruct(people);
    double middleWeight = searchWeight(people);
    printResult(middleWeight);
    printStructPeople(people);
    return 0;
}