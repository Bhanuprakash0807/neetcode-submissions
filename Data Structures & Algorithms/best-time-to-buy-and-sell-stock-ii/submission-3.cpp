class Solution {
public:
        vector<vector<int>> dp;
    int solve(vector<int>& prices,int cur,int ind,int n){
        if(ind==n){
            return 0;
        }
        if(dp[cur+1][ind]!=-1) return dp[cur+1][ind];
        if(cur==-1){
            int nbns=solve(prices,cur,ind+1,n);
            int b=solve(prices,ind,ind+1,n)-prices[ind];
            return dp[cur+1][ind]=max(nbns,b);
        }
        int nbns=solve(prices,cur,ind+1,n);
        int s=solve(prices,-1,ind+1,n)+prices[ind];
        return dp[cur+1][ind]=max(nbns,s);
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(n+1,-1));
      return solve(prices,-1,0,n);
    }
};