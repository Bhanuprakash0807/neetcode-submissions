class Solution {
public:
        vector<int> part;
        vector<vector<int>> res;

    void solve(vector<int>& nums,vector<int>& used){
        if(part.size()==nums.size()){
            res.push_back(part);
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            used[i]=1;
            part.push_back(nums[i]);
            solve(nums,used);
            part.pop_back();
            used[i]=0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> used(n,0);
        solve(nums,used);
        return res;
    }
};
