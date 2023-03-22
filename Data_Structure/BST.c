//BST using double pointer
#include <stdio.h>
#include<stdlib.h>

//Declaring a structure of type tree
typedef struct tree{
    int info;
    struct tree *left,*right;
}tree;


//Function to create a new node to insert in BST
tree *create(int x)
{
    tree *p;
    p = (tree *)malloc(sizeof(tree));
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

//Function to add key in it's proper position
void insert(tree **root, tree *temp){
    if(*root==NULL){
        *root=temp;
    }
    else{
        if((temp->info)<((*root)->info)){
            insert(&((*root)->left),temp);
        }
        else{
            insert(&((*root)->right),temp);
        }
    }
}


void printTwoChild(tree *root){
    tree *temp=root;
    if(root==NULL){
        return;
    }
    if((temp->left!=NULL && temp->right!=NULL)){
        printf("%d ",temp->info);
    }
    printTwoChild(temp->left);
    printTwoChild(temp->right);
}

void printEven(tree *root)
{
    tree *temp=root;
    if(root==NULL){
        return;
    }
    if((temp->info%2==0)){
        printf("%d \n",temp->info);
    }
    printEven(temp->left);
    printEven(temp->right);
}

int main()
{
    tree *root=NULL,*temp;int ch,key;
    do{
        printf("1 for insert,2 for two child display,3 for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the value: ");
                    scanf("%d",&key);
                    temp=create(key);
                    insert(&root,temp);
                    break;
            case 2: printTwoChild(root);
                    printf("\n");
                    break;
            case 4: exit(0);
            default: printf("Invalid argument.");
                    break;
        }
    }while(!0);
    return 0;
}