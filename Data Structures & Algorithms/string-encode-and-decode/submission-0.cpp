class Solution {
public:

    string encode(vector<string>& strs) {
        int ind=0;
        string enc="";
        string hash="#";
        int n=strs.size();
        while(ind<n){
            enc=enc+to_string(strs[ind].size())+hash+strs[ind];
            ind++;
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        int n=s.size();
        while(i<n){
            string str="";
            string len="";
            while(s[i]!='#'){
                len+=s[i];
                i++;
            }
            i++;
            int l=stoi(len);
            str=s.substr(i,l);
            res.push_back(str);
            i+=l;
        }
        return res;
    }
};
