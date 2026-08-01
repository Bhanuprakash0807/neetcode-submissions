class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        int n=tasks.size();
        vector<array<int,3>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(vec.begin(),vec.end());
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;
        int ind=0;
        long long int time=0;
        while(ind<n || !pq.empty()){
            if(pq.empty()){
                time=max(time,(long long)vec[ind][0]);
            }
            while(ind<n && vec[ind][0]<=time){
                pq.push({vec[ind][1],vec[ind][2]});
                ind++;
            }
            pair<int,int> pr=pq.top();
            pq.pop();
            int protime=pr.first;
            int index=pr.second;
            res.push_back(index);
            time+=protime;
        }
        return res;
    }
};