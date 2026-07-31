class Solution {
public:
    vector<bool> dp;
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
        if(s[n-1]!='0'){
            return false;
        }
        dp.resize(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            int end=min(n-1,maxJump+i);
            for(int j=i+minJump;j<=end;j++){
                if(s[j]=='0' && dp[j]){
                    dp[i]=true;
                }
            }
        }
        return dp[0];
    }
};