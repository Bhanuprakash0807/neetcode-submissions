class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            int d=dis(points[i]);
            pq.push({d,{points[i][0],points[i][1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            pair<int,pair<int,int>> pr=pq.top();
            pq.pop();
            res.push_back({pr.second.first,pr.second.second});
        }
        return res;
    }

    int dis(vector<int>& point){
        int x=point[0];
        int y=point[1];
        return x*x+y*y;
    }
};
