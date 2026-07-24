/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* root=new Node(node->val);
        unordered_map<Node*,Node*> mpp;
        queue<pair<Node*,Node*>> q;
        q.push({node,root});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* nd1=it.first;
            Node* nd2=it.second;
            for(auto& n:nd1->neighbors){
                if(mpp.find(n)!=mpp.end()){
                    nd2->neighbors.push_back(mpp[n]);
                    continue;
                }                
                Node* nnd=new Node(n->val);
                mpp[n]=nnd;
                nd2->neighbors.push_back(nnd);
                q.push({n,nnd});
            }
        }
        return root;
    }
};
