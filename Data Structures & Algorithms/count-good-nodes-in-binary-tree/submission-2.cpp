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

    int goodNodes(TreeNode* root) {
       int cnt=0;
       queue<pair<TreeNode*,int>> q;
       if(root!=NULL){
        q.push({root,INT_MIN});
       }
       while(!q.empty()){
        auto pr=q.front();
        q.pop();
        TreeNode* node=pr.first;
        int cap=pr.second;
        if(node->val>=cap){
            cnt++;
        }
        cap=max(cap,node->val);
        if(node->left){
            q.push({node->left,cap});
        }
        if(node->right){
            q.push({node->right,cap});
        }
       }
       return cnt;
    }

};
