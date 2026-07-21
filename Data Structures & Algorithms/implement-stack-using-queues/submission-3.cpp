class MyStack {
public:
   struct Node{
    int val;
    Node* next;
   };
   Node* q;
    MyStack() {
        q=NULL;
    }
    
    void push(int x) {
        Node* temp=new Node();
        temp->val=x;
        temp->next=q;
        q=temp;
    }
    
    int pop() {
     int val=q->val;
     q=q->next;
     return val;
    }
    
    int top() {
      return q->val;
    }
    
    bool empty() {
       return q==NULL;
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