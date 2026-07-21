class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=1;
        int r=0;
        for(int i=0;i<n;i++){
            l=max(weights[i],l);
            r+=weights[i];
        }
        int res=1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int wt=0;
            int ans=1;
            for(int i=0;i<n;i++){
                if(weights[i]+wt<=mid){
                    wt+=weights[i];
                }
                else{
                    wt=weights[i];
                    ans++;
                }
                if(ans>days){
                    break;
                }
            }
            if(ans<=days){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};