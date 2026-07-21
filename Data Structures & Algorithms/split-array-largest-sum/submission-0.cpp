class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int r=0;
        for(int i=0;i<n;i++){
            l=max(l,nums[i]);
            r+=nums[i];
        }
        int res=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            int ans=1;
            int sum=0;
            for(int i=0;i<n;i++){
                if(sum+nums[i]<=mid){
                    sum+=nums[i];
                }
                else{
                    sum=nums[i];
                    ans++;
                }
            }
            if(ans<=k){
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