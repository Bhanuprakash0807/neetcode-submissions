class Solution {
public:

    bool solve(vector<int>& nums,int ind,vector<int>& used,
    int k,long long int tar,long long int cursum){
        if(k==0){
            return true;
        }    
        if(cursum==tar){
            return solve(nums,0,used,k-1,tar,0);
        }
        for(int i=ind;i<nums.size();i++){
            if(cursum+nums[i]>tar){
                continue;
            }
            if(used[i]){
                continue;
            }
            used[i]=1;
            if(solve(nums,i+1,used,k,tar,cursum+nums[i])){
                return true;
            }
            used[i]=0;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%k){
            return false;
        }
        long long int tar=sum/k;
        int n=nums.size();
        vector<int> used(n,0);
        sort(nums.begin(),nums.end(),greater<int>());
        return solve(nums,0,used,k,tar,0);
    }
};