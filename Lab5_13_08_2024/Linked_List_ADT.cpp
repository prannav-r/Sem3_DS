//

#include <stdio.h>
#include <stdlib.h>
#define np 0      //defining a default error code value

class List
{
    struct node
    {
        int data;
        struct node *next;
    }*head;
    public:
        List()
        {
            head=NULL;
        }
        void display();
        bool ins_beg(int);
        bool ins_end(int);
        bool ins_pos(int,int);
};

void List :: display()
{
    struct node *temp = head;  
      
    if(head == NULL) {  
        printf("List is empty");  
        return;
    }  
    printf("Linked list: [");  
    while(temp != NULL)
    {
        printf("%d, ", temp->data);  
        temp = temp->next;  
    }
    printf("]");
}


bool List :: ins_beg(int num)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return 1;
}

bool List :: ins_end(int num)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = num;
    newnode -> next = NULL;
    if(head == NULL)
        head = newnode;
    else
    {
    struct node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    return 1;
    }
}

bool List :: ins_pos(int num,int pos)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = num;
    newnode -> next = NULL;
    
}

int main(){
    int ch,num,pos,dn;
    List l1;   //Creating a List Object l1.
    while(true){
        printf("\n1.Display the List\n2.Insert at Beginning\n3.Insert at End\n");
        printf("4.Insert at Position\n5.Delete at Beginning\n6.Pop Element\n");
        printf("7.Delete at Position\n8.Exit\nEnter the choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            l1.display();
            break;

        case 2:
            printf("Enter the number to insert: ");
            scanf("%d",&num);
            if (l1.ins_beg(num))
                printf("Succesfully inserted %d",num);
            break;

        case 3:
            printf("Enter the number to insert: ");
            scanf("%d",&num);
            if (l1.ins_end(num))
                printf("Succesfully inserted %d",num);
            break;
        
        case 4:
            printf("Enter the number to insert: ");
            scanf("%d",&num);
            printf("Enter the position(index) to insert: ");
            scanf("%d",&pos);
            if((l1.ins_pos(num,pos)))
                printf("Succesfully inserted %d",num);
            break;

        default:
            printf("Please Enter a Valid Choice!");
            break;
        }
    }
}