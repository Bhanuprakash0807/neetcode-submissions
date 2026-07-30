class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int cur=nums[0];
        int maxi=nums[0];
        int steps=1;
        for(int i=1;i<n;i++){
            if(cur<i){
                cur=maxi;
                steps++;
            }
            maxi=max(maxi,nums[i]+i);
        }
        return steps;
    }
};
