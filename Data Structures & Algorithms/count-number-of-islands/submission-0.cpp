class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> r={-1,0,1,0};
        vector<int> c={0,1,0,-1};
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]=-1;
                    while(!q.empty()){
                        auto it=q.front();
                        int row=it.first;
                        int col=it.second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=row+r[k];
                            int nc=col+c[k];
                            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]=='1'){
                                grid[nr][nc]='#';
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
