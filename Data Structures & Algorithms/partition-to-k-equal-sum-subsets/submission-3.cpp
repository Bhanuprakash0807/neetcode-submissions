class Solution {
public:

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long int sum=0;
        for(auto num: nums){
            sum+=num;
        }
        if(sum%k!=0){
            return false;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        vector<bool> used(nums.size(),false);
        return solve(nums,k,used,sum/k,0,0); 
    }
    private:
        bool solve(vector<int>& nums,int k,vector<bool>& used,int target,long long int cursum,int ind){
            if(k==0){
                return true;
            }
            if(cursum==target){
                return solve(nums,k-1,used,target,0,0);
            }
            for(int i=ind;i<nums.size();i++){
                if(used[i] || cursum+nums[i]>target){
                    continue;
                }
                used[i]=true;
                if(solve(nums,k,used,target,cursum+nums[i],i+1)){
                    return true;
                }
                used[i]=false;
            }
            return false;
        }
};