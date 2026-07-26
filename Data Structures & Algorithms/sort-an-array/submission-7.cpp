class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxval=INT_MIN;
        int minval=INT_MAX;
        for(int num:nums){
            mpp[num]++;
            minval=min(minval,num);
            maxval=max(maxval,num);
        }
        int ind=0;
        for(int i=minval;i<=maxval;i++){
            while(mpp[i]>0){
                nums[ind]=i;
                ind++;
                mpp[i]--;
            }
        }
        return nums;
    }
};