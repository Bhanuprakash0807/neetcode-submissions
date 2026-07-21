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

    bool dfs(TreeNode* root,int maxi,int mini){
        if(root==NULL){
            return true;
        }
        if(root->val>=maxi || root->val<=mini){
            return false;
        }
        return dfs(root->left,root->val,mini) && dfs(root->right,maxi,root->val);
    }

    bool isValidBST(TreeNode* root) {
        int maxi=INT_MAX;
        int mini=INT_MIN;
        return dfs(root,maxi,mini);
    }
};
