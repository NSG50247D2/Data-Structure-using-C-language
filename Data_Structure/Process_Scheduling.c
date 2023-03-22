//  Process Scheduling

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int process;
    int time;
    struct node *next;
}node;

node *insert(node *head){
    node *p;
    p=(node *)malloc(sizeof(node));
    int time,process;
    printf("Enter the process number: ");
    scanf("%d",&process);
    printf("Enter time for the process to complete: ");
    scanf("%d",&time);
    p->process=process;
    p->time=time;
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

void timeTaken(node *head,int ts)
{
    int tt=0;
    node *prev;
    while (!0){
        if(head->time>=ts){
            head->time=head->time-ts;
            tt=tt+ts;
        }
        else{
            tt=head->time+tt;
            head->time=0;
        }
        if(head->time==0){
            printf("Process %d is completed in %d ms\n",head->process,tt);
            if(head->next==head){
                break;
            }
            else{
                node *temp=head;
                prev->next=head->next;
                head=head->next;
                free(temp);
            }
        }
        else{
            prev=head;
            head=head->next;
        }
    }
    printf("Total time taken by all the processes is %d ms\n",tt);
}

int main()
{
    node *head=NULL;
    int ch,n,ts;
    do{
        printf("1 for insert, 2 for displaying_Time , 3 for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter total number of process: ");
                    scanf("%d",&n);
                    for(int i=0;i<n;i++){
                        head=insert(head);
                    }
                    break;
            case 2: printf("Enter time slot for each process by the cpu: ");
                    scanf("%d",&ts);
                    timeTaken(head,ts);
                    break;
            case 3: exit(0);
            default:printf("Invalid argument.\n");
                    break;
        }
    }while(!0);
    return 0;
}