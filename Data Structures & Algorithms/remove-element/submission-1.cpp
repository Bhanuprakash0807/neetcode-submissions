class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int n=nums.size();
        int j=n-1;
        while(i<=j){
            if(nums[i]!=val){
                i++;
            }
            else{
                swap(nums[i],nums[j]);
                j--;
            }
        }
        return i;
    }
};