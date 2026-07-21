/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node* fun(int size,vector<vector<int>>& grid,int r,int c){
        if(size==1){
            return new Node(grid[r][c] ? true : false,true);
        }
        int n=size;
        bool check=true;
        bool val=grid[r][c] ? true : false;
        for(int i=r;i<r+n;i++){
            for(int j=c;j<c+n;j++){
                if(val!=grid[i][j]){
                    check=false;
                    break;
                }
            }
            if(!check){
                break;
            }
        }
        if(check){
            return new Node(val,true);
        }
        Node* topLeft=fun(n/2,grid,r,c);
        Node* topRight=fun(n/2,grid,r,c+n/2);
        Node* bottomLeft=fun(n/2,grid,r+n/2,c);
        Node* bottomRight=fun(n/2,grid,r+n/2,c+n/2);
        return new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        Node* root=fun(n,grid,0,0);
        return root;
    }
};