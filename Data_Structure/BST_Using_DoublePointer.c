//Creating BINARY SEARCH TREE using double pointer with following other functions
/*
    1. Inorder Traversal
    2. Preorder Traversal
    3. Postorder Traversal
    4. Count total node
    5. Count leaf node
    6. Count Node With one child
    7. Print node with two child
    8. Print even number
    9. Delete a node(include function to find inorder successor)
    10. Level Traversal of BST(include function to calculate height of BST)
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct tree{
    int info;
    struct tree *left,*right;
}tree;

tree *create(int x)
{
    tree *p;
    p = (tree *)malloc(sizeof(tree));
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

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

void inorder(tree *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->info);
    inorder(root->right);
}

void preorder(tree *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->info);
    preorder(root->left);
    preorder(root->right);
}

void postorder(tree *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->info);
}

void countNode(tree *root,int *tn){
    tree *temp=root;
    if(root==NULL){
        return;
    }
    countNode(temp->left,tn);
    countNode(temp->right,tn);
    *tn=*tn+1;
}

void countLeafNode(tree *root,int *ln){
    tree *temp=root;
    if(root==NULL){
        return;
    }
    if(temp->left==NULL && temp->right==NULL){
        *ln=*ln+1;
    }
    countLeafNode(temp->left,ln);
    countLeafNode(temp->right,ln);
}

void countOneChild(tree *root,int *oc){
    tree *temp=root;
    if(root==NULL){
        return;
    }
    if((temp->left==NULL && temp->right!=NULL) || (temp->left!=NULL && temp->right==NULL)){
        *oc=*oc+1;
    }
    countOneChild(temp->left,oc);
    countOneChild(temp->right,oc);
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

tree *inorderSuccessor(tree *curr)
{
    tree *temp=curr;
    while(temp && temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

tree *delete(tree *root,int key)
{
    if(root==NULL)
    {
        printf("Tree is empty.\n");
    }
    else if(root->info < key)
    {
        root->right=delete(root->right,key);
    }
    else if(root->info > key)
    {
        root->left=delete(root->left,key);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            tree *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            tree *temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            tree *temp=inorderSuccessor(root->right);
            root->info=temp->info;
            root->right=delete(root->right,key);
        }
    }
    return root;
}

int height(tree *root)
{
    tree *temp=root;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int lh=height(temp->left);
        int rh=height(temp->right);
        if(lh>rh)
        {
            return (lh+1);
        }
        else
        {
            return (rh+1);
        }
    }
}

void printCurrentLevel(tree *root,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(level==1)
    {
        printf("%d ",root->info);
    }
    else
    {
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

void printLevelOrder(tree *root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        printCurrentLevel(root,i);
    }
}
void frame(){

}

int main()
{
    tree *root=NULL,*temp;int ch,key,tn=0,ln=0,oc=0,h=0;
    do{
        printf("1 for insert,2 for inorder, 3 for preorder, 4 for postorder, 5 for one counting total node, 6 for counting leaf node, 7 for counting one child node, 8 for level order traversal, 9 for print two child nodes, 10 for printing even nodes, 11 for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the key: ");
                    scanf("%d",&key);
                    temp=create(key);
                    insert(&root,temp);
                    break;
            case 2: inorder(root);
                    printf("\n");
                    break;
            case 3: preorder(root);
                    printf("\n");
                    break;
            case 4: postorder(root);
                    printf("\n");
                    break;
            case 5:countNode(root,&tn);
                    printf("Total nodes = %d\n",tn);
                    break;
            case 6: countLeafNode(root,&ln);
                    printf("Total Leaf Nodes = %d\n",ln);
                    break;
            case 7: countOneChild(root,&oc);
                    printf("Total nodes having one child = %d\n",oc);
                    break;
            case 8: printLevelOrder(root);
                    break;
            case 9: printTwoChild(root);
                    break;
            case 10: printEven(root);
                    break; 
            case 11: exit(0);
                    break;
            default: printf("Invalid argument.");
                    break;
        }
    }while(!0);
    return 0;
}