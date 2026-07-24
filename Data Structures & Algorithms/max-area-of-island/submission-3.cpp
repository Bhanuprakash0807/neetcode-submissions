class DSU{
private:
vector<int> parent;
public:
vector<int> size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findup(int u){
        if(u==parent[u]) return u;
        return parent[u]=findup(parent[u]);
    }

    bool ubs(int u,int v){
        int upu=findup(u);
        int upv=findup(v);
        if(upu==upv) return false;
        if(size[upu]>=size[upv]){
            size[upu]+=size[upv];
            parent[upv]=upu;
        }
        else{
            size[upv]+=size[upu];
            parent[upu]=upv;
        }
        return true;
    }
};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> r={-1,0,1,0};
        vector<int> c={0,1,0,-1};
        int cnt=0;
        DSU ds(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                    for(int k=0;k<4;k++){
                        int nr=i+r[k];
                        int nc=j+c[k];
                        if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                            if(ds.ubs(i*n+j,nr*n+nc)){
                                cnt--;
                            }
                        }
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
            if(grid[i][j]==0) continue;
                res=max(res,ds.size[ds.findup(i*n+j)]);
           }
        }
        return res;
    }
};
