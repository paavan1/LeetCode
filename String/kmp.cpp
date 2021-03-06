#include<stdlib.h>


//pre-compute the overlap function
    void preCompute(char* needle, int T[], int n)
    {
        int i = 0, j = 0;
        T[0] = -1;
        for(i = 1 ; i < n; i++)
        {
            j = T[i-1];
            while( j>=0 && needle[j + 1] != needle[i])
            {
                j = T[j];
            }

            T[i] = needle[j + 1] == needle[i] ? j + 1 : -1;
        }
    }

    char *strStr(char *haystack, char *needle) {

        if(haystack == NULL || needle == NULL) return NULL;
        if(*haystack == '\0') return *needle == '\0' ? haystack : NULL;
        if(*needle == '\0') return haystack;

        int len = 0;
        while(*(needle + len) != '\0') len++;
        int* T = new int[len];
        preCompute(needle, T, len);

        int h = 0, n = 0;
        while(*(haystack + h) != '\0')
        {
            if(*(haystack + h) == *(needle + n))
            {
                h++;n++;
            }else{
                if(n == 0){
                    h++;
                }else{
                    n = T[n-1] + 1;
                }
            }

            if(n == len) return haystack + h - len;
        }

        return NULL;
    }



