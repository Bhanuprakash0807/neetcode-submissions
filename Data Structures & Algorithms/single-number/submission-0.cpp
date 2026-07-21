class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorall=0;
        for(int i=0;i<nums.size();i++){
            xorall=xorall^nums[i];
        }
        return xorall;
    }
};
