class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        int l=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<s1.size();i++){
            mpp[s1[i]]++;
        }
        int cnt=0;
        int r=0;
        int n=s2.size();
        int minlen=INT_MAX;
        while(r<n){
            if(mpp[s2[r]]>0){
                cnt++;
            }
            mpp[s2[r]]--;
            while(cnt==k){
                if((r-l+1)<minlen){
                    minlen=r-l+1;
                }
                mpp[s2[l]]++;
                if(mpp[s2[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(minlen==k){
            return true;
        }
        return false;
    }
};
