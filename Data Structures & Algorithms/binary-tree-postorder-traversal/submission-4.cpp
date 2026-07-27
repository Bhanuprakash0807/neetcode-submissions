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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur=root;
        stack<TreeNode*> st;
        while(cur || !st.empty()){
            while(cur!=NULL){
                st.push(cur);
                res.push_back(cur->val);
                cur=cur->right;
            }
            cur=st.top()->left;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};