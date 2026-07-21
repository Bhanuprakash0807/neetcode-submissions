class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n=arr.size();
        vector<int> nums=arr;
        int cind=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
           if(abs(nums[i]-x)<mini){
            mini=min(abs(nums[i]-x),mini);
            cind=i;
           }    
        }
        int l=cind;
        int r=cind;
        while((r-l+1)<k){
            if(l>0 && r<n-1){
                int a=nums[l-1];
                int b=nums[r+1];
                int a1=abs(a-x);
                int b1=abs(b-x);
                if(a1<=b1){
                    l--;
                }
                else{
                    r++;
                }
            }
            else if(l>0){
                l--;
            }
            else{
                r++;
            }
        }
        for(int i=l;i<=r;i++){
            res.push_back(nums[i]);
        }
        return res;
    }
};