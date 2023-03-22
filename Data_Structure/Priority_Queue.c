//  Priority Queue using Link list

#include <stdio.h>
#include<stdlib.h>
#define max 5

struct node{
    int val;
    int pri;
};

int Insert(struct node arr[],int rear, int front){
    if(front==0 && rear==(max-1)){
        printf("Queue is overflow.\n");
    }
    else{
        int va,pr,i,nl=0;
        printf("Enter value and its priority: ");
        scanf("%d %d",&va,&pr);
        if(front==-1){
            rear=0;
            arr[rear].val=va;
            arr[rear].pri=pr;
            
        }
        else{
            if(rear==max-1){
                for(int i=0;i<=rear;i++){
                   arr[i-1]=arr[i];
                }
                front--;
                rear--;
            }
            for(i=rear;i>=front;i--){
                if(arr[i].pri<pr){
                    break;
                }
            }
            nl=i+1;
            for(i=rear;i>=nl;i--){
                arr[i+1]=arr[i];
            }
            arr[nl].val=va;
            arr[nl].pri=pr;
            rear++;
        }
    }
    return rear;
}

int Delete(struct node arr[max],int rear,int front){
    if(front==-1){
        printf("Queue is underflow.\n");
    }
    else{
            printf("Deleted element is %d\n",arr[front].val);
            front++;
    }
    return front;
}

void Display(struct node arr[max],int rear, int front){
    if(front==-1){
        printf("Queue is empty.\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",arr[i].val);
        }
    }
    printf("\n");
}

int main()
{
    struct node arr[max];
    int ch, rear = -1, front = -1;
    do
    {
        printf("Enter 1 for Insert, 2 for Delete, 3 for Display, 4 for exit from the program: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            rear = Insert(arr, rear, front);
            if (rear == 0)
            {
                front=0;
            }
            break;
        case 2:
            if (front == max)
            {
                rear = front = -1;
            }
            front = Delete(arr, rear, front);
            break;
        case 3:
            Display(arr, rear, front);
            break;
        case 4:
            exit(0);
        }
    } while (1);
    return 0;
}