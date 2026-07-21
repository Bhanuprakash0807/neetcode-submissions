class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string pre=strs[0];
        for(int i=1;i<n;i++){
            string npre="";
            int sz=min(strs[i].size(),pre.size());
            for(int j=0;j<sz;j++){
                if(strs[i][j]!=pre[j]){
                    break;
                }
                npre+=pre[j];
            }
            pre=npre;
        }
        return pre;
    }
};