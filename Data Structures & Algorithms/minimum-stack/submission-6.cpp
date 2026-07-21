class MinStack {
public:
    stack<long long> st;
    long long curmin;
    MinStack() {
        
    }
    
    void push(int val) {
       if(st.empty()){
        st.push(0);
        curmin=val;
        return;
       }
       st.push(val-curmin);
       if(curmin>val){
        curmin=val;
       }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
       long long val=st.top();
       if(val>0){
        st.pop();
      }
      else{
        st.pop();
        curmin=curmin-val;
      }
    }
    
    int top() {
         long long val=st.top();
       if(val>0){
        return val+curmin;
      }
      return (int)curmin;
    }
    
    int getMin() {
        return (int)curmin;
    }
};
