class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int n=prices.size();
        int r=1;
        int maxprofit=0;
        int minun=prices[0];
        while(r<n){
            if(prices[r]<minun){
                minun=prices[r];
                l=r;
            }
            maxprofit=max(maxprofit,prices[r]-minun);
            r++;
        }
        return maxprofit;
    }
};
