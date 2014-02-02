#include<vector>
#include<stdlib.h>
#include<queue>
#include<algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    //using bfs
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

        vector<vector<int>> ret;

        if(root == NULL) return ret;

        vector<int> temp;

        queue<TreeNode*> Q;

        Q.push(root);

        temp.push_back(root->val); ret.push_back(temp); temp.clear();

        int cnt1 = 1, cnt2 = 0;

        TreeNode* cur = NULL;

        bool even = true;

        while(Q.empty() == false)
        {
            cur = Q.front();

            Q.pop();

            cnt1--;

            if(cur->left)
            {
                cnt2++; Q.push(cur->left); temp.push_back(cur->left->val);
            }

            if(cur->right)
            {
                cnt2++; Q.push(cur->right); temp.push_back(cur->right->val);
            }

            if(cnt1 == 0)
            {
                if(even && cnt2) reverse(temp.begin(), temp.end());

                if(cnt2) ret.push_back(temp);

                cnt1 = cnt2; cnt2 = 0; temp.clear(); even = 1^even;
            }
        }

        return ret;
    }
