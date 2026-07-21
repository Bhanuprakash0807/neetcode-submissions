class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        int minlen=INT_MAX;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(target<=sum){
                sum-=nums[l];
                if(r-l+1<minlen){
                    minlen=r-l+1;
                }
                l++;
            }
            r++;
        }
        if(minlen==INT_MAX){
            return 0;
        }
        return minlen;
    }
};