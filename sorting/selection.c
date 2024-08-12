#include<stdio.h>
#include<stdlib.h>
int count;
int a[10]={3,4,1,5,8,8};
int arr[10]={3,4,1,5,8,8};
int n=6;
int selectionSort(int *a,int n){
    count =0;
    int small;
    for(int i=0;i<n-1;i++){
        small=i;
        for(int j=i+1;j<n;j++){
            count++;
            if(a[j]<a[small]){
                small=j;
            }
        }
        if(small!=i){
            int temp=a[small];
            a[small]=a[i];
            a[i]=temp;
        }
    }
    return count;   
    
}
int main(){
    
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",a[i]);

    }
    printf("\n");
    selectionSort(a,n);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",a[i]);

    }
    printf("\n");
    return 0;
    
    
}