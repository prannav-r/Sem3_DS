#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

class list
{
private:
    struct node
    {
        char data;
        struct node *prev;
    };
    struct node *top;

public:
    list()
    {
        top = NULL;
    }
    int push(char);
    char pop(void);
    char peek(void);
    void display(void);
};

// Push elements to the stack.
// Time complexity => O(1).
int list::push(char chr)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        return 0;
    }
    else
    {
        newnode->data = chr;
        newnode->prev = top;
        top = newnode;
        return 1;
    }
}

// Pop elements from the stack.
// Time complexity => O(1).
char list::pop(void)
{
    if (top == NULL)
    {
        return '\0';
    }
    else
    {
        char res = top->data;
        struct node *copy = top;
        top = top->prev;
        free(copy);
        return res;
    }
}

// Display elements in the stack.
// Time complexity => O(n).
void list::display(void)
{
    if (top == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        struct node *temp = top;
        while (temp != NULL)
        {
            printf("%c ", temp->data);
            temp = temp->prev;
        }
    }
}

// Peek of the stack.
// Time complexity => O(1)
char list::peek(void)
{
    if (top == NULL)
    {
        return '\0';
    }
    else
    {
        return top->data;
    }
}