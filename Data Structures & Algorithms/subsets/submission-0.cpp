class Solution {
public:

    void fun(vector<vector<int>>& res,vector<int>& subset,vector<int>& nums,int ind){
        if(ind==nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        fun(res,subset,nums,ind+1);
        subset.pop_back();
        fun(res,subset,nums,ind+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        fun(res,subset,nums,0);
        return res;
    }
};
