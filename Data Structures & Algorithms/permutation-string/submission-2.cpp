class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       unordered_map<char,int> mpp1;
       for(int i=0;i<s1.size();i++){
        mpp1[s1[i]]++;
       }
       int req=mpp1.size();
       for(int i=0;i<s2.size();i++){
       int cur=0;
        unordered_map<char,int> mpp2;
        int j=i;
        while(j<s2.size()){
            mpp2[s2[j]]++;
            if(mpp2[s2[j]]>mpp1[s2[j]]){
                break;
            }
            if(mpp2[s2[j]]==mpp1[s2[j]]){
                cur++;
            }
            if(cur==req){
                return true;
            }
            j++;
        }
       }
       return false;
    }
};
