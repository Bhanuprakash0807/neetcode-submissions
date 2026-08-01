class Solution {
public:
    string reorganizeString(string s) {
        int len=s.size();
        vector<int> hash(26,0);
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<len;i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash[i]>0){
                pq.push({hash[i],i+'a'});
            }
        }
        string res="";
        pair<int,char> prev={0,' '};
        while(!pq.empty() || prev.first>0){
            if(pq.empty() && prev.first>0){
                return "";
            }
            pair<int,char> pr=pq.top();
            pq.pop();
            int fre=pr.first;
            char ch=pr.second;
            res+=ch;
            fre--;
            if(prev.first>0){
                pq.push(prev);
            }
            prev={fre,ch};
        }
        return res;
    }
};