class Solution {
public:

    bool solve(vector<int>& nums,vector<int>& v,int ind,int target,int k){
        if(ind==nums.size()){
            return true;
        }
        for(int i=0;i<k;i++){
            if(v[i]+nums[ind]>target){
                continue;
            }
            v[i]+=nums[ind];
            if(solve(nums,v,ind+1,target,k)){
                return true;
            }
            v[i]-=nums[ind];
            if(v[i]==0){
                break;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long int sum=0;
        for(int num: nums){
            sum+=num;
        }
        if(sum%k!=0){
            return false;
        }
        vector<int> v(k,0);
        return solve(nums,v,0,sum/k,k);
    }
};