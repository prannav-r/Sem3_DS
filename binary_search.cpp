#include <stdio.h>
#include "sort.h"

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, i, ch, type,req;
    printf("Enter the Number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    while (true)
    {
        printf("1.Sort Array\n2.Binary Search\nEnter your choice :");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("\nSelect the type of sort :\n1.Ascending Order\n2.Descending Order\n3.Exit\n");
            scanf("%d", &type);
            sort(arr, n, type);
            printf("Sorted Array : ");
            for (i = 0; i < n - 1; i++)
            {
                printf("%d,", arr[i]);
            }
            printf("%d\n", arr[n - 1]);
        }
        else if (ch==2){
            sort(arr,n,1);
            printf("Enter the element to search for :\n");
            scanf("%d",&req);
            int res=binarySearch(arr,0,n-1,req);
            (res==-1)?printf("Element not found in the list.\n"):printf("Element found at index %d\n",res);
        }
        else
           break;
    }
}