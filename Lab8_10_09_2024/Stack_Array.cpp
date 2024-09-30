// C++ menu-driven program to implement stack ADT using a character array of size 5

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

class Array
{
    char arr[SIZE];
    int top;

public:
    Array()
    {
        top = -1;
    }
    char peek();
    int push(char element);
    char pop();
};

// Displaying the top of the Stack.
// Time complexity => O(1)
char Array ::peek()
{
    if (top == SIZE - 1)
        return 0;
    else
        return arr[top];
}

// Method to push into stack adt.
// Time complexity => O(1)
int Array ::push(char element)
{
    if (top == SIZE - 1)
    {
        return 0;
    }
    else if (top == -1)
    {
        top = 0;
        arr[0] = element;
        return 1;
    }
    else
    {
        top = top + 1;
        arr[top] = element;
        return 1;
    }
}

// Method to pop the element in stack adt.
// Time complexity => O(1)
char Array ::pop()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        top = top - 1;
        return arr[top];
    }
}

int main()
{
    int ch, pos, dn;
    char ele;
    Array l1; // Creating a List Object l1.
    while (true)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit\nEnter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the character to push: ");
            scanf("%c", &ele);
            if (l1.push(ele))
                printf("Succesfully Pushed %c", ele);
            break;

        case 2:
            dn = l1.pop();
            if (dn != 0)
            {
                printf("The Popped element is: ", dn);
                break;
            }
            else
                break;

        case 3:
            dn = l1.peek();
            if (dn != 0)
            {
                printf("The Topmost element is: ", dn);
                break;
            }
            else
                break;

        case 4:
            return 0;

        default:
            printf("Please Enter a Valid Choice!");
            break;
        }
    }
}