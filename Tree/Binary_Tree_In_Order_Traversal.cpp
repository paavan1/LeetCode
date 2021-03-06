#include<vector>
#include<stdlib.h>
#include<stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    //iterative method
    vector<int> inorderTraversal(TreeNode *root) {

        stack<TreeNode*> s;

        TreeNode* current = root;

        vector<int> ret;

        while(!s.empty() || current)
        {
            if(current)
            {
                s.push(current);
                current = current->left;
            }
            else
            {
                ret.push_back(s.top()->val);
                current = s.top()->right;
                s.pop();
            }
        }

        return ret;
    }

