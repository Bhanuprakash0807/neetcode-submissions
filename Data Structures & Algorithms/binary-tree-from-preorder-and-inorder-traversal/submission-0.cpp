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
    unordered_map<int,int> mpp;
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int& ind,int l,int r){
        if(l>r){
            return NULL;
        }
        int val=preorder[ind];
        ind++;
        TreeNode* root=new TreeNode(val);
        root->left=build(preorder,inorder,ind,l,mpp[val]-1);
        root->right=build(preorder,inorder,ind,mpp[val]+1,r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind=0;
        int l=0;
        int r=inorder.size()-1;
        for(int i=0;i<=r;i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder,inorder,ind,l,r);
    }
};
