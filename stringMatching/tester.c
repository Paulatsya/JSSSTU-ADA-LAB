#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count;
int stringMatch(char *text,char *pattern,int strlen,int patlen){
    count=0;
    for(int i=0;i<strlen-patlen;i++){
        int j=0;
        while(j<patlen && pattern[j] == text[j+i]){
            count++;
            j++;
        }
        if(j==patlen){
            printf("Pattern found!!");
            return count;
        }
    
    }
    printf("Pattern not found\n");
       
    
    return count;
}
int main(){
    int m,n;
    char text[20],pattern[20];
    printf("Enter pattern len\n");
    scanf("%d", &m); 
    printf("ENTER THE PATTERN\n");
    getchar();
    fgets(pattern,sizeof(pattern),stdin);
    printf("ENTER THE TEXT LENGTH\n"); 
    scanf("%d", &n); 
    printf("ENTER THE TEXT\n");
    getchar();
    fgets(text,sizeof(text),stdin);
    text[strcspn(text, "\n")] = '\0';
    stringMatch(text,pattern,n,m);
}