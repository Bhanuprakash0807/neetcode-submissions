class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int res=0;
       for(int i=0;i<s.size();i++){
        unordered_set<char> st;
        for(int j=i;j<s.size();j++){
            if(st.find(s[j])!=st.end()){
                break;
            }
            st.insert(s[j]);
        }
        res=max(res,(int)st.size());
       }
       return res;
    }
};
