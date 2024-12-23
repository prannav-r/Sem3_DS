#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exp_Tree.h"

int main()
{

    int choice;
    char expression[100];
    BT tree;
    while (1)
    {
        printf("\n1.Postfix Expression \n2.Construct Expression Tree \n3.Pre Order \n4.Post Order \n5.In Order \n6.Exit");
        printf("\nEnter the choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the postfix expression: ");
            scanf(" %s", &expression);
            break;
        case 2:
            if (strlen(expression) == 0)
            {
                printf("Enter the postfix expression first\n");
                break;
            }
            else
            {
                tree.constructExpressionTree(expression);
                printf("Expression Tree Constructed\n");
                break;
            }
        case 3:
            if (tree.constructedTree == 0)
            {
                printf("Construct the expression tree first\n");
                break;
            }
            else
            {
                printf("Pre Order: ");
                tree.preorder(tree.getRoot());
                break;
            }
        case 4:
            if (tree.constructedTree == 0)
            {
                printf("Please construct the expression tree first\n");
                break;
            }
            else
            {
                printf("Post Order: ");
                tree.postorder(tree.getRoot());
                break;
            }
        case 5:
            if (tree.constructedTree == 0)
            {
                printf("Please construct the expression tree first\n");
                break;
            }
            else
            {
                printf("In Order: ");
                tree.inorder(tree.getRoot());
                break;
            }
        case 6:
            printf("PROGRAM ENDED\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}