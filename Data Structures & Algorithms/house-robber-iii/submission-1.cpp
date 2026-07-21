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
    // int solve(TreeNode* root){
    //     if(mpp.find(root)!=mpp.end()){
    //         return mpp[root];
    //     }
    //     if(root==NULL){
    //         return mpp[root]=0;
    //     }
    //     int steal=root->val;
    //     if(root->left){
    //         steal+=solve(root->left->left)+solve(root->left->right);
    //     }
    //     if(root->right){
    //         steal+=solve(root->right->left)+solve(root->right->right);
    //     }
    //     int notsteal=solve(root->left)+solve(root->right);
    //     return mpp[root]=max(steal,notsteal);
    // }

    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        auto left=solve(root->left);
        auto right=solve(root->right);
        int withroot=root->val+left.second+right.second;
        int withoutroot=max(left.first,left.second)+max(right.first,right.second);
        return {withroot,withoutroot};
    }

    int rob(TreeNode* root) { 
        auto res=solve(root);
        return max(res.first,res.second);
    }
};