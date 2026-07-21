class Solution {
public:

    bool isPalindrome(string s){
        int l=0;
        int n=s.size();
        int r=n-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void fun(vector<vector<string>>& res,vector<string>& v,string& s,int ind){
        if(ind==s.size()){
            res.push_back(v);
            return ;
        }
        for(int i=ind;i<s.size();i++){
            string subst=s.substr(ind,i-ind+1);
            if(!isPalindrome(subst)){
                continue;
            }
            v.push_back(subst);
            fun(res,v,s,i+1);
            v.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        fun(res,v,s,0);
        return res;
    }
};
