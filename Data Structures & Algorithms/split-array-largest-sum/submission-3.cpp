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
        vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX));
        dp[n][0]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int j=1;j<=k;j++){
                int res=INT_MAX;
                int cursum=0;
                for(int i=ind;i<=n-j;i++){
                    cursum+=nums[i];
                    res=min(res,max(cursum,dp[i+1][j-1]));
                }
                dp[ind][j]=res;
            }
        }
       return dp[0][k];
    }
};