class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st1.empty()){
            st1.push(val);
            st2.push(val);
            return;
        }
        int curmin=st2.top();
        int newmin=min(val,curmin);
        st1.push(val);
        st2.push(newmin);
    }
    
    void pop() {
        if(st1.empty()){
            return;
        }
        st1.pop();
        st2.pop();
    }
    
    int top() {
        if(st1.empty()){
            return -1;
        }
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
