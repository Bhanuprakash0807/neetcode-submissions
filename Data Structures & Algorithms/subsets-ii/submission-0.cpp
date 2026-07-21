class Solution {
public:

    void fun(vector<int>& nums,vector<vector<int>>& res,vector<int>& subset,int ind){
        res.push_back(subset);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            subset.push_back(nums[i]);
            fun(nums,res,subset,i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        fun(nums,res,subset,0);
        return res;
    }
};
