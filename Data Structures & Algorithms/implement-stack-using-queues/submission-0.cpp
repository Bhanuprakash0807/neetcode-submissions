class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int sz=q1.size();
        for(int i=0;i<sz-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int val=q1.front();
        q1.pop();
        queue<int> temp;
        q1=q2;
        q2=temp;
        return val;
    }
    
    int top() {
       int sz=q1.size();
        for(int i=0;i<sz-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int val=q1.front();
        q1.pop();
        q2.push(val);
        queue<int> temp;
        q1=q2;
        q2=temp;
        return val;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */