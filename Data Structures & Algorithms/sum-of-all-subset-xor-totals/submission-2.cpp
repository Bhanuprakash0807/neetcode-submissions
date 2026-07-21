class Solution {
public:
    int res=0;
    void fun(vector<int>& nums,int ind,int sum){
        if(ind==nums.size()){
            res+=sum;
            return ;
        }
        fun(nums,ind+1,sum^nums[ind]);
        fun(nums,ind+1,sum);
    }
    int subsetXORSum(vector<int>& nums) {
        fun(nums,0,0);
        return res;
    }
};