class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums,int n,int ind){
        if(ind==n-1){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int end=min(n-1,ind+nums[ind]);
        int mini=INT_MAX;
        for(int i=ind+1;i<=end;i++){
            int nst=solve(nums,n,i);
            if(nst!=INT_MAX){
                mini=min(mini,1+nst);
            }
        }
        return dp[ind]=mini;
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,INT_MAX);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int end=min(n-1,nums[i]+i);
            int mini=INT_MAX;
            for(int j=i+1;j<=end;j++){
                if(dp[j]!=INT_MAX){
                    mini=min(dp[j]+1,mini);
                }
            }
            dp[i]=mini;
        }
        return dp[0];
    }
};
