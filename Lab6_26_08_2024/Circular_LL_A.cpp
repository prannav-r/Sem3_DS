// C++ menu-driven program to implement List ADT using a circular linked list.

#include <stdio.h>
#include <stdlib.h>
#define np 0 // defining a default error code value
#define np1 1

class CircularList
{
    struct Node
    {
        int data;
        Node *next;
    } *head;

public:
    CircularList()
    {
        head = NULL;
    }

    bool ins_beg(int);
    bool ins_end(int);
    bool ins_pos(int, int);
    int del_beg();
    int del_end();
    int del_pos(int);
    int search(int);
    void display();
};

// INSERT AT BEGINNING: O(N)
bool CircularList::ins_beg(int num)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = num;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    return true;
}

// INSERT AT END: O(N)
bool CircularList::ins_end(int num)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = num;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }
    return true;
}

// INSERT AT POSITION: O(N)
bool CircularList::ins_pos(int num, int pos)
{
    if (pos < 0)
    {
        return false;
    }

    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = num;

    if (pos == 0)
    {
        if (head == NULL)
        {
            newnode->next = newnode;
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }
        return true;
    }

    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (temp->next == head)
        {
            free(newnode);
            return false;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return true;
}

// DELETE AT BEGINNING: O(N)
int CircularList::del_beg()
{
    if (head == NULL)
    {
        return -1;
    }
    int data;
    if (head->next == head)
    {
        data = head->data;
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        data = head->data;
        Node *delNode = head;
        head = head->next;
        temp->next = head;
        free(delNode);
    }
    return data;
}

// DELETE AT END: O(N)
int CircularList::del_end()
{
    if (head == NULL)
    {
        return -1;
    }

    int data;
    if (head->next == head)
    {
        data = head->data;
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        data = delNode->data;
        temp->next = head;
        free(delNode);
    }
    return data;
}

// DELETE AT POSITION: O(N)
int CircularList::del_pos(int pos)
{
    if (head == NULL)
    {
        return -1;
    }

    if (pos == 0)
    {
        return del_beg();
    }

    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (temp->next == head)
        {
            return -1;
        }
        temp = temp->next;
    }

    Node *delNode = temp->next;
    if (delNode == head)
    {
        return -1;
    }

    temp->next = delNode->next;
    int data = delNode->data;
    free(delNode);

    return data;
}

// SEARCH FOR NUMBER: O(N)
int CircularList::search(int num)
{
    if (head == NULL)
    {
        return -1;
    }

    Node *temp = head;
    int index = 0;

    while (true)
    {
        if (temp->data == num)
        {
            return index;
        }
        temp = temp->next;
        index++;

        if (temp == head)
        {
            break;
        }
    }

    return -2;
}

// DISPLAY: O(N)
void CircularList::display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
}

int main()
{
    CircularList cl;
    int ch, num, dn, pos, sn;
    while (true)
    {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Delete at Beginning\n5.Delete at End\n");
        printf("6.Delete at Position\n7.Search\n8.Display\n9.Exit\nEnter the choice: \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            if (cl.ins_beg(num))
            {
                printf("Successfully inserted %d\n", num);
            }
            break;

        case 2:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            if (cl.ins_end(num))
            {
                printf("Successfully inserted %d\n", num);
            }
            break;

        case 3:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            printf("Enter the position(index) to insert: ");
            scanf("%d", &pos);
            if (cl.ins_pos(num, pos))
            {
                printf("Successfully inserted %d\n", num);
            }
            break;

        case 4:
            dn = cl.del_beg();
            if (dn == -1)
                printf("Can't delete. The list is empty.\n");
            else
                printf("Successfully deleted %d\n", dn);
            break;

        case 5:
            dn = cl.del_end();
            if (dn == -1)
                printf("Can't delete. The list is empty.");
            else
                printf("Successfully deleted %d", dn);
            break;

        case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            dn = cl.del_pos(pos);
            if (dn == -1)
                printf("Can't delete. The list is empty.");
            else
                printf("Successfully deleted %d", dn);
            break;

        case 7:
            printf("Enter number to search:");
            scanf("%d", &num);
            sn = cl.search(num);
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
            cl.display();
            break;

        case 9:
            return 0;

        default:
            printf("Please Enter a Valid Choice!\n");
            break;
        }
    }
}