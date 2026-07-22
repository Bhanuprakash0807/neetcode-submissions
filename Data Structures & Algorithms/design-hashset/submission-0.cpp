class MyHashSet {
public:
    int hash(int x){
        return x%10000;
    }
    struct Node{
        int val;
        struct Node* next;
        Node(int x,Node* nxt){
            val=x;
            next=nxt;
        }
    };
    vector<Node*> list;
    MyHashSet() {
        list.resize(10000,NULL);
       for(int i=0;i<10000;i++){
        list[i]=new Node(-1,NULL);
       }
    }
    
    void add(int key) {
        int h=hash(key);
        Node* ptr=list[h]->next;
        Node* prev=list[h];
        while(ptr!=NULL){
            if(ptr->val==key){
                return;
            }
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=new Node(key,NULL);
    }
    
    void remove(int key) {
         int h=hash(key);
        Node* ptr=list[h]->next;
        Node* prev=list[h];
        while(ptr!=NULL){
            if(ptr->val==key){
                prev->next=ptr->next;
                ptr->next=NULL;
                delete ptr;
                return;
            }
            prev=ptr;
            ptr=ptr->next;
        }
    }
    
    bool contains(int key) {
          int h=hash(key);
        Node* ptr=list[h]->next;
        Node* prev=list[h];
        while(ptr!=NULL){
            if(ptr->val==key){
                return true;
            }
            prev=ptr;
            ptr=ptr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */