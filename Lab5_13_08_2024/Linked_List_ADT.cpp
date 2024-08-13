//






































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
            if(!(l1.ins_beg(num)))
                printf("Can't insert %d. The list is full.",num);
            else
                printf("Succesfully inserted %d",num);
            break;

        case 3:
            printf("Enter the number to insert: ");
            scanf("%d",&num);
            if(!(l1.ins_end(num)))
                printf("Can't insert %d. The list is full.",num);
            else
                printf("Succesfully inserted %d",num);
            break;
        
        case 4:
            printf("Enter the number to insert: ");
            scanf("%d",&num);
            printf("Enter the position(index) to insert: ");
            scanf("%d",&pos);
            if(!(l1.ins_pos(num,pos)))
                printf("Can't insert %d. The list is full.",num);
            else
                printf("Succesfully inserted %d",num);
            break;

        case 5:
            dn=l1.del_beg();
            if(dn==np)
                printf("Can't delete. The list is empty.");
            else
                printf("Succesfully deleted %d",dn);
            break;

        case 6:
            dn=l1.del_end();
            if(dn==np)
                printf("Can't delete. The list is empty.");
            else
                printf("Succesfully deleted %d",dn);
            break;

        case 7:
            printf("Enter the position to delete: ");
            scanf("%d",&pos);
            dn=l1.del_pos(pos);
            if(dn==np)
                printf("Can't delete. The list is empty.");
            else
                printf("Succesfully inserted %d",dn);
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Please Enter a Valid Choice!");
            break;
        }
    }
}