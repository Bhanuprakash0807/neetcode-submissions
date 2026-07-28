class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0;
        int cnt10=0;
        for(int bill:bills){
            int num=bill;
            bill=bill-5;
            int req10=bill/10;
            if(req10!=0 && req10<=cnt10){
                bill-=(10)*req10;
                cnt10-=req10;
            }
            int req5=bill/5;
            if(req5!=0 && req5<=cnt5){
                bill-=5*req5;
                cnt5-=req5;
            }
            if(bill!=0){
                return false;
            }
            if(num==10){
                cnt10++;
            }
            if(num==5){
                cnt5++;
            }
        }
        return true;
    }
};