#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    struct Node* left;
    struct Node* right;
    int value;
};

struct Node* root = NULL;

int countLeafOf(struct Node* node) {
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return 1;
    else if (node->left == NULL)
        return countLeafOf(node->right);
    else if (node->right == NULL)
        return countLeafOf(node->left);
    else
        return countLeafOf(node->left) + countLeafOf(node->right);
}

void add(int value) {
    struct Node* node = root;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (node == NULL) {
        root = newNode;
    }
    else {
        int v = 0;
        struct Node* parent = NULL;
        do {
            parent = node;
            v = node->value;
            if (value < v) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        } while (node != NULL);
        if (value < v) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }
}

void printNode0(struct Node* node) {
    if (node->left != NULL) {
        printf_s("(");
        printNode0(node->left);
        printf_s(")<-");
    }
    printf_s("%d", node->value);
    if (node->right != NULL) {
        printf_s("->(");
        printNode0(node->right);
        printf_s(")");
    }
}
void print0() {
    if (root != NULL) {
        printNode0(root);
        printf_s("\n");
    }
    else {
        printf_s("[]");
    }
}

void clearBuffer(char* buffer, int bufferSize)
{
    for (int i = 0; i < bufferSize; i++)
        buffer[i] = '\0';
}

int main() {
    add(4);
    add(7);
    add(5);
    add(1);
    add(3);
    add(8);
    const int bufferSize = 100;
    char *buffer = (char *) malloc(sizeof(char) * bufferSize);
    int temp = 0;
    char inLoop = 1;
    while (inLoop) {
        printf_s("Enter opetion:\nAdd = 1\nGet count leafs node = 2\nPrint tree = 3\nExit = 4\n");
        clearBuffer(buffer, bufferSize);
        scanf_s("%s", buffer, 99);
        if (strcmp("1", buffer) == 0) {
            printf_s("Enter value\n");
            scanf_s("%d", &temp);
            add(temp);
        }
        else if (strcmp("2", buffer) == 0) {
            int leafs = countLeafOf(root);
            printf_s("Count leaf is: %d\n", leafs);
        }
        else if (strcmp("3", buffer) == 0) {
            print0();
        }
        else if (strcmp("4", buffer) == 0) {
            inLoop = 0;
        }
        else {
            printf_s("Line is not correct\n");
        }
    }
    return 0;
}