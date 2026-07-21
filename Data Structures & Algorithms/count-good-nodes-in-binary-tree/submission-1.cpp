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

    void dfs(TreeNode* root,int& ans,int cap){
        if(root==NULL){
            return;
        }
        if(root->val>=cap){
            ans++;
        }
        cap=max(cap,root->val);
        dfs(root->left,ans,cap);
        dfs(root->right,ans,cap);
    }

    int goodNodes(TreeNode* root) {
        int ans=0;
        int cap=INT_MIN;
        dfs(root,ans,cap);
        return ans;
    }
};
