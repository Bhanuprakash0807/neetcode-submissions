class MyHashSet {
public:
   vector<int> set;
    MyHashSet() {
      set.resize(31251);
    }
    int getMask(int key){
        return 1<<(key%32);
    }
    void add(int key) {
       set[key/32]|=getMask(key);
    }
    
    void remove(int key) {
        if(set[key/32] & getMask(key)){
            set[key/32]^=getMask(key);
        }
    }
    
    bool contains(int key) {
       return set[key/32]&getMask(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */