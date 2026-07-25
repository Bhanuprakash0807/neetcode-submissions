class Solution {
public:
    // int solve(vector<int>& prices,int cur,int ind,int n){
    //     if(ind==n){
    //         return 0;
    //     }
    //     if(dp[cur+1][ind]!=-1) return dp[cur+1][ind];
    //     if(cur==-1){
    //         int nbns=solve(prices,cur,ind+1,n);
    //         int b=solve(prices,ind,ind+1,n)-prices[ind];
    //         return dp[cur+1][ind]=max(nbns,b);
    //     }
    //     int nbns=solve(prices,cur,ind+1,n);
    //     int s=solve(prices,-1,ind+1,n)+prices[ind];
    //     return dp[cur+1][ind]=max(nbns,s);
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));;
            for(int ind=n-1;ind>=0;ind--){
        for(int cur=n-1;cur>=-1;cur--){
                if(cur==-1){
                    int nbns=dp[cur+1][ind+1];
                    int b=dp[ind+1][ind+1]-prices[ind];
                    dp[cur+1][ind]=max(nbns,b);
                }
                else{
                    int nbns=dp[cur+1][ind+1];
                    int s=dp[0][ind+1]+prices[ind];
                    dp[cur+1][ind]=max(nbns,s);
                }
            }
        }
      return dp[0][0];
    }
};