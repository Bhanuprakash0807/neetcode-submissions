class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        while(!pq.empty()){
            pair<int,char> pr=pq.top();
            pq.pop();
            int fre=pr.first;
            char ch=pr.second;
            if(res.size()>1 && res[res.size()-1]==ch && res[res.size()-2]==ch){
                if(pq.empty()) break;
                pair<int,char>  pr2=pq.top();
                pq.pop();
                int fre2=pr2.first;
                char ch2=pr2.second;
                    fre2--;
                if(fre2>0){
                    pq.push({fre2,ch2});
                }
                res+=ch2;
                pq.push(pr);
            }
            else{
            res+=ch;
            fre--;
            if(fre>0){
                pq.push({fre,ch});
            }
            }
        }
        return res;
    }
};