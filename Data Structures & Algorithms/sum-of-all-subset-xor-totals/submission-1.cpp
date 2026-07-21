class Solution {
public:
    int res=0;
    void fun(vector<int>& nums,int sum,int ind){
        res+=sum;
        for(int i=ind;i<nums.size();i++){
            sum^=nums[i];
            fun(nums,sum,i+1);
            sum^=nums[i];
        }
    }

    int subsetXORSum(vector<int>& nums) {
        fun(nums,0,0);
        return res;
    }
};