// Queue implementation using array
#include<stdio.h>
#include<stdlib.h>

#define max 5  // Maximum size of queue

int insert(int arr[],int rear){
    if(rear==max-1){
        printf("Queue is overflow\n");
    }
    else{
        rear++;
        int val;
        printf("Enter the value: ");
        scanf("%d",&val);
        arr[rear]=val;
    }
    return rear;
}

int delete(int arr[],int front){
    if(front==-1){
        printf("Queue is underflow\n");
    }
    else{
        printf("Deleted element is %d\n",arr[front]);
        front++;
    }
    return front;
}

void display(int arr[],int rear,int front){
    if(front==-1){
        printf("Queue is underflow.\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",arr[i]);
        }
    }
}

int main()
{
    int arr[max],rear=-1,front=-1,ch;
    do{
        printf("1 for insert, 2 for delete, 3 for display, 4 for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: rear=insert(arr,rear);
                    if(rear==0){
                        front =0;
                    }
                    break;
            case 2: front=delete(arr,front);
                    if(front==max){
                        rear=front=-1;
                    }
                    break;
            case 3: display(arr,rear,front);
                    break;
            case 4: exit(0);
        }
    }while(1);
}