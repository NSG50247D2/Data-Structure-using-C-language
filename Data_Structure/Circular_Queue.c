// Program to implement circular queue using array

#include<stdio.h>
#include<stdlib.h>

#define max 5

int insert(int arr[],int rear,int front){
    if((rear==max-1 && front==0)|| (rear==front-1) && front!=0){
        printf("Queue is overflow.\n");
    }
    else{
        int val;
        printf("Enter the value to be stored: ");
        scanf("%d",&val);
        if(rear==max-1){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=val;
    }
    return rear;
}

int delete(int arr[],int rear,int front){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Deleted element is %d\n",arr[front]);
        if(front==rear){
            front=-1;
        }
        else{
            front++;
        }
    }
    return front;
}

void display(int arr[],int rear,int front){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        if(front>rear){
            for(int i=front;i<=max-1;i++){
                printf("%d ",arr[i]);
            }
            for(int i=0;i<=rear;i++){
                printf("%d ",arr[i]);
            }
        }
        else{
            for(int i=front;i<=rear;i++){
                printf("%d ",arr[i]);
            }
        }
        printf("\n");
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
            case 1: rear=insert(arr,rear,front);
                    if(rear==0){
                        front = 0;
                    }
                    break;
            case 2: front=delete(arr,rear,front);
                    if(front==max && rear==max-1){
                        front=rear=-1;
                    }
                    if(front==-1){
                        rear=-1;
                    }
                    break;
            case 3: display(arr,rear,front);
                    break;
            case 4: exit(0);
        }
    }while(1);
}