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
    unordered_map<TreeNode*,int> mpp;
    int solve(TreeNode* root){
        if(mpp.find(root)!=mpp.end()){
            return mpp[root];
        }
        if(root==NULL){
            return 0;
        }
        int steal=root->val;
        if(root->left){
            steal+=solve(root->left->left)+solve(root->left->right);
        }
        if(root->right){
            steal+=solve(root->right->left)+solve(root->right->right);
        }
        int notsteal=solve(root->left)+solve(root->right);
        return mpp[root]=max(steal,notsteal);
    }

    int rob(TreeNode* root) { 
        return solve(root);
    }
};