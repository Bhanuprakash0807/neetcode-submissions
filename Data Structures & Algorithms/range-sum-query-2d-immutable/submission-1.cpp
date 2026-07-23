class NumMatrix {
public:
    int m;
    int n;
    vector<vector<int>> premat;
    NumMatrix(vector<vector<int>>& matrix) {
        premat.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        m=matrix.size();
        n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                premat[i+1][j+1]=matrix[i][j]+premat[i][j+1]+premat[i+1][j]-premat[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       return premat[row2+1][col2+1]-premat[row1][col2+1]-premat[row2+1][col1]+premat[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */