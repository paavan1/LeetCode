#include<string>

using namespace std;

string longestPalindrome(string s) {
        if(s.size() == 0) return s;

        int start = 0, max = 1;

        int i = 0, j = 0;

        //odd length
        for(i = 0; i < s.size(); i++)
        {
            j = 0;
            while(i - j - 1 >= 0 && i + j + 1 < s.size())
            {
                if(s[i-j-1] != s[i+j+1]) break;
                j++;
            }

            if(max < 2*j + 1)
            {
                max = 2*j + 1; start = i - j;
            }
        }

        //even length
        for(i = 0; i < s.size() - 1; i++)
        {
            j = 0;
            while(i - j >= 0 && i + j + 1 < s.size())
            {
                if(s[i-j] != s[i+j+1]) break;
                j++;
            }

            if(max < 2*j)
            {
                max = 2*j; start = i - j + 1;
            }
        }

        return s.substr(start,max);
    }
