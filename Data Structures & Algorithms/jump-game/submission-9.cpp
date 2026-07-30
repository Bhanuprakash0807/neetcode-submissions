class Solution {
public:

    vector<int> dp;
    bool solve(vector<int>& nums,int n,int ind){
        if(ind>=n-1){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int maxJ=nums[ind];
        for(int i=ind+1;i<=ind+nums[ind];i++){
            if(solve(nums,n,i)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        return solve(nums,n,0);
    }
};
