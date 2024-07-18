#include <stdio.h>

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