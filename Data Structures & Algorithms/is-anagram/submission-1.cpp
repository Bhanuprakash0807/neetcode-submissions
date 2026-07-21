class Solution {
public:
    bool isAnagram(string s, string t) {
      vector<int> v(26);
      int len1=s.size();
      int len2=t.size();
      if(len1!=len2){
        return false;
      }
      for(int i=0;i<len1;i++){
        v[s[i]-'a']++;
      }
      for(int i=0;i<len2;i++){
        v[t[i]-'a']--;
      }
      for(int i=0;i<len1;i++){
        if(v[s[i]-'a']!=0){
            return false;
        }
      }
      return true;
    }
};
