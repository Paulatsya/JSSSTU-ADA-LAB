#include<stdio.h>
#include<stdio.h>
int count;
int a[10]={3,4,1,5,8,8};
int n=6;
int flag=1;
int bubbleSort(int *a,int n){
    count=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            count++;
            if(*(a+j) > *(a+j+1)){
                int temp=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=temp;
                flag=1;

            }
        }
        if(flag==0)
            break;
    }
    return count;
}
int main(){
    count;
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",a[i]);

    }
    printf("\n");
    bubbleSort(a,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",a[i]);

    }
    
}