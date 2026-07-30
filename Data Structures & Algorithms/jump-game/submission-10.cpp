class Solution {
public:

    vector<bool> dp;
    bool solve(vector<int>& nums,int n,int ind){
        if(ind==n-1){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int maxJ=nums[ind];
        for(int i=ind+1;i<=ind+nums[ind];i++){
            if(solve(nums,n,i)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            int end=min(n-1,i+nums[i]);
            for(int j=i+1;j<=end;j++){
                if(dp[j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
