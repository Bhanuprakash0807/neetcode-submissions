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
            int i1=ind;
            int i2=ind+1;
            string s1=words[i1];
            string s2=words[i2];
            i1=0;
            i2=0;
            bool cont=false;
            while(i1<s1.size() && i2<s2.size()){
                if(s1[i1]==s2[i2]){
                    i1++;
                    i2++;
                }
                else{
                    if(mpp[s1[i1]]<mpp[s2[i2]]){
                        cont=true;
                        break;
                    }
                    else{
                        return false;
                    }
                }
            }
            if(cont){
                ind++;
                continue;
            }
            if(i1==s1.size() && i2==s2.size()){
                ind++;
                continue;
            }
            else if(i1==s1.size()){
                ind++;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};