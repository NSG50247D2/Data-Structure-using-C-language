// Queue using Link list

#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *enqueue(node *rear){
    node *p=(node *)malloc(sizeof(node));
    int info;
    printf("enter ele: ");
    scanf("%d",&info);
    p->info=info;
    p->next=NULL;
    if(rear==NULL)
    {
        rear=p;
    }
    else{
        rear->next=p;
        rear=p;
    }
    return rear;
}

node *dequeue(node *front)
{
    if(front==NULL){
        printf("Empty: ");
        return NULL;
    }
    node *temp=front;
    printf("deleted ele: %d\n",temp->info);
    front=front->next;
    free(temp);
    return front;
}

void display(node *rear,node *front){
    if(front==NULL){
        printf("Empty:\n");
    }
    else{
        node *temp=front;
        while(temp!=rear->next){
            printf("%d ",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    node *front=NULL,*rear=NULL; int ch;
    do{
        printf("1 for enqueue, 2 for dequeue, 3 for display, 4 for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: rear=enqueue(rear);
                    if(rear!=NULL && front==NULL){
                        front=rear;
                    }
                    break;
            case 2: front=dequeue(front);
                    if(front==rear->next)
                    {
                        front=rear=NULL;
                    }
                    break;
            case 3: display(rear,front);
                    break;
            case 4: exit(0);
        }
    }while(1);
    return 0;
}