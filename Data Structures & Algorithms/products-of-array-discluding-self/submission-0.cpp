class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
           if(i>0) left[i]=left[i-1]*nums[i-1];
            if(n-i-1<n-1) right[n-i-1]=right[n-i-1+1]*nums[n-i-1+1];
        }
        for(int i=0;i<n;i++){
            res[i]=left[i]*right[i];
        }
        return res;
    }
};
