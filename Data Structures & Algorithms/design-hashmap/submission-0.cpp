class MyHashMap {
public:
    struct Node{
        int key;
        int val;
        struct Node* next;
        Node(int k,int x,Node* nxt){
            key=k;
            val=x;
            next=nxt;
        }
    };
    vector<Node*> list;

    int hash(int key){
        return key%10000;
    }

    MyHashMap() {
        list.resize(10000);
        for(int i=0;i<10000;i++){
            list[i]=new Node(-1,-1,NULL);
        }
    }
    
    void put(int key, int value) {
        int h=hash(key);
        Node* ptr=list[h]->next;
        Node* prev=list[h];
        while(ptr!=NULL){
            if(ptr->key==key){
                ptr->val=value;
                return;
            }
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=new Node(key,value,NULL);
    }
    
    int get(int key) {
 int h=hash(key);
        Node* ptr=list[h]->next;
        while(ptr!=NULL){
            if(ptr->key==key){
                // ptr->val=value;
                return ptr->val;
            }
            ptr=ptr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int h=hash(key);
        Node* ptr=list[h]->next;
        Node* prev=list[h];
        while(ptr!=NULL){
            if(ptr->key==key){
                prev->next=ptr->next;
                delete ptr;
                return ;
            }
            prev=ptr;
            ptr=ptr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */