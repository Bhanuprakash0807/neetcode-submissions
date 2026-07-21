class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=0;
        int i=0;
        int n=nums.size();
        while(i<n-1){
            if(nums[i]!=nums[i+1]){
                nums[ind]=nums[i];
                ind++;
            }
            i++;
        }
        if(ind==0){
            nums[ind]=nums[n-1];
            ind++;
            return ind;
        }
        if(ind>0 && nums[n-1]!=nums[ind-1]){
            nums[ind]=nums[n-1];
            ind++;
        }
        return ind;
    }
};