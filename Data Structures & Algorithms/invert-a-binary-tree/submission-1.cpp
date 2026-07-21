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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root){
        q.push(root);
        }
        while(!q.empty()){
            TreeNode* nd=q.front();
            q.pop();
            swap(nd->left,nd->right);
            if(nd->left){
                q.push(nd->left);
            }
            if(nd->right){
                q.push(nd->right);
            }
        }
        return root;
    }
};
