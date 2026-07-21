class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int maxi=piles[0];
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int res=maxi;
        int r=maxi;
        while(l<=r){
            int mid=l+(r-l)/2;
            int ans=0;
            for(int i=0;i<n;i++){
                ans+=(piles[i]+mid-1)/mid;
            }
            if(ans<=h){
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
