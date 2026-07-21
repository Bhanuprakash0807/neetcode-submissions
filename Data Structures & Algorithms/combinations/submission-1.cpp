class Solution {
public:

    void fun(vector<vector<int>>& res,vector<int>& subset,int n,int k,int ind){
        if(subset.size()==k){
            res.push_back(subset);
            return;
        }
        int need=k-subset.size();
        for(int i=ind;i<=n-need+1;i++){
            subset.push_back(i);
            fun(res,subset,n,k,i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        fun(res,subset,n,k,1);
        return res;
    }
};