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
    TreeNode* deleteNode(TreeNode* root, int key) {
       TreeNode* cur=root;
       TreeNode* prev=NULL;
       while(cur && cur->val!=key){
            prev=cur;
        if(cur->val<key){
            cur=cur->right;
        }
        else{
            cur=cur->left;
        }
       }
       if(cur==NULL){
        return root;
       }
       else{
        if(cur->left==NULL){
            TreeNode* temp=cur->right;
            if(prev==NULL){
                return temp;
            }
            else{
                if(prev->left==cur){
                    prev->left=temp;
                }
                else{
                    prev->right=temp;
                }
            }
        }
        else if(cur->right==NULL){
            TreeNode* temp=cur->left;
            if(prev==NULL){
                return temp;
            }
            else{
                if(prev->left==cur){
                    prev->left=temp;
                }
                else{
                    prev->right=temp;
                }
            }
        }
        else{
            TreeNode* temp=cur->right;
            TreeNode* par=NULL;
            while(temp->left){
                par=temp;
                temp=temp->left;
            }
            cur->val=temp->val;
            if(par==NULL){
                cur->right=temp->right;
                delete temp;
            }
            else{
                par->left=temp->right;
                temp->right=NULL;
                delete temp;
            }
        }
       }
       return root;
    }
};