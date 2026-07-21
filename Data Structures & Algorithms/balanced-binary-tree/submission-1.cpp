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

    bool isBalanced(TreeNode* root) {
       stack<TreeNode*> st;
       unordered_map<TreeNode*,int> mpp;
       TreeNode* cur=root;
       TreeNode* last=NULL;
       while(cur || !st.empty()){
        if(cur){
            st.push(cur);
            cur=cur->left;
        }
        else{
            cur=st.top();
            if(cur->right==NULL || last==cur->right ){
                st.pop();
                int l=mpp[cur->left];
                int r=mpp[cur->right];
                if(abs(l-r)>1){
                    return false;
                }
                mpp[cur]=1+max(l,r);
                last=cur;
                cur=NULL;
            }
            else{
                cur=cur->right;
            }
        }
       }
       return true;
    }
};
