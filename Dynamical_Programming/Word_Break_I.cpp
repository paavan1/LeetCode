#include<string>
#include<unordered_set>

using namespace std;

//using DP
    bool wordBreak(string s, unordered_set<string> &dict) {

        if(s.size() == 0) return dict.find("") != dict.end();

        int* DP = new int[s.size() + 1];

        DP[0] = true;

        string word;

        for(int i = 0; i < s.size(); i++)
        {
            DP[i+1] = false;

            for(int j = 0; j <= i; j++)
            {
                word = s.substr(j,i-j+1);

                if(dict.find(word) == dict.end()) continue;

                if(DP[j] == true)
                {
                    DP[i+1] = true; break;
                }
            }
        }

        return DP[s.size()];

    }
