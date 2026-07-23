class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0;
        int i=0;
        int n=nums.size();
        int r=n-1;
        while(i<=r){
            if(nums[i]==0){
                swap(nums[i],nums[l]);
                l++;
                i++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[r]);
                r--;
            }
            else{
                i++;
            }
        }
    }
};