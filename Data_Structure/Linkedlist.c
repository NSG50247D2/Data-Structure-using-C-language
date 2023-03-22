// Program to create a single Link List with following function
/*
    1. Delete first element
    2. Delete last element
    3. Delete middle element
    4. Pallindrome numbers
    5. Prime numbers
    6. Reverse Link list
    7. Print Link list in reverse
    8. Alternate Display
    9. Merge Two link list
    10. Delete duplicate 
    11. Delete Loop
    12. Search Delete
    
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *insert(node *head){
    node *p;
    p=(node *)malloc(sizeof(node));
    int val;
    printf("Enter the value: ");
    scanf("%d",&val);
    p->info=val;
    p->next=NULL;
    if(head==NULL){
        head=p;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=p;
    }
    return head;
}

void display(node *head){
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->info);
            temp=temp->next;
        }
    }
    printf("\n");
}

node  *deletefirst(node *head){
    if(head==NULL){
        printf("Empty: ");
        return NULL;
    }
    node *temp=head;
    head=head->next;
    free(temp);
    return head;
}

node *deleteLast(node *head){
    if(head==NULL){
        printf("Link list is empty\n");
    }
    else{
        node *temp=head,*temp2;
        while(temp->next!=NULL){
            temp2=temp;
            temp=temp->next;
        }
        printf("Deleted element: %d\n",temp->info);
        if(temp==head){
            head=NULL;
        }
        else{
            temp2->next=NULL;
        }
        free(temp);
    }
    return head;
}

void deleteMiddle(node *head)
{
    node *temp=head,*temp2=head,*temp3=head; int i=1;
    while(temp2!=NULL && temp2->next!=NULL){
        temp2=temp2->next->next;
        temp=temp->next;
        if(i!=1){
            temp3=temp3->next;
        }
        i++;
    }
    temp3->next=temp->next;
    printf("Deleted element is %d\n",temp->info);
    free(temp);

}

void pallin(node *head){
    if(head==NULL){
        printf("Empty.\n");
    }
    else{
        node *temp=head;int s,z;
        do{
            s=0;
            int t=temp->info;
            while(temp->info){
                z=temp->info%10;
                s=s*10+z;
                temp->info=temp->info/10;
            }
            if(s==t){
                printf("%d is pallindrome in link list\n",t);
            }
            temp->info=t;
            temp=temp->next;
        }while(temp!=NULL);
    }
}

void prime(node *head)
{
    if(head==NULL){
        printf("Empty: ");
    }
    else{
        node *temp=head;int flag;
        do{
            flag=1;
            for(int i=2;i<=(temp->info/2);i++){
                if(temp->info%i==0){
                    flag=0;
                }
            }
            if(flag==1 &&temp->info!=1){
                printf("%d is prime.\n",temp->info);
            }
            temp=temp->next;
        }while(temp!=NULL);
    }
}
node *reverse(node *head){
    node *prev=NULL;
    node *curr=head;
    node *next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void revDisplay(node *head)
{
    node *temp=head;
    if(head==NULL){
        return ;
    }
    else{
        revDisplay(temp->next);
    }
    printf("%d ",temp->info);
}

void alterDisplay(node *head)
{
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        node *temp=head;
        do{
            printf("%d ",temp->info);
            if(temp->next!=NULL){
                temp=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }while(temp!=NULL);
        printf("\n");
    }
}


void merge(node *head1,node *head2){
    if(head1==NULL || head2==NULL){
        printf("1 or both link list is empty so merge can not be done.\n");
    }
    else{
        node *temp1=head1;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=head2;
    }
}

void deleteDup(node *head)
{
    if(head==NULL){
        printf("empty.\n");
    }
    else{
        node *temp=head,*temp2,*dup;
        while(temp->next!=NULL && temp!=NULL){
            temp2=temp;
            while(temp2->next!=NULL){
                if(temp->info == temp2->next->info){
                    dup=temp2->next;
                    temp2->next=temp2->next->next;
                    free(dup);
                }
                else{
                    temp2=temp2->next;
                }
            }
            temp=temp->next;
        }
    }
}

void deleteloop(node *head){
    if(head==NULL){
        printf("empty.\n");
    }
    else{
        node *temp1=head,*temp2=head;
        while(temp1 && temp2 && temp2->next)
        {
            temp1=temp1->next;
            temp2=temp2->next->next;
            if(temp1==temp2)
            {
                while(temp1->next!=temp2->next)
                {
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
                temp1->next=NULL;
            }
        }
    }
}

void searchDelete(node **head){
    if(*head==NULL){
        printf("Empty.\n");
    }
    else{
        int pos,i=1;
        printf("Enter pos to del: ");
        scanf("%d",&pos);
        node *temp=*head,*temp2=*head;
        if(pos==1){
            *head=temp->next;
            printf("Element del: %d\n",temp->info);
            free(temp);
        }
        else{
            int i=1;
            while(i<pos){
                temp2=temp;
                temp=temp->next;
                i++;
            }
            temp2->next=temp->next;
            printf("Element del: %d\n",temp->info);
            free(temp);
        }
    }
}

int main()
{
    node *head=NULL; int ch;
    node *head2=NULL;
    do{
        printf("1 for insert, 2 for display , 3 for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert(head);
                    // head2=insert(head2);
                    break;
            case 2: display(head);
                    // display(head2);
                    break;
            case 3: head=deletefirst(head);
                    break;
            case 4: head=deleteLast(head);
                    break;
            case 5: pallin(head);
                    break;
            case 6: prime(head);
                    break;
            case 7: head=reverse(head);
                    break;
            case 8: revDisplay(head);
                    printf("\n");
                    break;
            case 9: alterDisplay(head);
                    break;
            case 10:searchDelete(&head);
                    break;
            case 11: deleteMiddle(head);
                    break;
            case 12:merge(head,head2);
                    break;
            case 13: deleteDup(head);
                    break;
        }
    }while(1);
    
}