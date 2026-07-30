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
        dp.resize(n,-1);
        return solve(nums,n,0);
    }
};
