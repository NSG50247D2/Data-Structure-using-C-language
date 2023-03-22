// Stack using array

#include <stdio.h>
#include <stdlib.h>

#define max 5 // Maximum Stack size is 5

int push(int arr[], int top)
{
    if (top == (max - 1))
    {
        printf("Stack is overflow.\n");
    }
    else
    {
        top = top + 1;
        int val;
        printf("Enter value to insert in the stack: ");
        scanf("%d", &val);
        arr[top] = val;
    }
    return top;
}

int pop(int arr[], int top)
{
    if (top == (-1))
    {
        printf("Stack is underflow.\n");
    }
    else
    {
        printf("Deleted element is %d\n", arr[top]);
        top = top - 1;
    }
    return top;
}

void display(int arr[], int top)
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int a[max], n, top = -1;
    do
    {
        printf("Enter 1 for Push, Enter 2 for Pop, Enter 3 for Display, Enter 4 for exit from the program:  ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            top = push(a, top);
            break;
        case 2:
            top = pop(a, top);
            break;
        case 3:
            display(a, top);
            break;
        case 4:
            exit(0);
        }
    } while (1);
    return 0;
}
