class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp1;
        int req=0;
        for(int i=0;i<t.size();i++){
            mpp1[t[i]]++;
        }
        req=mpp1.size();
        int minlen=INT_MAX;
        int sind=-1;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> mpp2;
            int cur=0;
            for(int j=i;j<s.size();j++){
                mpp2[s[j]]++;
              
                if(mpp1[s[j]] && mpp2[s[j]]==mpp1[s[j]]){
                    cur++;
                }
                int len=j-i+1;
                if(cur==req && len<minlen){
                    minlen=len;
                    sind=i;
                }
            }
        }
        if(sind==-1){
            return "";
        }
        return s.substr(sind,minlen);
    }
};
