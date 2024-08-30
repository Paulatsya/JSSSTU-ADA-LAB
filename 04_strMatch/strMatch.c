    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void strMatch(char *text, char *pattern, int tlen, int plen) 
    {
        for (int i = 0; i <= (tlen - plen); i++)
        {
            int j = 0;
            while (j < plen && pattern[j] == text[j + i])
            {
                j++;
            }
            if (j == plen)
            {
                printf("Pattern found at starting index>> %d\n", i);
                return;
            }
        }
        printf("Pattern not found\n");
        return;
    }
    int main(int argc, char const *argv[])
    {
        int tlen, plen; //tlen: length of text : plen:- pattern length 
        char text[20], pattern[20];
        // text input
        printf("Enter the text\n");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';

        tlen = strlen(text);
        // pattern input
        printf("Enter the pattern\n");
        fgets(pattern, sizeof(pattern), stdin);
        pattern[strcspn(pattern, "\n")] = '\0';
        plen = strlen(pattern);
        strMatch(text, pattern, tlen, plen);

        return 0;
    }
