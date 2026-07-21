class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0){
            return {{}};
        }
        int n=nums.size();
        vector<vector<int>> res;    
        vector<int> tmp=vector<int>(nums.begin()+1,nums.end());
        vector<vector<int>> temp=permute(tmp);
        for(auto& perm: temp){
            for(int i=0;i<=perm.size();i++){
                vector<int> cpy=perm;
                cpy.insert(cpy.begin()+i,nums[0]);
                res.push_back(cpy);
            }
        }
        return res;
    }
};
