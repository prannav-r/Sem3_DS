#include <stdio.h>
#include <stdlib.h>

class List {
    int cur;
    struct node
    {
        int data;
        struct node *next;
    } *head;

    node* gethead() {
        return head;
    }

public:
    List()
    {
        head = NULL;
        cur = -1;
    }
    void display();
    void insert_asc(int);
    void merge(List &l1, List &l2);

    
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

void List::insert_asc(int num)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL || head->data >= num) {
        newnode->next = head;
        head = newnode;
    } 
    else {
        struct node *temp = head;
        while (temp->next != NULL && temp->next->data < num) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    cur++;
}

    
void List::merge(List &l1, List &l2)
{
    struct node *temp1 = l1.gethead();
    struct node *temp2 = l2.gethead();
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data < temp2->data) {
            insert_asc(temp1->data);
            temp1 = temp1->next;
        } 
        else {
            insert_asc(temp2->data);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insert_asc(temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insert_asc(temp2->data);
        temp2 = temp2->next;
    }
}