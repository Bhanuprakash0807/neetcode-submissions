class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
       auto& v=mpp[key];
       int l=0;
       int r=v.size()-1;
       string res="";
       while(l<=r){
        int mid=l+(r-l)/2;
        if(v[mid].first<=timestamp){
            res=v[mid].second;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
       }
       return res;
    }
};
