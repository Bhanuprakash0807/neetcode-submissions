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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
       TreeNode* cur=root;
       while(cur!=NULL){
        if(cur->left==NULL){
            res.push_back(cur->val);
            cur=cur->right;
        }
        else{
            TreeNode* prev=cur;
            cur=prev->left;
            while(cur->right!=NULL && cur->right!=prev){
                cur=cur->right;
            }
            if(cur->right==NULL){
                cur->right=prev;
                cur=prev->left;
            }
            else{
                res.push_back(prev->val);
                cur->right=NULL;
                cur=prev->right;   
            }
        }
       }
        return res;
    }
};