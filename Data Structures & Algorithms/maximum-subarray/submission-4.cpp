class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int larsum=INT_MIN;
        int l=0;
        int winsum=0;
        for(int r=0;r<nums.size();r++){
            winsum+=nums[r];
            larsum=max(larsum,winsum);
            if(winsum<0){
                winsum=0;
            }
        }
        return larsum;
    }
};
