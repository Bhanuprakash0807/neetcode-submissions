class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==1){
            return false;
        }
        unordered_map<int,int> mpp;
        int n=nums.size();
        int l=0;
        int r=0;
        k=min(k,n);
        for(int i=0;i<=k;i++){
            if(mpp[nums[i]]==1){
                return true;
            }
            mpp[nums[i]]=1;
        }
        r=k+1;
        l=1;
        mpp[nums[0]]=0;
        while(r<n){
            if(mpp[nums[r]]==1){
                return true;
            }
            mpp[nums[r]]=1;
            mpp[nums[l]]=0;
            l++;
            r++;
        }
        return false;
    }
};