class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int curr=INT_MAX;
        for(int p:prices){
            if(p<curr){
                // profit-=p;
                curr=p;
            }
            else if(curr<p){
                profit+=(p-curr);
                curr=p;
            }
        }
        return profit;
    }
};