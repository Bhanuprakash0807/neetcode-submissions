class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int n=nums.size();
        int res=INT_MAX;
      for(int i=0;i<n;i++){
        int cursum=0;
        for(int j=i;j<n;j++){
            cursum+=nums[j];
            if(cursum>=target){
                res=min(res,j-i+1);
                break;
            }
        }
      }
      if(res==INT_MAX){
        return 0;
      }
      return res;
    }
};