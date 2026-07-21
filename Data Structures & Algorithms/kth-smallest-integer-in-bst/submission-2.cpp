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

    void dfs(TreeNode* root,int& cnt,int& val){
        if(root==NULL){
            return ;
        }
        dfs(root->left,cnt,val);
        if(cnt==0){
            return;
        }
        cnt--;
        if(cnt==0){
            val=root->val;
            return;
        }
        dfs(root->right,cnt,val);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt=k;
        int val;
        dfs(root,cnt,val);
        return val;
    }
};
