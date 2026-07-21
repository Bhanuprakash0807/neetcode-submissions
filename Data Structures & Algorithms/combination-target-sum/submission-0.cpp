class Solution {
public:

    void fun(vector<vector<int>>& res,vector<int>& subset,vector<int>& nums,int target,int ind){
       if(target==0){
        res.push_back(subset);
        return;
       }
       if(ind>=nums.size()){
        return;
       }
       if(target>=nums[ind]){
        subset.push_back(nums[ind]);
        fun(res,subset,nums,target-nums[ind],ind);
        subset.pop_back();
       }
        fun(res,subset,nums,target,ind+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        fun(res,subset,nums,target,0);
        return res;
    }
};
