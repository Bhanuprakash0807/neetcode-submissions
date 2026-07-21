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

    int diameterOfBinaryTree(TreeNode* root) {
       unordered_map<TreeNode*,pair<int,int>> mpp;
       mpp[NULL]={0,0};
       stack<TreeNode*> st;
       st.push(root);
       while(!st.empty()){
        TreeNode* node=st.top();
        if(node->left && mpp.find(node->left)==mpp.end()){
            st.push(node->left);
        }
        else if(node->right && mpp.find(node->right)==mpp.end()){
            st.push(node->right);
        }
        else{
            node=st.top();
            st.pop();
            int lh=mpp[node->left].first;
            int rh=mpp[node->right].first;
            int ld=mpp[node->left].second;
            int rd=mpp[node->right].second;
            int h=1+max(lh,rh);
            int d=max(lh+rh,max(ld,rd));
            mpp[node]={h,d};
        }
       }
       return mpp[root].second;
    }
};
