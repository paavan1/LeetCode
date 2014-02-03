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
            *start = NULL; *end = NULL; return;
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

        if(rEnd != NULL) *end = rEnd;
        else if(lEnd != NULL) *end = lEnd;
        else *end = root;
    }

    void flatten(TreeNode *root) {

        TreeNode* start = NULL, *end = NULL;

        flatten(root, &start, &end);

    }
