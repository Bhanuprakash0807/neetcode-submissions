class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       unordered_map<int,int> mpp;
       int n=hand.size();
       for(int i=0;i<n;i++){
            mpp[hand[i]]++;
       }
       vector<int> v;
       for(auto& it:mpp){
        v.push_back(it.first);
       }
       sort(v.begin(),v.end(),greater<int>());
       for(int i=0;i<v.size();i++){
        if(mpp[v[i]]==0){
            continue;
        }
        int num=v[i];
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
