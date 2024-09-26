// C++ menu-driven program to implement List ADT using a doubly linked list.

#include <stdio.h>
#include <stdlib.h>
#define np 0

class Dlist
{
    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    } *head, *tail;

public:
    Dlist()
    {
        head = NULL;
        tail = NULL;
    }
    bool ins_beg(int num);
    bool ins_end(int num);
    bool ins_pos(int num, int pos);
    int del_beg();
    int del_end();
    int del_pos(int pos);
    int search(int num);
    void display();
};

void Dlist ::display()
{

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    // Forward Print code
    struct node *temp = head;
    printf("Linked List: ");
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);

    // Reverse Print code
    printf("Linked List (Reversed): ");
    while (temp->prev != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d", temp->data);
    void dis_rev();
}

bool Dlist ::ins_beg(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        tail = newnode;
        return 1;
    }
    else
    {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
        return 1;
    }
}

bool Dlist ::ins_end(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return 1;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        return 1;
    }
}

bool Dlist ::ins_pos(int num, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (pos == 0 || head == nullptr)
    {
        ins_beg(num);
    }

    if (newnode == nullptr)
    {
        return 0;
    }

    newnode->data = num;

    struct node *temp = head;

    for (int i = 1; i < pos; i++)
    {

        if (temp == nullptr)
        {
            return 0;
        }

        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return 0;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != nullptr)
    {
        temp->next->prev = newnode;
    }

    temp->next = newnode;

    return 1;
}

int Dlist ::del_beg()
{
    if (head == NULL)
        return np;

    else if (head->next == NULL)
    {
        int data = head->data;
        head = NULL;
        tail = NULL;
        return data;
    }

    else
    {
        int data = head->data;
        head = head->next;
        head->prev = NULL;
        return data;
    }
}

int Dlist ::del_end()
{
    struct node *temp = tail->prev;

    if (head == NULL)
    {
        printf("The list is empty.");
    }

    else if (head == tail)
    {
        return del_beg();
    }

    else
    {
        return temp->next->data;
        temp->next = NULL;
        tail = temp;
    }
}

int Dlist ::del_pos(int pos)
{
    int count = 0;
    struct node *temp = head;
    struct node *temp2;

    if (pos == 0)
    {
        return del_beg();
    }

    else
    {
        while (count < pos - 1)
        {
            temp = temp->next;
            count = count + 1;
        }

        if (temp->next != NULL)
        {
            temp2 = temp->next->next;
            temp->next = temp2;
            temp2->prev = temp;
            return 1;
        }

        else
        {
            return del_end();
        }
    }
}

int Dlist ::search(int num)
{
    if (head == nullptr)
    {
        return 0;
    }
    struct node *temp = head;
    int pos = 0;
    while (temp != nullptr && temp->data != num)
    {
        temp = temp->next;
        pos++;
    }
    if (temp == nullptr)
    {
        return 0;
    }
    return pos + 1;
}

int main()
{
    Dlist l1;
    int ch, num, dn, pos, sn;
    while (true)
    {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Delete at Beginning\n5.Delete at End\n");
        printf("6.Delete at Position\n7.Search\n8.Display\n9.Exit\nEnter the choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            if (!(l1.ins_beg(num)))
                printf("Can't insert %d. The list is full.\n", num);
            else
                printf("Succesfully inserted %d\n", num);
            break;

        case 2:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            if (!(l1.ins_end(num)))
                printf("Can't insert %d. The list is full.", num);
            else
                printf("Succesfully inserted %d", num);
            break;

        case 3:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            printf("Enter the position(index) to insert: ");
            scanf("%d", &pos);
            if (l1.ins_pos(num, pos))
            {
                printf("Successfully inserted %d\n", num);
            }
            break;

        case 4:
            dn = l1.del_beg();
            if (dn == np)
                printf("Can't delete. The list is empty.\n");
            else
                printf("Successfully deleted %d\n", dn);
            break;

        case 5:
            dn = l1.del_end();
            if (dn == -1)
                printf("Can't delete. The list is empty.");
            else
                printf("Successfully deleted %d", dn);
            break;

        case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            dn = l1.del_pos(pos);
            if (dn == -1)
                printf("Can't delete. The list is empty.");
            else
                printf("Successfully deleted %d", dn);
            break;

        case 7:
            printf("Enter number to search:");
            scanf("%d", &num);
            sn = l1.search(num);
            if (sn == -1)
            {
                printf("List is empty.");
            }
            else if (sn == -2)
            {
                printf("Number not found.");
            }
            else
            {
                printf("%d found at %d index position", num, sn);
            }
            break;

        case 8:
            l1.display();
            break;

        case 9:
            return 0;

        default:
            printf("Please Enter a Valid Choice!\n");
            break;
        }
    }
}