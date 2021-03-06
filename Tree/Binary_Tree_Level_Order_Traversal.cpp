#include<vector>
#include<stdlib.h>
#include<queue>

using namespace std;

struct TreeNode {
	 int val;
     TreeNode *left;
 	 TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    //using bfs
    vector<vector<int> > levelOrder(TreeNode *root) {

        vector<vector<int>> ret;

        vector<int> temp;

        if(root == NULL) return ret;

        queue<TreeNode*> Q;

        Q.push(root);

        temp.push_back(root->val); ret.push_back(temp); temp.clear();

        TreeNode* cur = NULL;

        int cnt1 = 1, cnt2 = 0;


        while(Q.empty() == false)
        {
            cur = Q.front();

            Q.pop();

            cnt1--;

            if( cur->left )
            {
                cnt2++; Q.push(cur->left); temp.push_back(cur->left->val);
            }

            if(cur->right)
            {
                cnt2++; Q.push(cur->right); temp.push_back(cur->right->val);
            }

            if(cnt1 == 0)
            {
                if(cnt2) ret.push_back(temp); temp.clear();
                cnt1 = cnt2; cnt2 = 0;
            }
        }

        return ret;
    }
