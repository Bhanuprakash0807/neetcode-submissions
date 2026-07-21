class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        dp[0]=0;
        int lastp=0;
        for(int i=1;i<=n;i++){
            if((i & (i-1))==0){
                dp[i]=1;
                lastp=i;
            }
            else{
                dp[i]=1+dp[i%lastp];
            }
        }
        return dp;
    }
};
