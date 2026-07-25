class Solution {
public:
vector<vector<int>> dp;
    // int solve(vector<int>& prices,int buy,int ind,int n){
    //     if(ind==n){
    //         return 0;
    //     }
    //     if(dp[buy][ind]!=-1) return dp[buy][ind];
    //     if(buy){
    //         int nbns=solve(prices,buy,ind+1,n);
    //         int b=solve(prices,0,ind+1,n)-prices[ind];
    //         return dp[buy][ind]=max(nbns,b);
    //         // return dp[cur+1][ind]=max(nbns,b);
    //     }
    //     int nbns=solve(prices,buy,ind+1,n);
    //     int s=solve(prices,1,ind+1,n)+prices[ind];
    //     // return dp[cur+1][ind]=max(nbns,s);
    //     return dp[buy][ind]=max(nbns,s);
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(2,vector<int>(n+1,0));;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    int nbns=dp[j][i+1];
                    int b=dp[0][i+1]-prices[i];
                    dp[j][i]=max(nbns,b);
                }
                else{
                    int nbns=dp[j][i+1];
                    int s=dp[1][i+1]+prices[i];
                    dp[j][i]=max(nbns,s);
                }
            }
        }
      return dp[1][0];
    }
};