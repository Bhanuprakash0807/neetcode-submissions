class Solution {
public:

    void fun(vector<vector<int>>& res,vector<int>& subset,vector<int>& nums,int ind){
       res.push_back(subset);
        for(int i=ind;i<nums.size();i++){
            subset.push_back(nums[i]);
            fun(res,subset,nums,i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        fun(res,subset,nums,0);
        return res;
    }
};
