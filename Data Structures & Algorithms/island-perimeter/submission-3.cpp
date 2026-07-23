class Solution {
public:

    vector<int> r={-1,0,1,0};
    vector<int> c={0,1,0,-1};
    void bfs(int i,int j,vector<vector<int>>& grid,int& cnt){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=-1;
        while(!q.empty()){
            auto it=q.front();
            int row=it.first;
            int col=it.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r[k]+row;
                int nc=c[k]+col;
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size()){
                    if(grid[nr][nc]==1){
                        grid[nr][nc]=-1;
                        q.push({nr,nc});
                    }
                    else if(grid[nr][nc]==-1){
                        continue;
                    }
                    else{
                        cnt++;
                    }
                }
                else{
                    cnt++;
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bfs(i,j,grid,cnt);
                    break;
                }
            }
        }
        return cnt;
    }
};