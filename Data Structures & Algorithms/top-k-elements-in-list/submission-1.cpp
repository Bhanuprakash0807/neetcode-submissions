class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n=nums.size();
       unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<vector<int>> fre(n+1);
        for(auto& it:mpp){
            fre[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i=n;i>=1;i--){
            for(auto num:fre[i]){
                res.push_back(num);
                if(res.size()==k){
                    return res;
                }
            }
        }
    }
};
