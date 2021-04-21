#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

unsigned int getLeafCount(struct node* node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right==NULL)
        return 1;
    else
        return getLeafCount(node->left)+
               getLeafCount(node->right);
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)
            malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
/*
int inputNumRight(int x) {
    x = 0;
    do {
        printf("%s\n", "Enter number of right: ");
        scanf_s("%d", &x);
        fflush(stdin);
    } while (x < 1);
    return x;
}

int inputNumLeft(int y) {
    y = 0;
    do {
        printf("%s\n", "Enter number of left: ");
        scanf_s("%d", &y);
        fflush(stdin);
    } while (y < 1);
    return y;
}
*/
/*void inputTreeLeft(struct node *root){
    for(int i = 0; i <= inputNumLeft() ; i++ ) {
        root->left = newNode(i);
        if(inputNumLeft() >= 2){
            root->left->left = newNode(i);
            root->left->right = newNode(i);
            if(inputNumLeft() >= 4){
                root->left->left->left = newNode(i);
                root->left->left->right = newNode(i);
                root->left->right->left = newNode(i);
                root->left->right->right = newNode(i);
            }
        }
    }
}

void inputTreeRight(struct node *root) {
    for(int j = 0; j < inputNumRight(); j++ ) {
        root->right = newNode(j);
        if(inputNumRight() >= 2){
            root->right->left = newNode(j);
            root->right->right = newNode(j);
            if(inputNumRight() >= 4){
                root->right->left->left = newNode(j);
                root->right->left->right = newNode(j);
                root->right->right->left = newNode(j);
                root->right->right->right = newNode(j);
            }
        }
    }
}
*/

int main()
{
    struct node *root = newNode(1);
    /*inputNumRight();
    inputNumLeft();*/
    int x = 2;
    int y = 3;
    for(int i = 0; i <= x ; i++ ) {
        root->left = newNode(i);
        if(x >= 2){
            root->left->left = newNode(i);
            root->left->right = newNode(i);
            if(x >= 4){
                root->left->left->left = newNode(i);
                root->left->left->right = newNode(i);
                root->left->right->left = newNode(i);
                root->left->right->right = newNode(i);
            }
        }
    }
    for(int j = 0; j < y; j++ ) {
        root->right = newNode(j);
        if(y >= 2){
            root->right->left = newNode(j);
            root->right->right = newNode(j);
            if(y >= 4){
                root->right->left->left = newNode(j);
                root->right->left->right = newNode(j);
                root->right->right->left = newNode(j);
                root->right->right->right = newNode(j);
            }
        }
    }
    printf_s("Leaf count of the tree is %d", getLeafCount(root));

    return 0;
}