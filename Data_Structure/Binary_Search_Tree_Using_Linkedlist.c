//BINARY SEARCH TREE using single pointer and other two function
/*
    1. Inorder Traversal
    2. Search for a key
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int info;
    struct tree *left,*right;
}tree;

tree *insert(tree *root,int val){
    tree *p=(tree *)malloc(sizeof(tree));
    p->info=val;
    p->right=NULL;
    p->left=NULL;
    if(root==NULL){
        root=p;
    }
    else{
        tree *temp=root,*temp2;
        while(temp){
            temp2=temp;
            if(val<temp->info){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        if(p->info>temp2->info){
            temp2->right=p;
        }
        else{
            temp2->left=p;
        }
    }
    return root;
}


void inorder(tree *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->info);
    inorder(root->right);
}


void search(tree *root){
    int sr,f=0;
    printf("Enter the value to search for: ");
    scanf("%d",&sr);
    tree *curr=root;
    while(curr)
    {
        if(sr>curr->info){
            curr=curr->right;
        }
        else if(sr<curr->info){
            curr=curr->left;
        }
        else{
            printf("Element is present:\n");
            f=1;
            break;
        }
    }
    if(f==0){
        printf("Element is not present:\n");
    }
}


int main()
{
    tree *root=NULL;int ch,val;
    do{
        printf("1 for insert,2 for search, 3 for inorder traversal, 4 for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the value: ");
                    scanf("%d",&val);
                    root=insert(root,val);
                    break;
            case 2: search(root);
                    break;
            case 3: inorder(root);
                    printf("\n");
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid argument.");
                    break;
        }
    }while(!0);
    return 0;
}