//C++ menu-driven program to sort an array of numbers in ascending or descending order.

#include <stdio.h>

int i,n,type;

void sort(int arr[],int n,int type){
    int j,k,r;
    for (j=0;j<n-1;j++){
        for(k=j+1;k<n;k++){
           if (type==1?arr[j]>arr[k]:arr[j]<arr[k]){
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
    while (true)
    {
       printf("\nSelect the type of sort :\n1.Ascending Order\n2.Descending Order\n3.Exit\n");
       scanf("%d",&type);
       if (type==1){
        sort(arr,n,type);
        printf("Sorted Array : ");
        for (i=0;i<n-1;i++){
           printf("%d,",arr[i]);
           }
            printf("%d",arr[n-1]);
       }
       else if(type==2){
        sort(arr,n,type);
        printf("Sorted Array : ");
        for (i=0;i<n-1;i++){
            printf("%d,",arr[i]);
           }
        printf("%d",arr[n-1]);
       }
       else
        break;
    }
}