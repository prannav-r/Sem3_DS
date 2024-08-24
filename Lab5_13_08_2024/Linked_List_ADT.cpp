//change

#include <stdio.h>
#include <stdlib.h>
#define np 0 // defining a default error code value

class List
{
    struct node
    {
        int data;
        struct node *next;
    } *head;

public:
    List()
    {
        head = NULL;
    }
    void display();
    bool ins_beg(int);
    bool ins_end(int);
    bool ins_pos(int, int);
    int del_beg();
    int del_end();
    int del_pos(int);
};

void List ::display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("Linked list: [");
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("]");
}

bool List ::ins_beg(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = head;
    head = newnode;
    return 1;
}

bool List ::ins_end(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL)
        head = newnode;
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        return 1;
    }
}

bool List::ins_pos(int num, int pos)
{
    if (pos < 0)
        return 0;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (pos == 0)
    {
        newnode->next = head;
        head = newnode;
        return 1;
    }

    struct node *current = head;
    for (int i = 0; i < pos - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
        return 0;

    newnode->next = current->next;
    current->next = newnode;
    return 1;
}

int List::del_beg()
{
    if (head == NULL)
        return np;

    struct node *temp = head;
    int data = temp->data;
    head = head->next;
    free(temp);
    return data;
}

int List::del_end()
{
    if (head == NULL)
        return np;

    struct node *current = head;
    if (current->next == NULL)
    {
        int data = head->data;
        free(head);
        head = NULL;
        return data;
    }

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    int data = current->next->data;
    free(current->next);
    current->next = NULL;
    return data;
}

int List::del_pos(int pos)
{
    printf("working");
}

int main()
{
    int ch, num, pos, dn;
    List l1; // Creating a List Object l1.
    while (true)
    {
        printf("\n\n1.Insert at Beginning\n2.Insert at End\n");
        printf("3.Insert at Position\n4.Delete at Beginning\n5.Pop Element\n");
        printf("6.Delete at Position\n7.Search Element\n8.Display the List\n");
        printf("Enter your choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            if (!(l1.ins_beg(num)))
                printf("Can't insert %d. The list is full.", num);
            else
                printf("Succesfully inserted %d", num);
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
            if (!(l1.ins_pos(num, pos)))
                printf("Can't insert %d. The list is full.", num);
            else
                printf("Succesfully inserted %d", num);
            break;

        case 4:
            dn = l1.del_beg();
            if (dn == np)
                printf("Can't delete. The list is empty.");
            else
                printf("Succesfully deleted %d", dn);
            break;

        case 5:
            dn = l1.del_end();
            if (dn == np)
                printf("Can't delete. The list is empty.");
            else
                printf("Succesfully deleted %d", dn);
            break;

        case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            dn = l1.del_pos(pos);
            if (dn == np)
                printf("Can't delete. The list is empty.");
            else
                printf("Succesfully inserted %d", dn);
            break;

        case 7:
            printf("Enter the number to search: ");
            scanf("%d", &num);
            dn = l1.del_pos(pos);
            if (dn == np)
                printf("Element not found ");
            else
                printf("Element found at position");
            break;

        case 8:
            l1.display();
            break;

        default:
            printf("Please Enter a Valid Choice!");
            break;
        }
    }
}