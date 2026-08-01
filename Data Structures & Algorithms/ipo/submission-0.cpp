class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<int> indices(n);
        for(int i=0;i<n;i++){
            indices[i]=i;
        }
        sort(indices.begin(),indices.end(),[&](int a,int b){
            return capital[a]<capital[b];
        });
        priority_queue<int> pq;
        int idx=0;
        for(int i=0;i<k;i++){
            while(idx<n && capital[indices[idx]]<=w){
                pq.push(profits[indices[idx]]);
                idx++;
            }
            if(pq.empty())  break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};