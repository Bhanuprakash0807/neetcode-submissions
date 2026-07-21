class Solution {
public:

    int dfs(int ind,int k,vector<int>& nums,int n,vector<vector<int>>& dp){
        if(ind==n && k==0){
            return 0;
        }
        if(ind==n){
            return INT_MAX;
        }
        if(k==0){
            return INT_MAX;
        }
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        int res=INT_MAX;
        int cursum=0;
        for(int i=ind;i<=n-k;i++){
            cursum+=nums[i];
            res=min(res,max(cursum,dfs(i+1,k-1,nums,n,dp)));
        }
        return dp[ind][k]=res;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
       return dfs(0,k,nums,n,dp);
    }
};