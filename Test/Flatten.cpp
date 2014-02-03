#include<stdlib.h>
#include<iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    void flatten(TreeNode* root, TreeNode** start, TreeNode** end)
    {
        if(root == NULL) {
            start = NULL; end = NULL; return;
        }

        TreeNode* lStart = NULL, *lEnd = NULL;
        flatten(root->left, &lStart, &lEnd);


        TreeNode* rStart = NULL, *rEnd = NULL;
        flatten(root->right, &rStart, &rEnd);

        root->left = NULL;
        root->right = lStart == NULL ? rStart : lStart;

        if(lEnd) lEnd->right = rStart;

        if(rEnd) rEnd->right = NULL;

        *start = root;
        *end = rEnd == NULL ? lEnd : rEnd;
    }

    void flatten(TreeNode *root) {

        TreeNode* start = NULL, *end = NULL;

        flatten(root, &start, &end);

    }

    void test()
    {
    	TreeNode *root = new TreeNode(1);
    	root->left = new TreeNode(2);
    	root->right = new TreeNode(3);
    	flatten(root);

    	while(root)
    	{
    		cout<<root->val<<" ";
    		root = root->right;
    	}
    	cout<<endl;
    }

    int main()
    {
    	test();
    }
