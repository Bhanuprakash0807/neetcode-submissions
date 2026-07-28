class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fcnt=0;
        int tcnt=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fcnt++;
                }
            }
        }
        tcnt=fcnt+q.size();
        if(fcnt==0){
            return 0;
        }
        if(tcnt==fcnt){
            return -1;
        }
        int time=1;
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
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fcnt--;
                    }
                }
            }
            if(fcnt==0){
                return time;
            }
            time++;
        }
        // if(fcnt==0){
        // return time;
        // }
        return -1;
    }
};
