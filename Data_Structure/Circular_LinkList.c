// Circular Link List creation with delete function

#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *insert(node *head){
    int val;
    printf("Enter the value to store: ");
    scanf("%d",&val);
    node *p=(node *)malloc(sizeof(node));
    p->next=NULL;
    p->info=val;
    if(head==NULL){
        head=p;
    }
    else{
        node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=p;
    }
    p->next=head;
    return head;
}

void display(node *head){
    if(head==NULL){
        printf("Link list is empty");
    }
    else{
        node *temp=head;
        do{
            printf("%d ",temp->info);
            temp=temp->next;
        }while(temp!=head);
    }
    printf("\n");
}

// Function to delete first node
node *deleteFirst(node *head)
{
    if(head==NULL)
    {
        printf("Empty.\n");
        return NULL;
    }
    else
    {
        node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        node *t2=head;
        if(temp==head)
        {
            free(temp);
            return NULL;
        }
        else
        {
            head=temp->next->next;
            temp->next=head;
        }
        free(t2);
    }
    return head;
}


// Function to delete a specific node
void searchDelete(node **head)
{
    if(*head==NULL)
    {
        printf("Empty.\n");
    }
    else
    {
        node *temp=*head,*temp2=*head;
        int i=1;
        printf("Enter pos: ");
        int pos;
        scanf("%d",&pos);
        if(pos==1)
        {
            printf("Del = %d",temp->info);
            *head=temp->next;
            free(temp);
        }
        else
        {
            while(i<pos)
            {
                temp2=temp;
                temp=temp->next;
            }
            temp2->next=temp->next->next;
            free(temp);
        }
    }
}

// Function to delete last node
node *deleteLast(node *head){
    if(head==NULL){
        printf("Link list is empty\n");
    }
    else{
        node *temp=head,*temp2;
        while(temp->next!=head){
            temp2=temp;
            temp=temp->next;
        }
        printf("Deleted element: %d\n",temp->info);
        if(temp==head){
            head=NULL;
        }
        else{
            temp2->next=head;
        }
        free(temp);
    }
    return head;
}


int main()
{
    node *head=NULL;
    int c;
    do{
        printf("1 for insert, 2 for display, 3 for delete first node, 4 4 for delete last node, 5 for search position and delete node, 6 for exit: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=deleteFirst(head);
                    break;
            case 4: head=deleteLast(head);
                    break;
            case 5: searchDelete(head);
                    break;
            case 6: exit(0);
            default: printf("Invalid Argument!");
        }
    }while(1);

    return 0;
}