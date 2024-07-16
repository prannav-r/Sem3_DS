//C++ menu-driven program to sort an array of numbers in ascending or descending order.

#include <stdio.h>

int i,n;
void ascsort(int arr[],int n){
    int j,k,r;
    for (j=0;j<n;j++){
        for(k=j+1;k<n;k++){
            if (arr[j]>arr[k]){
                r=arr[j];
                arr[j]=arr[k];
                arr[k]=r;
            }
        }
    }
}

int main(){
    printf("Enter the Number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    printf("Sorted Array : ");
    for (i=0;i<n-1;i++){
        printf("%d,",arr[i]);
    }
    printf("%d",arr[n-1]);
}