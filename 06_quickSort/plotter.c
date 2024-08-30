#include<stdio.h>
#include<stdlib.h>
int count =0;
int partition(int *a,int low,int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;
    do
    {
        while(a[i]<=pivot && i<=high){
            i++;
            count++;
        }
        while(a[j]>pivot && j>=low){
            j--;
            count++;

        }
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    } while (i<j);

    int temp=a[j];
    a[j]=a[low];
    a[low]=temp;
    return j;
    
}
void quickSort(int *a,int low,int high){
    if(low<high){
        int partitionIndex=partition(a,low,high);
        quickSort(a,low,partitionIndex-1);
        quickSort(a,partitionIndex+1,high);
    }
}
void plotter(){
    FILE *f1,*f2,*f3;
    int *a;
    f1=fopen("quickWorst.txt","w");
    f2=fopen("quickBest.txt","w");
    f3=fopen("quickAvg.txt","w");
    for(int i=10; i<=1000 ; i*=2){
        int n=i;
        count=0;
        a=(int *)malloc(n*sizeof(int));
        for (int j = 0; j < n; j++)
        {// worst case--> Sorted array
            a[j]=j+1;
        }
        quickSort(a,0,n-1);
        fprintf(f1,"%d\t%d\n",n,count);
        free(a);
        a=(int *)malloc(n*sizeof(int));
        count=0;
        for (int j = 0; j < n; j++)
        {//Best case
            a[j]=5;
        }
        quickSort(a,0,n-1);
        fprintf(f2,"%d\t%d\n",n,count);
        free(a);
        a=(int *)malloc(n*sizeof(int));
        count=0;
        for (int j = 0; j < n; j++)
        {
            a[j]=rand()%n;
        }
        quickSort(a,0,n-1);
        fprintf(f3,"%d\t%d\n",n,count);
        free(a);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
int main(){

    plotter();
    return 0;
}