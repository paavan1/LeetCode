#include<string>

using namespace std;

int numDecodings(string s) {

        if(s.size() == 0 || s[0] == '0') return 0;

        int* DP = new int[s.size()];
        DP[0] = 1;
        int num = 0;

        for(int i = 1; i < s.size(); i++)
        {
            DP[i] = s[i] == '0' ? 0 : DP[i-1];
            num = (s[i-1] - '0')*10 + s[i] - '0';
            if(num >= 10 && num <= 26) DP[i] += i >= 2 ? DP[i-2] : 1;
        }

        return DP[s.size()-1];
    }
