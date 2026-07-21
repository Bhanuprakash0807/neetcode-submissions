class Solution {
public:
    vector<int> r={-1,0,1,0};
    vector<int> c={0,1,0,-1};
    bool solve(vector<vector<char>>& board,string& word,int ind,int row,int col){
        if(ind==word.size()){
            return true;
        }
        for(int i=0;i<4;i++){
            int nr=row+r[i];
            int nc=col+c[i];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && board[nr][nc]==word[ind]){
                board[nr][nc]='#';
                if(solve(board,word,ind+1,nr,nc)){
                    board[nr][nc]=word[ind];
                    return true;
                }
                board[nr][nc]=word[ind];
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    board[i][j]='#';
                    if(solve(board,word,1,i,j)){
                    board[i][j]=word[0];
                        return true;
                    }
                    board[i][j]=word[0];
                }
            }
        }
        return false;
    }
};
