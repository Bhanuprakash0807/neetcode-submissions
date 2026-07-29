class Solution {
public:

    vector<vector<int>> dp;
    int solve(vector<int>& nums,int ind,bool flag,int n){
        if(ind==n-1){
            if(flag==true){
                return  max(0,nums[ind]);
            }
            return nums[ind];
        }
        if(dp[ind][flag]!=-1){
            return dp[ind][flag];
        }
        if(flag==true){
            return dp[ind][flag]=max(0,nums[ind]+solve(nums,ind+1,flag,n));
        }
        return dp[ind][flag]=max(solve(nums,ind+1,flag,n),nums[ind]+solve(nums,ind+1,true,n));
    }

    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(2,-1));
        return solve(nums,0,false,n);
    }
};
