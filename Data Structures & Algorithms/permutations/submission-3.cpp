class Solution {
public:
       vector<vector<int>> res;
       int mask=0;
       vector<int> perm;

    void solve(vector<int>& nums){
        if(perm.size()==nums.size()){
            res.push_back(perm);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mask & (1<<i)){
                continue;
            }
            mask=mask | (1<<i);
            perm.push_back(nums[i]);
            solve(nums);
            mask=mask ^ (1<<i);
            perm.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
       int n=nums.size();
        solve(nums);
        return res;
    }
};
