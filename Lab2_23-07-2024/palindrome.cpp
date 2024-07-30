//C++ program to find whether a given string is a palindrome or not using only pointers.
#include <stdio.h>
#include <stdlib.h>

int palindrome(char *str,int *len){
    int *i = (int *)malloc(sizeof(int));
    for (*i = 0; *i < (*len / 2); *i++)
    {
        if (str[*i] != str[(*len) - *i - 1])
        {
           printf("It is not a palindrome.");
           return 0;
        }
    }
    printf("It is a Palindrome.");
}

int main(){
    int *len=(int*)malloc(sizeof(int));
    printf("Enter the size of the string: ");
    scanf("%d",len);
    char *str=(char*)malloc((*len)*sizeof(int));
    printf("Enter the string: ");
    scanf("%s",str);
    palindrome(str,len);
    free(str);
}