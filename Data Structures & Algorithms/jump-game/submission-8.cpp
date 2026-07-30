class Solution {
public:

    bool solve(vector<int>& nums,int n,int ind){
        if(ind>=n-1){
            return true;
        }
        int maxJ=nums[ind];
        for(int i=ind+1;i<=ind+nums[ind];i++){
            if(solve(nums,n,i)){
                return true;
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,n,0);
    }
};
