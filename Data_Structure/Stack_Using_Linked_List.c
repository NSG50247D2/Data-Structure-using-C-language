// Stack using Link list
#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *push(node *head){
    node *p;
    p=(node *)malloc(sizeof(node));
    int val;
    printf("Enter the value to store: ");
    scanf("%d",&val);
    p->info=val;
    p->next=NULL;
    if(head==NULL){
        head=p;
    }
    else{
        p->next=head;
        head=p;
    }
    return head;
}

node *pop(node *head){
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        node *temp=head;
        printf("Deleted element is %d",temp->info);
        head=head->next;
        free(temp);
    }
    return head;
}

void display(node *head){
    if(head==NULL){
        printf("Empty:\n");
    }
    else{
        node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    node *head=NULL;int ch;
    do{
        printf("1 for push, 2 for pop, 3 for display, 4 for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=push(head);
                    break;
            case 2: head=pop(head);
                    break;
            case 3: display(head);
                    break;
            case 4: exit(0);
            default: printf("Invalid input\n");
                    break;
        }
    }while(1);
    return 0;
}