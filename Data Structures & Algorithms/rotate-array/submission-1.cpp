class Solution {
public:

    void rever(vector<int>& nums,int l,int r){
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>=n){
            k=k%n;
        }
     rever(nums,0,n-1);
     rever(nums,0,k-1);
     rever(nums,k,n-1);
    }
};