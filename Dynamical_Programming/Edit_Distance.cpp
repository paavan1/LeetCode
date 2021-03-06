#include<string>
#include<vector>

using namespace std;
    //using DP

    int minDistance(string word1, string word2) {

        if(word2.size() == 0) return word1.size();

        vector<int> DP(word2.size() + 1, 0);

        for(int i = 0; i <= word2.size(); i++) DP[i] = i;

        int temp1 = 0, temp2 = 0;

        for(int i = 0; i < word1.size(); i++)
        {
            temp1 = DP[0]; DP[0] = i + 1;

            for(int j = 1; j <= word2.size(); j++)
            {
                temp2 = temp1;

                temp1 = DP[j];

                //replace
                DP[j] = word1[i] == word2[j-1] ? temp2 : temp2 + 1;

                //delete
                DP[j] = DP[j] < DP[j-1] + 1 ? DP[j] : DP[j-1] + 1;

                //insert
                DP[j] = DP[j] < temp1 + 1 ? DP[j] : temp1 + 1;

            }
        }

        return DP[word2.size()];
    }
