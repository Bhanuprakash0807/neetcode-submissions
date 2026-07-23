class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       int m=board.size();
       int n=board[0].size();
       for(int i=0;i<m;i++){
        unordered_set<int> r;
        for(int j=0;j<n;j++){
            if(board[i][j]=='.'){
                continue;
            }
            if(r.count(board[i][j])){
                return false;
            }
            r.insert(board[i][j]);
        }
       }
       for(int i=0;i<n;i++){
        unordered_set<int> c;
        for(int j=0;j<m;j++){
            if(board[j][i]=='.'){
                continue;
            }
            if(c.count(board[j][i])){
                return false;
            }
            c.insert(board[j][i]);
        }
       }
       for(int k=0;k<9;k++){
        unordered_set<int> st;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int row=(k/3)*3+i;
                    int col=(k%3)*3+j;
                    if(board[row][col]=='.'){
                        continue;
                    }
                    if(st.count(board[row][col])){
                        return false;
                    }
                    st.insert(board[row][col]);
                }
            }
       }
    return true;
    }
};
