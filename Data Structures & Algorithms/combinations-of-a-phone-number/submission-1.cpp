class Solution {
public:

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
        //  vector<string> res;
         res.push_back(s);
         for(char& ch: digits){
            vector<string> tmp;
            for(string& curstr: res){
                for(char& alpha: mpp[ch-'0']){
                    tmp.push_back(curstr+alpha);
                }
            }
            res=tmp;
         }
         return res;
    }
};
