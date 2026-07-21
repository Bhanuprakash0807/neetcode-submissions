class Solution {
public:

    void fun(int open,int close,string& s,vector<string>& res,int n){
        if(close==0){
            res.push_back(s);
            return;
        }
        if(open>0){
            s.push_back('(');
            fun(open-1,close,s,res,n);
            s.pop_back();
        }
        if(open<close){
            s.push_back(')');
            fun(open,close-1,s,res,n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        string cur="";
        vector<string> res;
        fun(open,close,cur,res,n);
        return res;
    }
};
