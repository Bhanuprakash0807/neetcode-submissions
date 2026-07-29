class Solution {
public:

    vector<vector<int>> dp;
    int solve(vector<int>& nums,int ind,bool flag,int n){
        if(ind==n-1){
            if(flag==true){
                return  max(0,nums[ind]);
            }
            return nums[ind];
        }
        if(dp[ind][flag]!=-1){
            return dp[ind][flag];
        }
        if(flag==true){
            return dp[ind][flag]=max(0,nums[ind]+solve(nums,ind+1,flag,n));
        }
        return dp[ind][flag]=max(solve(nums,ind+1,flag,n),nums[ind]+solve(nums,ind+1,true,n));
    }

    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(2,0);
        vector<int> temp(2,0);
        v[1]=max(0,nums[n-1]);
        v[0]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1){
                    temp[j]=max(0,nums[i]+v[j]);
                }
                else{
                    temp[j]=max(v[j],nums[i]+v[1]);
                }
            }
            v=temp;
        }
        return v[0];
    }
};
