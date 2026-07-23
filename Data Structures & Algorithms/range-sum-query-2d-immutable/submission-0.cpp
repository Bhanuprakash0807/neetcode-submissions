class NumMatrix {
public:
    vector<vector<int>> premat;
    NumMatrix(vector<vector<int>>& matrix) {
        premat.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i=0;i<matrix.size();i++){
            int sum=0;
            for(int j=0;j<matrix[0].size();j++){
                sum+=matrix[i][j];
                premat[i+1][j+1]=sum;
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            int sum=0;
            for(int i=0;i<matrix.size();i++){
                sum+=premat[i+1][j+1];
                premat[i+1][j+1]=sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (premat[row2+1][col2+1]-premat[row2+1][col1])-(premat[row1][col2+1]-premat[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */