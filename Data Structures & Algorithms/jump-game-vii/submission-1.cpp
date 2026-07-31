class Solution {
public:
    vector<int> dp;
    bool solve(string& s,int mini,int maxi,int n,int ind){
        if(ind==n-1){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int end=min(n-1,ind+maxi);
        for(int i=ind+mini;i<=end;i++){
            if(s[i]=='0' && solve(s,mini,maxi,n,i)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }

    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        dp.resize(n,-1);
        return solve(s,minJump,maxJump,n,0);
    }
};