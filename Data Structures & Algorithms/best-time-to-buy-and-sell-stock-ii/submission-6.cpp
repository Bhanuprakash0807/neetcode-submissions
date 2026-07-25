class Solution {
public:
vector<vector<int>> dp;
    int solve(vector<int>& prices,int buy,int ind,int n){
        if(ind==n){
            return 0;
        }
        if(dp[buy][ind]!=-1) return dp[buy][ind];
        if(buy){
            int nbns=solve(prices,buy,ind+1,n);
            int b=solve(prices,0,ind+1,n)-prices[ind];
            return dp[buy][ind]=max(nbns,b);
            // return dp[cur+1][ind]=max(nbns,b);
        }
        int nbns=solve(prices,buy,ind+1,n);
        int s=solve(prices,1,ind+1,n)+prices[ind];
        // return dp[cur+1][ind]=max(nbns,s);
        return dp[buy][ind]=max(nbns,s);
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(2,vector<int>(n+1,-1));;
        //     for(int ind=n-1;ind>=0;ind--){
        // for(int cur=n-1;cur>=-1;cur--){
        //         if(cur==-1){
        //             int nbns=dp[cur+1][ind+1];
        //             int b=dp[ind+1][ind+1]-prices[ind];
        //             dp[cur+1][ind]=max(nbns,b);
        //         }
        //         else{
        //             int nbns=dp[cur+1][ind+1];
        //             int s=dp[0][ind+1]+prices[ind];
        //             dp[cur+1][ind]=max(nbns,s);
        //         }
        //     }
        // }
      return solve(prices,1,0,n);
    }
};