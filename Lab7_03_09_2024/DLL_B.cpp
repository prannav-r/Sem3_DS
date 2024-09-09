#include <stdio.h>
#include <stdlib.h>
#include "DLL_B.h"


int main() 
{
    Dlist list;
    int val,ch;
    while (1) 
    {     
        printf("\n 1.New Webpage \n 2.Go Front\n 3.Go Back\n 4.Exit\n");
        printf("Enter the option: ");
        scanf("%d", &ch);

        switch (ch) 
        {
        case 1:
            printf("Inserted new page.");
            printf("%d", list.newpage());
            printf("\n(Press any key to continue)");
            break;

        case 2:
            val = list.front();
            if (val != -1) {
                printf("Moved front. \nCurrent page: %d", val);
            } 
            else {
                printf("Cannot go front.");
            }
            printf("\n(Press any key to continue)");
            break;

        case 3:
            val = list.back();
            if (val != -1) {
                printf("Moved back. \nCurrent page: %d", val);
            } 
            else {
                printf("Cannot go back.");
            }
            printf("\n(Press any key to continue)");
            break;

        case 4:
            printf("PROGRAM ENDED\n");
            return 0;

        default:
            printf("Incorrect input.\n");
            return 0;
        }
    }
    return 0;
}