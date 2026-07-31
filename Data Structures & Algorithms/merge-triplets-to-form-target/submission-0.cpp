class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool one=false;
        bool two=false;
        bool three=false;
        int n=triplets.size();
        int a=target[0];
        int b=target[1];
        int c=target[2];
        int cnt=0;
        for(int i=0;i<n;i++){
            int a1=triplets[i][0];
            int b1=triplets[i][1];
            int c1=triplets[i][2];
            if(a1>a || b1>b || c1>c){
                continue;
            }
            if(a1==a){
                one=true;
            }
            if(b1==b){
                two=true;
            }
            if(c1==c){
                three=true;
            }
            if(one && two && three){
                return true;
            }
        }
        return false;
    }
};
