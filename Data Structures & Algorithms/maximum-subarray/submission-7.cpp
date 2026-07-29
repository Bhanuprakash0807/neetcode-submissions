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
        dp[n-1][1]=max(0,nums[n-1]);
        dp[n-1][0]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1){
                    dp[i][j]=max(0,nums[i]+dp[i+1][j]);
                }
                else{
                    dp[i][j]=max(dp[i+1][j],nums[i]+dp[i+1][1]);
                }
            }
        }
        return dp[0][0];
    }
};
