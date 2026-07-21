class Solution {
public:

    unordered_set<int> col;
    unordered_set<int> posdiag;
    unordered_set<int> negdiag;

    void solve(vector<string>& board,int n,int row,vector<vector<string>>& res){
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int c=0;c<n;c++){
            if(col.count(c) || posdiag.count(row+c) || negdiag.count(row-c)){
                continue;
            }
                board[row][c]='Q';
                col.insert(c);
                posdiag.insert(row+c);
                negdiag.insert(row-c);
                solve(board,n,row+1,res);
                col.erase(c);
                posdiag.erase(row+c);
                negdiag.erase(row-c);
                board[row][c]='.';
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> res;
        solve(board,n,0,res);
        return res;
    }
};
