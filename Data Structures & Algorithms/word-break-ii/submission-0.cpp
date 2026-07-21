class Solution {
public:

        unordered_set<string> st;
    void solve(vector<string>& res,string cur,int ind,string& s){
        if(ind==s.size()){
            res.push_back(cur);
            return;
        }
        for(int i=ind;i<s.size();i++){
            string subst=s.substr(ind,i-ind+1);
            if(st.count(subst)){
                if(cur.empty()){
                    solve(res,subst,i+1,s);
                }
                else{
                solve(res,cur+" "+subst,i+1,s);
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string cur="";
        for(string word: wordDict){
            st.insert(word);
        }
        solve(res,cur,0,s);
        return res;
    }
};