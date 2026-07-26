class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int min_ind=i;
            for(int j=i;j<n;j++){
                if(nums[min_ind]>nums[j]){
                    min_ind=j;
                }
            }
            swap(nums[min_ind],nums[i]);
        }
        return nums;
    }
};