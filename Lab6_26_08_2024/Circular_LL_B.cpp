//Implementation of round-robin scheduling algorithm using the circular linked list.

#include <stdio.h>
#include <stdlib.h>

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

    bool ins_end(int);
    int del_beg();
    bool isEmpty();
    void display();
};

// INSERT AT THE END: O(N)
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

// DELETE AT THE BEGINNING: O(N)
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
        Node *delNode = head;
        data = head->data;
        head = head->next;
        temp->next = head;
        free(delNode);
    }
    return data;
}

// CHECK IF NULL: O(1)
bool CircularList::isEmpty()
{
    return head == NULL;
}

// DISPLAY: O(N)
void CircularList::display()
{
    if (head == NULL)
    {
        printf("No processes in the queue.\n");
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
    CircularList queue;
    int timeSlot, ch, time;

    printf("Enter the fixed time slot for processes: ");
    scanf("%d", &timeSlot);

    while (1)
    {
        printf("\n1. Insert Process\n2. Execute\n3. Exit\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the time required for the process: ");
            scanf("%d", &time);
            queue.ins_end(time);
            break;

        case 2:
            if (queue.isEmpty())
            {
                printf("No processes to execute.\n");
            }
            else
            {
                time = queue.del_beg();
                time -= timeSlot;
                if (time > 0)
                {
                    printf("Process not completed. Remaining time: %d\n", time);
                    queue.ins_end(time);
                }
                else
                {
                    printf("Process completed.\n");
                }
            }
            break;

        case 3:
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }
}
