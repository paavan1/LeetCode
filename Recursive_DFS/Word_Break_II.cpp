#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

//using DP to precompute the knowledge which is used in pruning during dfs
    void preCompute(string s, vector<bool> &DP, unordered_set<string> &dict)
    {
        DP[s.size()-1] = true;

        string cur;

        for(int i = s.size() - 2; i >= 0; i--)
        {
            DP[i] = false;

            for(int j = i + 1; j < s.size();j++)
            {
                cur = s.substr(i+1,j-i);

                if(dict.find(cur) == dict.end()) continue;

                if(DP[j] == true)
                {
                    DP[i] = true; break;
                }
            }
        }
    }

    void dfs(string s, int total, vector<string> &prefix, vector<string> &ret, unordered_set<string> &dict, vector<bool> &DP)
    {
        if(total == s.size())
        {
            string temp(prefix[0]);

            for(int i = 1; i < prefix.size(); i++){ temp.append(" "); temp.append(prefix[i]);}

            ret.push_back(temp); return;
        }

        //dfs
        string cur;
        for(int i = total; i < s.size(); i++)
        {
            cur = s.substr(total, i - total + 1);

            if(dict.find(cur) == dict.end() || DP[i] == false) continue;

            prefix.push_back(cur);

            dfs(s,i+1, prefix, ret, dict, DP);

            prefix.pop_back();
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {

        vector<string> ret;

        if(s.size() == 0) return ret;

        vector<bool> DP(s.size(),false);

        preCompute(s,DP,dict);

        vector<string> prefix;

        dfs(s, 0, prefix, ret, dict, DP);

        return ret;
    }

