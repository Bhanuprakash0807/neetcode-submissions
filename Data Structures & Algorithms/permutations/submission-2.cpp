class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res={{}};
        for(int i=0;i<n;i++){
            int ele=nums[i];
            vector<vector<int>> new_res;
            for(int j=0;j<res.size();j++){
                for(int k=0;k<=res[j].size();k++){
                    vector<int> cpy=res[j];
                    cpy.insert(cpy.begin()+k,nums[i]);
                    new_res.push_back(cpy);
                }
            }
            res=new_res;
        }
        return res;
    }
};
