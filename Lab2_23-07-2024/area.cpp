//C++ program menu-driven program 
//Calculates and displays the area of a circle, square, and rectangle using only pointers.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int *ch = (int *)malloc(sizeof(int));
    int *res = (int *)malloc(sizeof(int));
    while (1)
    {
        printf("\nMain Menu\n1.Circle\n2.Square\n3.Rectangle\n4.Exit\nEnter your choice: ");
        scanf("%d", ch);
        if (*ch == 1)
        {
            int *r = (int *)malloc(sizeof(int));
            printf("Enter the radius of the circle: ");
            scanf("%d", r);
            *res = M_PI * ((*r) * (*r));
            printf("The area of circle is: %d", *res);
        }
        else if (*ch == 2)
        {
            int *s = (int *)malloc(sizeof(int));
            printf("Enter the side of the square: ");
            scanf("%d", s);
            *res = (*s) * (*s);
            printf("The area of square is: %d", *res);
        }
        else if (*ch == 3)
        {
            int *l = (int *)malloc(sizeof(int));
            int *b = (int *)malloc(sizeof(int));
            printf("Enter the length of the square: ");
            scanf("%d", l);
            printf("Enter the breadth of the square: ");
            scanf("%d", b);
            *res = (*l) * (*b);
            printf("The area of rectangle is: %d", *res);
        }
        else if (*ch == 4)
        {
            break;
        }
    }
}