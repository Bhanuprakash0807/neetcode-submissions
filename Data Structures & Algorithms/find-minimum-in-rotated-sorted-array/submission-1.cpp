class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int res=INT_MAX;
        while(l<=r){
            if(nums[l]<=nums[r]){
                return min(res,nums[l]);
            }
            int mid=l+(r-l)/2;
            if(nums[l]<=nums[mid]){
                // res=min(res,nums[l]);
                l=mid+1;
            }
            else{
                res=min(res,nums[mid]);
                r=mid-1;
            }
        }
        return res;
    }
};
