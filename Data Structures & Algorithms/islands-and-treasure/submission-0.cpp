class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int time=1;
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<int> r={-1,0,1,0};
        vector<int> c={0,1,0,-1};
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
            auto pr=q.front();
            int row=pr.first;
            int col=pr.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+r[i];
                int nc=col+c[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    if(grid[nr][nc]>time){
                        grid[nr][nc]=time;
                        q.push({nr,nc});
                    }
                }
            }
            }
            time++;
        }
    }
};
