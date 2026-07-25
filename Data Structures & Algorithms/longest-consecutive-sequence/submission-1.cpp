class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int ind=0;
        int res=1;
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                ind++;
            }
            else if(nums[i-1]+1==nums[i]){
                res=max(res,i-ind+1);
            }
            else{
                ind=i;
            }
        }
        return res;
    }
};
