class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size()==1) return nums; 
        int n=nums.size();
        int ele1=0;
        int ele2=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
            else if(cnt1==0){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0){
                cnt2=1;
                ele2=nums[i];
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int num:nums){
            if(num==ele1){
                cnt1++;
            }
            if(num==ele2){
                cnt2++;
            }
        }
        vector<int> res;
        if(cnt1>n/3) res.push_back(ele1);
        if(cnt2>n/3) res.push_back(ele2);
        return res;
    }
};