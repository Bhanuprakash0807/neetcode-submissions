class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt=0;
        int l=0;
        int n=people.size();
        int r=n-1;
        sort(people.begin(),people.end());
        while(l<=r){
            if(l==r){
                cnt++;
                break;
            }
            int w1=people[l];
            int w2=people[r];
            if(w1+w2<=limit){
                cnt++;
                l++;
                r--;
            }
            else{
                cnt++;
                r--;
            }
        }
        return cnt;
    }
};