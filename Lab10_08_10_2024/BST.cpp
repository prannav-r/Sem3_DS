/*
C++ menu-driven program to implement Tree ADT using a binary search tree.
The Tree ADT has the following operations:

1. Insert
2. Preorder
3. Inorder
4. Postorder
5. Search
6. Exit

What is the time complexity of each of the operations?
*/

#include <stdio.h>
#include <stdlib.h>

class BST
{
private:
    struct Node
    {
        int data;
        struct Node *Left;
        struct Node *Right;
    };
    struct Node *Root;
    struct Node *NewNode;
    struct Node *Temp;
    struct Node *TempP;
    struct Node *createnode();
    void RecPreOrder(struct Node *);
    void RecInOrder(struct Node *);
    void RecPostOrder(struct Node *);
    int RecSearch(int, struct Node *);

public:
    BST()
    {
        Root = NULL;
        NewNode = NULL;
    }
    int Insert(int);
    int Delete(int);
    void PreOrder();
    void InOrder();
    void PostOrder();
    int Search(int);
};

struct BST::Node *BST::createnode()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

int BST::Insert(int val)
{
    NewNode = createnode();
    NewNode->data = val;
    NewNode->Left = nullptr;
    NewNode->Right = nullptr;
    if (Root == nullptr)
    {
        Root = NewNode;
        return 1;
    }
    else
    {
        Temp = Root;
        while (1 == 1)
        {
            if (Temp->data > val)
            {
                if (Temp->Left == nullptr)
                {
                    Temp->Left = NewNode;
                    return 1;
                }
                Temp = Temp->Left;
            }
            else
            {
                if (Temp->Right == nullptr)
                {
                    Temp->Right = NewNode;
                    return 1;
                }
                Temp = Temp->Right;
            }
        }
    }
    return 0;
}

// Method to print data of the tree recursively and INORDER
// Time Complexity => O(n)
void BST::RecInOrder(struct Node *Root)
{
    if (Root->Left != nullptr)
    {
        RecInOrder(Root->Left);
    }
    printf(" %d ", Root->data);
    if (Root->Right != nullptr)
    {
        RecInOrder(Root->Right);
    }
}

// Method to print data of tree INORDER
// Time Complexity => O(n)

void BST::InOrder()
{
    if (Root != nullptr)
    {
        RecInOrder(Root);
    }
    else
    {
        printf("Tree is Empty.");
    }
}

// Method to print data of the tree Recursively and PREORDER
// Time Complexity => O(n)

void BST::RecPreOrder(struct Node *Root)
{
    printf(" %d ", Root->data);
    if (Root->Left != nullptr)
    {
        RecPreOrder(Root->Left);
    }
    if (Root->Right != nullptr)
    {
        RecPreOrder(Root->Right);
    }
}

// Method to print data of tree PREORDER
// Time Complexity => O(n)

void BST::PreOrder()
{
    if (Root != nullptr)
    {
        RecPreOrder(Root);
    }
    else
    {
        printf("Tree is Empty.");
    }
}

// Method to print data of the tree Recursively and POSTORDER
// Time Complexity => O(n)

void BST::RecPostOrder(struct Node *Root)
{
    if (Root->Left != nullptr)
    {
        RecPostOrder(Root->Left);
    }
    if (Root->Right != nullptr)
    {
        RecPostOrder(Root->Right);
    }
    printf(" %d ", Root->data);
}

// Method to print data of tree POSTORDER
// Time Complexity => O(n)

void BST::PostOrder()
{
    if (Root != nullptr)
    {
        RecPostOrder(Root);
    }
    else
    {
        printf("Tree is Empty.");
    }
}

// Method to Delete a value form the tree
// Time Complexity => O(logn)
int BST::Delete(int val)
{
    struct Node *parent = nullptr;
    struct Node *current = Root;
    while (current != nullptr && current->data != val)
    {
        parent = current;
        if (val < current->data)
            current = current->Left;
        else
            current = current->Right;
    }
    if (current == nullptr)
        return 0;
    if (current->Left == nullptr && current->Right == nullptr)
    {
        if (current != Root)
        {
            if (parent->Left == current)
                parent->Left = nullptr;
            else
                parent->Right = nullptr;
        }
        else
        {
            Root = nullptr;
        }
        return 1;
        free(current);
    }
    else if (current->Left == nullptr || current->Right == nullptr)
    {
        struct Node *child = (current->Left != nullptr) ? current->Left : current->Right;
        if (current != Root)
        {
            if (current == parent->Left)
                parent->Left = child;
            else
                parent->Right = child;
        }
        else
        {
            Root = child;
        }
        return 1;
        free(current);
    }
    else
    {
        struct Node *successor = current->Right;
        while (successor->Left != nullptr)
            successor = successor->Left;
        int temp = successor->data;
        Delete(temp);
        current->data = temp;
        return 1;
    }
    return 1;
}

int BST::RecSearch(int val, struct Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        if (root->data == val)
        {
            return 1;
        }
        else
        {
            if (root->data > val)
            {
                if (RecSearch(val, root->Left))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if (RecSearch(val, root->Right))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
}

int BST::Search(int val)
{
    if (RecSearch(val, Root))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    BST b;
    int opt = 1, data;
    while (opt != 0)
    {
        printf("\n1)Insert\n2)Delete\n3)Preorder\n4)Inorder\n5)Postorder\n6)Search\n7)Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter number to insert: ");
            scanf("%d", &data);
            if (b.Insert(data))
            {
                printf("Inserted %d successfully\n", data);
            }
            break;

        case 2:
            printf("Enter number to delete: ");
            scanf("%d", &data);
            if (b.Delete(data))
            {
                printf("Deleted %d successfully\n", data);
            }
            break;

        case 3:
            printf("Preorder Traversal: ");
            b.PreOrder();
            break;

        case 4:
            printf("Inorder Traversal: ");
            b.InOrder();
            break;

        case 5:
            printf("Postorder Traversal: ");
            b.PostOrder();
            break;

        case 6:
            printf("Enter the number to search: ");
            scanf("%d", &data);
            if (b.Search(data) == 1)
            {
                printf("Element Found in the Binary Search Tree");
            }
            else
            {
                printf("Element is not found in the Binary Search Tree");
            }
            break;

        case 7:
            return 0;

        default:
            return 0;
            break;
        }
    }
}