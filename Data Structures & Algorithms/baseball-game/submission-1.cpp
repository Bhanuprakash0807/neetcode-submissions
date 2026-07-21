class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int res=0;
        for(auto& opr:operations){
            if(opr=="+"){
                int curtop=st.top();
                st.pop();
                int newtop=st.top()+curtop;
                st.push(curtop);
                st.push(newtop);
                res+=newtop;
            }
            else if(opr=="D"){
                st.push(st.top()*2);
                res+=st.top();
            }
            else if(opr=="C"){
                res-=st.top();
                st.pop();
            }
            else{
                st.push(stoi(opr));
                res+=stoi(opr);
            }
        }
        return res;
    }
};