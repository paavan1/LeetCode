#include<string>

using namespace std;

bool isAN(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {

        int i = 0, j = s.size() - 1;

        while(i <= j)
        {
            if(! isAN(s[i]) ) {i++; continue;}

            if( !isAN(s[j]) ) {j--; continue;}

            if(tolower(s[i]) != tolower(s[j])) return false;

            i++;

            j--;
        }

        return true;
    }
