class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(true){
            int pivotindex=partition(nums,left,right);
            if(pivotindex==k-1){
                return nums[k-1];
            }
            else if(pivotindex<k-1){
                left=pivotindex+1;
            }
            else{
                right=pivotindex-1;
            }
        }
        return -1;
    }
private:
    int partition(vector<int>& nums,int left,int right){
        int pivot=nums[right];
        int p=left;
        for(int i=left;i<=right;i++){
            if(nums[i]>pivot){
                swap(nums[p],nums[i]);
                p++;
            }
        }
        swap(nums[p],nums[right]);
        return p;
    }
};
