/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int fun(TreeNode* root,int& ans){
        if(root==NULL){
            return -1;
        }
        int l=1+fun(root->left,ans);
        int r=1+fun(root->right,ans);
        ans=max(ans,l+r);
        return max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        fun(root,ans);
        return ans;
    }
};
