class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mpp;
        int n=order.size();
        int m=words.size();
        for(int i=0;i<n;i++){
            mpp[order[i]]=i;
        }
        int ind=0;
        while(ind<m-1){
            string s1=words[ind];
            string s2=words[ind+1];
            for(int i=0;i<s1.size();i++){
                if(i==s2.size()) return false;
                if(s1[i]==s2[i]) continue;
                if(mpp[s1[i]]>mpp[s2[i]]) return false;
                break;
            }
            ind++;
        }
        return true;
    }
};