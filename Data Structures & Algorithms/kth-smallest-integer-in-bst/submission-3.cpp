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
        while(cur!=NULL){
            if(!cur->left){
                cnt--;
                if(cnt==0){
                    return cur->val;
                }
                cur=cur->right;
            }
            else{
                TreeNode* pre=cur->left;
                while(pre->right && pre->right!=cur){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right=cur;
                    cur=cur->left;
                }
                else{
                    cnt--;
                    if(cnt==0){
                        return cur->val;
                    }
                    pre->right=NULL;
                    cur=cur->right;
                }
            }
        }
    }
};
