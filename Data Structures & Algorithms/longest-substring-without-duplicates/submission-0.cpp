class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int l=0;
        int r=0;
        int ans=0;
        int n=s.size();
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                l=max(mpp[s[r]]+1,l);
            }
            mpp[s[r]]=r;
            ans=max(ans,(r-l+1));
            r++;
        }
        return ans;
    }
};
