class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> diff(n,0);
        for(int i=0;i<trust.size();i++){
            diff[trust[i][1]-1]++;
            diff[trust[i][0]-1]--;
        }
        for(int i=0;i<n;i++){
            if(diff[i]==n-1){
                return i+1;
            }
        }
        return -1;
    }
};