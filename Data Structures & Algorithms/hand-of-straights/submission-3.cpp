class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       map<int,int> mpp;
       int n=hand.size();
       for(int i=0;i<n;i++){
            mpp[hand[i]]++;
       }
       vector<pair<int,int>> v;
       for(auto& it:mpp){
        v.push_back({it.first,it.second});
       }
       sort(v.begin(),v.end(),greater<pair<int,int>>());
       for(int i=0;i<v.size();i++){
        if(mpp[v[i].first]==0){
            continue;
        }
        int num=v[i].first;
        int fre=mpp[num];
        int gs=groupSize-1;
        num=num-1;
        while(gs){
            if(mpp[num]<fre){
                return false;
            }
            mpp[num]-=fre;
            num--;
            gs--;
        }
       }
       return true;
    }
};
