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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> s;
        dfs(s,root);
        return join(s,',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals=split(data,',');
        int ind=0;
        return dfsd(vals,ind);
    }
private:
    void dfs(vector<string>& s,TreeNode* root){
        if(root==NULL){
            s.push_back("N");
            return;
        }
        s.push_back(to_string(root->val));
        dfs(s,root->left);
        dfs(s,root->right);
    }

    string join(vector<string>& s,char delim){
        ostringstream res;
        for(auto& ele: s){
            if(&ele!=&s[0]){
                res << delim;
            }
            res<< ele;
        }
        return res.str();
    }

    vector<string> split(string& data,char delim){
        vector<string> elems;
        stringstream ss(data);
        string item;
        while(getline(ss,item,delim)){
            elems.push_back(item);
        }
        return elems;
    }

    TreeNode* dfsd(vector<string>& vals,int& ind){
        if(vals[ind]=="N"){
            ind++;
            return NULL;
        }
        TreeNode* node=new TreeNode(stoi(vals[ind]));
        ind++;
        node->left=dfsd(vals,ind);
        node->right=dfsd(vals,ind);
        return node;
    }

};
