class Solution {
public:
       vector<vector<int>> res;

    void solve(int l,vector<int>& nums){  
        if(l==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=l;i<nums.size();i++){
            swap(nums[l],nums[i]);
            solve(l+1,nums);
            swap(nums[l],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
       int n=nums.size();
        solve(0,nums);
        return res;
    }
};
