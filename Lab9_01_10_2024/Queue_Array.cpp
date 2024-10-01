/*
A. Write a separate C++ menu-driven program to implement Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit

What is the time complexity of each of the operations?
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

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
    void display();
};

int main()
{
    queue l1;
    int choice;
    int element;
    int pos;
    while (1)
    {

        printf("\n Queue \n");
        printf("\n 1.Enqueue \n 2.Dequeue \n 3.Peek \n 4.Exit \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the numbers ");
            scanf(" %d", &element);
            if (l1.enqueue(element))
            {
                printf("\n Inserted successfully.\n");
            }
            else
            {
                printf("\n Insertion unsuccessful.\n");
            }
            break;

        case 2:
            if (l1.dequeue())
            {
                printf("\n Dequeue Succesful.\n");
            }
            else
            {
                printf("\n Queue empty.\n");
            }
            break;

        case 3:
            l1.peek();
            break;

        case 4:
            printf("PROGRAM ENDED\n");
            return 0;
        }
    }
}
