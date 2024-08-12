#include<stdio.h>
#include<stdlib.h>
int count;
int a[10]={3,4,1,5,8,8};
int arr[10]={3,4,1,5,8,8};
int n=6;
void insertionSort(int *a,int n){
    int i,j,cur;
    
    for(i=1;i<n;i++){
        cur=a[i];
        j=i-1;
        while(a[j]>a[i] && j>=0){
            
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=cur;

    }
    return NULL;
}

int main(){
    
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",a[i]);

    }
    printf("\n");
    insertionSort(a,n);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",a[i]);

    }
    printf("\n");
    
    
}