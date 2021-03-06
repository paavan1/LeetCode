#include<string>
#include<stack>

using namespace std;

 //using stack
    int longestValidParentheses(string s) {

        stack<int> workingS;

        int max = 0, len = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                workingS.push(i);
            }else{
                if(workingS.empty() || s[workingS.top()] == ')')
                {
                    workingS.push(i);
                }else{
                    workingS.pop();
                    len = workingS.empty() ? i + 1 : i - workingS.top();
                    max = max > len ? max : len;
                }
            }
        }

        return max;
    }




