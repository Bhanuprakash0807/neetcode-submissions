class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int n=s.size();
        int k=t.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<k;i++){
            mpp[t[i]]++;
        }
        int minlen=INT_MAX;
        int cnt=0;
        int sind=-1;
        while(r<n){
            if(mpp[s[r]]>0){
                cnt++;
            }
            mpp[s[r]]--;
            while(cnt==k){
                if((r-l+1)<minlen){
                    minlen=r-l+1;
                    sind=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(sind==-1){
            return "";
        }
        return s.substr(sind,minlen);
    }
};
