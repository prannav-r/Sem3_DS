//C++ program to search for the presence of a number in an array using linear search.

#include <stdio.h>

int i,x,n;
int ls(int arr[],int n,int x){
    for (int i = 0; i < n; i++) {
        if (arr[i]==x){
            return 1;
        }
}
return 0;
}

int main(){
printf("Enter the Number of elements in the array: ");
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++){
    printf("Enter element %d : ",i+1);
    scanf("%d",&arr[i]);
 }
printf("Enter the element to search:");
scanf("%d",&x);
int res=ls(arr,n,x);
if (res == 1){
    printf("Element found in the array.\n");
 }
else{
    printf("Element not found in the array.\n");
 }
}