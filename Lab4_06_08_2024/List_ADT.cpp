// C++ menu driven program to implement List ADT using arrays.

#include <stdio.h>
#include <stdlib.h>
#define size 10 // defining a static size
#define np 0    // defining a default error code value

// Creating a Class for List.
class List
{
    int arr[size];
    int cur;

public:
    List()
    {
        cur = -1;
    }
    void display();
    bool ins_beg(int);
    bool ins_end(int);
    bool ins_pos(int, int);
    int del_beg();
    int del_end();
    int del_pos(int);
};

// List Method to display the list elements.
void List::display()
{
    if (cur == -1)
        printf("List = []");
    else
    {
        printf("List = ");
        for (int i = 0; i <= cur - 1; i++)
        {
            printf("%d,", arr[i]);
        }
        printf("%d", arr[cur]);
    }
}

// List Method to Insert an Element at the beginning of the List.
bool List::ins_beg(int num)
{
    if (cur == size - 1)
        return 0;

    else if (cur == -1)
    {
        cur = 0;
        arr[0] = num;
        return 1;
    }
    else
    {
        for (int i = cur; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = num;
        cur++;
        return 1;
    }
}

// List Method to Insert an Element at the end of the List.
bool List ::ins_end(int num)
{
    if (cur == size - 1)
        return 0;

    else
    {
        arr[cur + 1] = num;
        cur++;
        return 1;
    }
}

// List Method to Insert an Element at the position specified in the List.
bool List ::ins_pos(int num, int pos)
{
    if (cur == size - 1 || pos > cur || pos < 0)
        return 0;

    else
    {
        for (int i = cur; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos] = num;
        cur++;
        return 1;
    }
}

// List Method to Delete an Element at the beginning of the List.
int List ::del_beg()
{
    if (cur == -1)
        return np;

    else
    {
        int temp = arr[0];
        for (int i = 0; i <= cur; i++)
        {
            arr[i] = arr[i + 1];
        }
        cur--;
        return temp;
    }
}

// List Method to Delete an Element at the end of the List.
int List ::del_end()
{
    if (cur == -1)
        return np;

    else
    {
        int temp = arr[cur];
        cur--;
        return temp;
    }
}

// List Method to Delete an Element at the position specified in the List.
int List ::del_pos(int pos)
{
    if (cur == -1)
        return np;

    else
    {
        int temp = arr[pos];
        for (int i = pos; i <= cur; i++)
        {
            arr[i] = arr[i + 1];
        }
        cur--;
        return temp;
    }
}

// Main
int main()
{
    int ch, num, pos, dn;
    List l1; // Creating a List Object l1.
    while (true)
    {
        printf("\n1.Display the List\n2.Insert at Beginning\n3.Insert at End\n");
        printf("4.Insert at Position\n5.Delete at Beginning\n6.Pop Element\n");
        printf("7.Delete at Position\n8.Exit\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            l1.display();
            break;

        case 2:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            if (!(l1.ins_beg(num)))
                printf("Can't insert %d. The list is full.", num);
            else
                printf("Succesfully inserted %d", num);
            break;

        case 3:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            if (!(l1.ins_end(num)))
                printf("Can't insert %d. The list is full.", num);
            else
                printf("Succesfully inserted %d", num);
            break;

        case 4:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            printf("Enter the position(index) to insert: ");
            scanf("%d", &pos);
            if (!(l1.ins_pos(num, pos)))
                printf("Can't insert %d. The list is full.", num);
            else
                printf("Succesfully inserted %d", num);
            break;

        case 5:
            dn = l1.del_beg();
            if (dn == np)
                printf("Can't delete. The list is empty.");
            else
                printf("Succesfully deleted %d", dn);
            break;

        case 6:
            dn = l1.del_end();
            if (dn == np)
                printf("Can't delete. The list is empty.");
            else
                printf("Succesfully deleted %d", dn);
            break;

        case 7:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            dn = l1.del_pos(pos);
            if (dn == np)
                printf("Can't delete. The list is empty.");
            else
                printf("Succesfully inserted %d", dn);
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Please Enter a Valid Choice!");
            break;
        }
    }
}