class Solution {
public:

    bool solve(vector<int>& matchsticks,vector<int>& v,int ind,int target){
        if(ind==matchsticks.size()){
            if(v[0]==v[1] && v[0]==v[2] && v[0]==v[3]){
                return true;
            }
            return false;
        }
        for(int i=0;i<4;i++){
            if(v[i]+matchsticks[ind]>target){
                continue;
            }
            v[i]+=matchsticks[ind];
            if(solve(matchsticks,v,ind+1,target)){
                return true;
            }
            v[i]-=matchsticks[ind];
            if(v[i]==0){
                break;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        long long int sum=0;
        for(int i=0;i<matchsticks.size();i++){
            sum+=matchsticks[i];
        }
        if(sum%4!=0){
            return false;
        }
        vector<int> v(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return solve(matchsticks,v,0,sum/4);
    }
};