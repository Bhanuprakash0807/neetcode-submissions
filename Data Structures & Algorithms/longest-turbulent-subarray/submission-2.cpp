class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int res=1;
        int l=0;
        int r=0;
        int n=nums.size();
        bool nextgreater=true;
        // if(nums[0]<nums[1]){
        //     nextgreater=true;
        // }
        // else if(nums[0]>nums[1]){
        //     nextgreater=false;
        // }
        while(r<n-1){
            if(nextgreater){
                if(nums[r]<nums[r+1]){
                    l=r;
                    nextgreater=true;
                    r++;
                }
                else if(nums[r]>nums[r+1]){
                    nextgreater=false;
                    r++;
                }
                else{
                    r++;
                    l=r;
                }
            }
            else{
                if(nums[r]<nums[r+1]){
                    nextgreater=true;
                    r++;
                    // res=max(res,r-l+1);
                }
                else if(nums[r]>nums[r+1]){
                    nextgreater=false;
                    l=r;
                    r++;
                }
                else{
                    r++;
                    l=r;
                }
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};