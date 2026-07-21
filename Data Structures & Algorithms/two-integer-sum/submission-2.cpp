class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
       unordered_map<int,int> mpp;
       for(int i=0;i<n;i++){
        int cmp=target-nums[i];
        if(mpp.count(cmp)){
            return {mpp[cmp],i};
        }
        mpp[nums[i]]=i;
       }
    }
};
