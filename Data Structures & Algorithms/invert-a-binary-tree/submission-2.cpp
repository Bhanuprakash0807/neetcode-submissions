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
        stack<TreeNode*> st;
        if(root){
        st.push(root);
        }
        while(!st.empty()){
            TreeNode* nd=st.top();
            st.pop();
            swap(nd->left,nd->right);
            if(nd->left){
                st.push(nd->left);
            }
            if(nd->right){
                st.push(nd->right);
            }
        }
        return root;
    }
};
