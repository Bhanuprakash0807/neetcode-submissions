class Solution {
public:

    void fun(vector<vector<int>>& res,vector<int>& subset,vector<int>& nums,int target,int ind){
      if(target==0){
        res.push_back(subset);
        return;
      }
      for(int i=ind;i<nums.size();i++){
        if(target<nums[i]){
            break;
        }
        subset.push_back(nums[i]);
        fun(res,subset,nums,target-nums[i],i);
        subset.pop_back();
      }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        fun(res,subset,nums,target,0);
        return res;
    }
};
