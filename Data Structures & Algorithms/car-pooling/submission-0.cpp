class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<pair<int,int>> points;
        for(int i=0;i<n;i++){
            points.push_back({trips[i][1],trips[i][0]});
            points.push_back({trips[i][2],-trips[i][0]});
        }
        sort(points.begin(),points.end(),[](pair<int,int>& a,pair<int,int>& b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        });
        int sum=0;
        for(pair<int,int>& pr:points){
            sum+=pr.second;
            if(sum>capacity){
                return false;
            }
        }
        return true;
    }
};