class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       unordered_map<int,int> mpp;
       int n=nums.size();
       for(int num:nums){
        mpp[num]++;
        if(mpp.size()>2){
            unordered_map<int,int> nmpp;
            for(auto& ele:mpp){
                if(ele.second>1){
                    nmpp[ele.first]=ele.second-1;
                }
            }
            mpp=nmpp;
        }
       }
       vector<int> res;
       for(auto& ele:mpp){
                int cnt=0;
            for(int num:nums){
                if(ele.first==num){
                    cnt++;
                }
            }
            if(cnt>n/3) res.push_back(ele.first);
       }
       return res;
    }
};