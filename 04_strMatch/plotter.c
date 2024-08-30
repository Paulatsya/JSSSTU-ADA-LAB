#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
void strMatch(char *text, char *pattern, int tlen, int plen)
{
    count=0;
    for (int i = 0; i <= tlen - plen; i++)
    {
        int j = 0;
        
        while(j<plen){
            count++;
            if(pattern[j]!=text[i+j]){
                break;
            }
            j++;
        }
        if(j==plen){
            return;
        }
    }
}
void plotter()
{
    FILE *f1, *f2, *f3;
    f1 = fopen("strMatchBest.txt", "w");
    f2 = fopen("strMatchAvg.txt", "w");
    f3 = fopen("strMatchWorst.txt", "w");
    int plen, tlen = 100;
    char *pattern;
    char *text = (char *)malloc(tlen * sizeof(char));
    for (int i = 0; i < tlen; i++)
    { // intialising text to be all "a"
        text[i] = 'a';
    }

    for (int i = 10; i <= 100; i += 10)
    { // i is length of the patter we want
        plen = i;
        count=0;    
        pattern = (char *)malloc(plen * sizeof(char));
        for (int j = 0; j < plen; j++)
        { // best case--> pattern is same as text
            pattern[j] ='a';
        }
        strMatch(text, pattern, tlen, plen);
        fprintf(f1, "%d\t%d\n", plen, count);

        count = 0; // reseting count
        // worst case-->last character wrong
        pattern[plen - 1] = 'b';
        strMatch(text, pattern, tlen, plen);
        fprintf(f2, "%d\t%d\n", plen, count);

        count = 0; // reset
        for (int j = 0; j < plen; j++)
        {                                 // Avg case--> randomised
            pattern[j] = 97 + rand() % 3; // ascii(97)="a" & rand()%3-->0/1/2
        }
        strMatch(text, pattern, tlen, plen);
        fprintf(f3, "%d\t%d\n", plen, count);
        free(pattern);
    }
    free(text);
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
int main(int argc, char const *argv[])
{
    plotter();
    return 0;
}
