/*
A. Write a separate C++ menu-driven program to implement Queue ADT using an integer array of size 5.
The Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit

What is the time complexity of each of the operations?
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define np 0

class queue
{
    int arr[SIZE];
    int front;
    int rear;

public:
    queue()
    {
        front = -1;
        rear = -1;
    }
    int isfull();
    int isempty();
    int enqueue(int);
    int dequeue();
    void peek();
};

int queue ::isfull()
{
    if (rear == SIZE - 1)
        return 1;

    else
        return 0;
}

int queue ::isempty()
{
    if ((front == -1 && rear == -1))
        return 1;

    else
        return 0;
}

int queue ::enqueue(int num)
{
    if (isfull())
        return 0;

    else if (isempty())
    {
        arr[0] = num;
        front = 0;
        rear = 0;
        return 1;
    }

    else
    {
        rear++;
        arr[rear] = num;
        return 1;
    }
}

int queue ::dequeue()
{
    int temp;
    if (isempty())
        return np;

    else if (front == rear)
    {
        temp = arr[front];
        front = rear = -1;
        return temp;
    }

    temp = arr[front];
    front++;
    return temp;
}

void queue ::peek()
{
    if (isempty())
        printf("Queue is Empty!\n");

    else
        printf("Front Element is: %d", arr[front]);
}

int main()
{
    queue l1;
    int ch;
    int num;
    int ans;
    while (true)
    {

        printf("\n Queue \n");
        printf("\n 1.Enqueue \n 2.Dequeue \n 3.Peek \n 4.Exit \n");
        printf("\n Enter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number: ");
            scanf(" %d", &num);
            if (l1.enqueue(num))
                printf("\n Inserted %d successfully.\n", num);

            else
                printf("\n Insertion unsuccessful. Array is Full.\n");
            break;

        case 2:
            ans = l1.dequeue();
            if (ans != np)
                printf("\n Dequeued %d", ans);

            else
                printf("\n Queue empty.\n");
            break;

        case 3:
            l1.peek();
            break;

        case 4:
            return 0;

        default:
            printf("Enter a valid choice!");
        }
    }
}