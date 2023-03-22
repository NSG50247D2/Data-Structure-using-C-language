// Minimum Span Tree

#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int src,dst,wt;
    struct node *next;
}node;

node *insert(node *root)
{
    node *p = (node *)malloc(sizeof(node));
    printf("Enter Source: ");
    scanf("%d", &(p->src));
    printf("Enter Destination: ");
    scanf("%d", &(p->dst));
    printf("Enter Weight: ");
    scanf("%d",&(p->wt));
    node *temp = root, *prev = NULL;
    while (temp && temp->wt < p->wt)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
    {
        p->next = root;
        root = p;
    }
    else
    {
        p->next = temp;
        prev->next = p;
    }
    return root;
}

int loop(int src, int dest, int arr[100][100]){
    int flag=1;
    for (int i = 0; i < 100; i++)
    {
        if (arr[src][i] && arr[dest][i])
        {
            return 0;
        }
        if(arr[src][i]){
            arr[src][i]=arr[i][src]=0;
            flag=loop(i,dest,arr);
            arr[src][i]=arr[i][src]=1;
        }
    }
    return flag;
}

void display(node *root,int n)
{
    int arr[100][100] = {0};
    while (root && n != 1)
    {
        if ( loop(root->src,root->dst,arr) )
        {
            arr[root->src][root->dst]++;
            arr[root->dst][root->src]++;
            printf("%d %d : %d\n", root->src, root->dst, root->wt);
            --n;
        }
        root = root->next;
    }
}

int main()
{
    node *root=NULL;
    int ch,n;
    printf("Enter No. of Vertices: ");
    scanf("%d", &n);
    do
    {
        printf("Enter 1 for insert, 2 for dsiplay, 3 for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: root=insert(root);
                    break;
            case 2: display(root,n);
                    break;
            case 3:exit(0);
        }
    }while(1);
    return 0;
}