/*
C. Write a separate C++ menu-driven program to implement Hash ADT with Quadratic Probing. Maintain proper boundary conditions and follow good coding practices. The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

What is the time complexity of each of the operations?
*/

#include <stdio.h>
#include <stdlib.h>
#define size 25

class hash
{
    int hashtable[size] = {0};

public:
    hash()
    {
        for (int i = 0; i < size; i++)
        {
            hashtable[i] = -1;
        }
    }
    int insert(int num);
    void display();
    int del(int num);
    int search(int num);
};

// Method to insert the element in hashtable.
// Time complexity => O(n) in the worst case
int hash::insert(int num)
{
    int index = num % size;

    if (hashtable[index] == -1)
    {
        hashtable[index] = num;
        return 1;
    }
    else
    {
        int i = 1;
        while (index != size - 1)
        {
            if (hashtable[index] == -1)
            {
                hashtable[index] = num;
                return 1;
            }
            index = i * i + index;
            i++;
        }
    }
    return 0;
}

// Method to display the elements in hashtable.
// Time complexity => O(n)
void hash::display()
{
    for (int i = 0; i < size; i++)
    {
        if (hashtable[i] != -1)
        {
            printf("%d\t", hashtable[i]);
        }
    }
}

// Method to delete a element in hashtable.
// Time complexity => O(n) in the worst case
int hash ::del(int num)
{
    int index = num % size;
    int i = 0;
    while (index < size - 1)
    {
        if (hashtable[index] == num)
        {
            hashtable[index] = -1;
            return 1;
        }
        else if (hashtable[index] == -1)
        {
            return 0;
        }
        index = i * i + index;
        i++;
    }
    return 0;
}

// Method to search an element in hashtable.
// Time complexity => O(n) in the worst case
int hash::search(int num)
{
    int index = num % size;
    int i = 0;
    while (index < size - 1)
    {
        if (hashtable[index] == num)
        {
            return 1;
        }
        else if (hashtable[index] == -1)
        {
            return 0;
        }
        index = i * i + index;
        i++;
    }
    return 0;
}

int main()
{
    hash h1;
    int choice;
    while (1)
    {
        printf("\n1) Insert");
        printf("\n2) Delete");
        printf("\n3) Search");
        printf("\n4) Display");
        printf("\n5) Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int num1;
            printf("Enter the number to insert :");
            scanf("%d", &num1);
            if (h1.insert(num1))
            {
                printf("%d inserted successfully\n", num1);
            }
            else
            {
                printf("Insertion unsuccessful\n");
            }
            break;

        case 2:
            int num2;
            printf("Enter the number to delete\n");
            scanf("%d", &num2);
            if (h1.del(num2))
            {
                printf("%d deleted successfully\n", num2);
            }
            else
            {
                printf("Element is not present\n");
            }
            break;

        case 3:
            int num3;
            printf("Enter the element to search :");
            scanf("%d", &num3);
            if (h1.search(num3))
            {
                printf("Element is found\n");
            }
            else
            {
                printf("Element is not found\n");
            }
            break;

        case 4:
            h1.display();
            break;

        case 5:
            printf("PROGRAM ENDED");
            return 0;
        }
    }
}
