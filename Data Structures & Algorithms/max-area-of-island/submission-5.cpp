class Solution {
public:

        vector<int> r={-1,0,1,0};
        vector<int> c={0,1,0,-1};
    int dfs(int i,int j,vector<vector<int>>& grid,int& cnt){
        grid[i][j]=-1;
        int res=1;
        for(int k=0;k<4;k++){
            int nr=r[k]+i;
            int nc=c[k]+j;
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1){
                res+=dfs(nr,nc,grid,cnt);
            }
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int cnt=dfs(i,j,grid,cnt);
                    res=max(res,cnt);
                }
            }
        }
       return res;
    }
};
