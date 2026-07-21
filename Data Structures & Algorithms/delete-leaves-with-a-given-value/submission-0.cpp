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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<TreeNode*> st;
        TreeNode* cur=root;
        TreeNode* last=NULL;
        while(cur || !st.empty()){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            if(cur->right && last!=cur->right){
                st.push(cur->right);
                cur=cur->right;
            }
            else{
                st.pop();
                if(cur->right==NULL && cur->left==NULL && cur->val==target){
                if(st.empty()){
                    return NULL;
                }
                TreeNode* par=st.top();
                    if(par->left==cur){
                        par->left=NULL;
                    }
                    else{
                        par->right=NULL;
                    }
                }
                last=cur;
                cur=NULL;
            }
        }
        return root;
    }
};