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

    bool isSameTree(TreeNode* p,TreeNode* a){
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({p,a});
        while(!q.empty()){
            TreeNode* nd1=q.front().first;
            TreeNode* nd2=q.front().second;
            q.pop();
            if(nd1==NULL && nd2==NULL){
                continue;
            }
            if(nd1==NULL || nd2==NULL || nd1->val!=nd2->val){
                return false;
            }
            q.push({nd1->left,nd2->left});
            q.push({nd1->right,nd2->right});
        }
        return true;
    }

    bool dfs(TreeNode* root,TreeNode* subRoot,int val){
        if(root==NULL){
            return false;
        }
        if(val==root->val){
            bool ans= isSameTree(root,subRoot);
            if(ans){
                return ans;
            }
        }
        return dfs(root->left,subRoot,val) || dfs(root->right,subRoot,val);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        int val=subRoot->val;
        return dfs(root,subRoot,val);
    }
};
