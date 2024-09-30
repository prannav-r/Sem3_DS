// C++ menu-driven program to implement stack ADT using a singly linked list

#include <stdio.h>
#include <stdlib.h>

class list
{
    struct Node
    {
        int data;
        struct Node *next;
    };

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head;

public:
    list()
    {
        head = NULL;
    }
    int push(char);
    char pop();
    void peek();
};

int main()
{
    list l1;
    int choice;
    char element, dn;
    int pos;

    while (true)
    {
        printf("\n 1. Push \n 2. Pop \n 3. Peek \n 4. Exit \nEnter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the character ");
            scanf(" %c", &element);
            if (l1.push(element))
            {
                printf("\n Inserted successfully.\n");
            }
            else
            {
                printf("\n Insertion unsuccessful.\n");
            }
            break;

        case 2:
            dn = l1.pop();
            if (dn != 0)
            {
                printf("\nThe Popped Element is :", dn);
            }
            else
            {
                printf("\n Stack empty.\n");
            }
            break;

        case 3:
            l1.peek();
            break;

        case 4:
            return 0;
        }
    }
}

// Pushing the element into the singly linked list.
// Time complexity => O(1)
int list::push(char element)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = head;
    head = newnode;
    return 1;
}

// Popping the element from the singly linked list.
// Time complexity => O(1)
char list::pop()
{
    struct Node *temp;
    struct Node *temp2;
    if (head == NULL)
    {
        printf("The list is empty.");
        return 0;
    }

    else
    {
        temp2 = head;      // temp2 stores the memory address of 0 element
        temp = head->next; // temp stores the memory of 1 element
        head = temp;
        free(temp2);
        return temp->data;
    }
}

// Displaying the top of the singly linked list.
// Time complexity => O(1)
void list::peek()
{
    if (head == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("%c", head->data);
    }
}