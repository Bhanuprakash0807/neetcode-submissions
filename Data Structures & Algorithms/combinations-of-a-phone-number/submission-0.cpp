class Solution {
public:

    void solve(string& digits,string& s,vector<string>& res,int ind,vector<string>& mpp){
        if(ind==digits.size()){
            res.push_back(s);
            return;
        }
        if(ind>digits.size()){
            return;
        }
        char ch=digits[ind];
        for(int i=0;i<mpp[ch-'0'].size();i++){
            s.push_back(mpp[ch-'0'][i]);
            solve(digits,s,res,ind+1,mpp);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> mpp(10);
         mpp[2]="abc";
         mpp[3]="def";
         mpp[4]="ghi";
         mpp[5]="jkl";
         mpp[6]="mno";
         mpp[7]="pqrs";
         mpp[8]="tuv";
         mpp[9]="wxyz";
         vector<string> res;
        if(digits.size()==0){
            return res;
        }
         string s="";
         solve(digits,s,res,0,mpp);
         return res;
    }
};
