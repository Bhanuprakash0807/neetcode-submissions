class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        int maxf=0;
        int l=0;
        int r=0;
        int n=s.size();
        unordered_map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            while((r-l+1)-maxf>k){
                mpp[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};
