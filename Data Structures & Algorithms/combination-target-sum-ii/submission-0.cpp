class Solution {
public:

    void fun(vector<vector<int>>& res,vector<int>& candidates,vector<int>& subset,int target,int ind){
        if(target==0){
            res.push_back(subset);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]){
                continue;
            }
            subset.push_back(candidates[i]);
            fun(res,candidates,subset,target-candidates[i],i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        fun(res,candidates,subset,target,0);
        return res;
    }
};
