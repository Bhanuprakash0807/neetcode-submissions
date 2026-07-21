class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto s: strs){
            vector<int> count(26,0);
            for(auto ch: s){
                count[ch-'a']++;
            }
            string key=to_string(count[0]);
            int sz=count.size();
            for(int i=1;i<sz;i++){
                key+=','+to_string(count[i]);
            }
            mpp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto& it: mpp){
            res.push_back(it.second);
        }
        return res;
    }
};
