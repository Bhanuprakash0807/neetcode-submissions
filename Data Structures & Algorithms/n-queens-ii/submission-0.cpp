class Solution {
public:

    vector<bool> col,posdiag,negdiag;
    

    void solve(vector<string>& board,int n,int row,vector<vector<string>>& res){
       if(row==n){
        res.push_back(board);
        return;
       }
       for(int c=0;c<n;c++){
        if(col[c] || posdiag[row+c] || negdiag[row-c+n]){
            continue;
        }
        col[c]=1;
        posdiag[row+c]=1;
        negdiag[n+row-c]=1;
        board[row][c]='Q';
        solve(board,n,row+1,res);
        col[c]=0;
        posdiag[row+c]=0;
        negdiag[row-c+n]=0;
        board[row][c]='.';
       }
    }

    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
         vector<vector<string>> res;
        col.resize(n,0);
        posdiag.resize(2*n,0);
        negdiag.resize(2*n,0);
        solve(board,n,0,res);
        return res.size();
    }
};