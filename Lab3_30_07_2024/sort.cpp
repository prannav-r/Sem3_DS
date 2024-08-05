//C++ menu-driven program to sort a given array in ascending order.

#include <stdio.h>

void print_arr(int arr[], int n){
    printf("Sorted Array = ");
    for (int i = 0; i<n-1;i++){
        printf("%d,",arr[i]);
    }
    printf("%d\n",arr[n-1]);
}


void bubble_sort(int arr[],int n){
    int temp,swap;
    for (int i = 0;i<n-1;i++){
        swap=0;
        for (int j = 0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap = 1;
            }
        }
        if (swap==0)
            break;
    }
}

void sel_sort(int arr[],int n){
    int min_ind,temp;
    for (int i=0;i<n-1;i++){
        min_ind=i;
        for (int j=i+1 ; j<n ; j++){
            if (arr[j]<arr[min_ind]){
                min_ind=j;
            }
        }
        if (min_ind!=i){
            temp=arr[min_ind];
            arr[min_ind]=arr[i];
            arr[i]=temp;
        }
    }
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int arr[], int n) {
    int max = findMax(arr, n);
    int count[100] = {0};
    int output[100];
    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


int main(){
    int ch,n;

        printf("Enter the size of the array : ");
        scanf("%d",&n);
        int arr[n];
        for (int i=0;i<n;i++){
            printf("Enter element %d :",i+1);
            scanf("%d",&arr[i]);
        }
        printf("1.Bubble Sort\n2.Selection Sort\n3.Counting Sort\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                bubble_sort(arr, n);
                print_arr(arr, n);
                break;
            case 2:
                sel_sort(arr, n);
                print_arr(arr, n);
                break;
            case 3:
                count_sort(arr, n);
                print_arr(arr, n);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
}