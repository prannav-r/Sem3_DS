// C++ menu-driven program to implement stack ADT using a character array of size 5

#include <stdio.h>
#define size 5
#define np 0

class Array
{
    int arr[size];
    int cur;

public:
    Array()
    {
        cur = -1;
    }
    void peek();
    int push(int num);
    int pop();
};

void Array ::peek()
{
    printf("%d", arr[cur]);
}

int main()
{
    int ch, num, pos, dn;
    Array l1; // Creating a List Object l1.
    while (true)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit\nEnter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            if (!(l1.push(num)))
                printf("Can't insert %d. The list is full.", num);
            else
                printf("Succesfully inserted %d", num);
            break;

        case 2:
            dn = l1.pop();
            if (dn != np)
                printf("Can't insert %d. The list is full.", num);
            else
                printf("Succesfully inserted %d", num);
            break;

        case 3:
            l1.peek();
            break;

        default:
            printf("Please Enter a Valid Choice!");
            break;
        }
    }
}