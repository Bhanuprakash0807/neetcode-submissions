class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto& ast: asteroids){
            if(ast>0){
                st.push(ast);
            }
            else{
                int absval=abs(ast);
                bool add=true;
                while(!st.empty() && st.top()>0){
                    if(st.top()>absval){
                        add=false;
                        break;
                    }
                    else if(st.top()==absval){
                        st.pop();
                        add=false;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(add){
                    st.push(ast);
                }
            }
        }
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};