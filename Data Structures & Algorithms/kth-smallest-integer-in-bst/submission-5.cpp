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

    int kthSmallest(TreeNode* root, int k) {
        int cnt=k;
        TreeNode* cur=root;
        stack<TreeNode*> st;
        while(cur || !st.empty()){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            cnt--;
            if(cnt==0){
                return cur->val;
            }
            cur=cur->right;
        }
        return -1;
    }
};
