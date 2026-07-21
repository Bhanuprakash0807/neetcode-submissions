class Solution {
public:

    bool canPlace(int row,int col,vector<string>& board){
        int r=row;
        int c=col;
        //up
        for(int i=0;i<r;i++){
            if(board[i][c]=='Q'){
                return false;
            }
        }
        //upleft
        while(r>=0 && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c--;
        }
        //upright
        r=row;
        c=col;
        while(r>=0 && c<board.size()){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c++;
        }
        return true;
    }

    void solve(vector<string>& board,int n,int row,vector<vector<string>>& res){
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(canPlace(row,col,board)){
                board[row][col]='Q';
                solve(board,n,row+1,res);
                board[row][col]='.';
            }
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
