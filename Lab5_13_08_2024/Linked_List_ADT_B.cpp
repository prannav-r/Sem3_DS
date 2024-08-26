#include "LL_fns.h"

int main() {
    List l1, l2, l3;
    int choice, num, pos;

    while (true) {
        printf("\n\n1. Insert into List1\n2. Insert into List2\n3. Merge into List3\n4. Display \n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter a number to insert into List1: ");
                scanf("%d", &num);
                l1.insert_asc(num);
                break;

            case 2:
                printf("Enter a number to insert into List2: ");
                scanf("%d", &num);
                l2.insert_asc(num);
                break;

            case 3:
                l3 = List();
                l3.merge(l1, l2);
                printf("Lists 1 and 2 merged into List 3\n");
                break;

            case 4:
                printf("List1-");
                l1.display();
                printf("\nList2-");
                l2.display();
                printf("\nList3-");
                l3.display();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Choose a number between 1 and 5\n");
                break;
        }
    }

    return 0;
}