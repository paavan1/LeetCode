#include<string>
#include<vector>

using namespace std;

void combination(int len, string &prefix,  string digits, vector<string> &ret,  vector<string> &mapping)
    {
        if(len == digits.size())
        {
            ret.push_back(prefix); return;
        }

        string temp = mapping[digits[len] - '0' - 2];

        for(int i = 0; i < temp.size(); i++)
        {
            prefix[len] = temp[i];
            combination(len + 1, prefix,  digits, ret,  mapping);
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> mapping(8,"");
        mapping[0] = "abc";
        mapping[1] = "def";
        mapping[2] = "ghi";
        mapping[3] = "jkl";
        mapping[4] = "mno";
        mapping[5] = "pqrs";
        mapping[6] = "tuv";
        mapping[7] = "wxyz";

        vector<string> ret;

        if(digits.size() == 0)
        {
            ret.push_back(""); return ret;
        }

        string prefix(digits.size(), '0');

        combination(0, prefix,  digits, ret, mapping);

        return ret;
    }
