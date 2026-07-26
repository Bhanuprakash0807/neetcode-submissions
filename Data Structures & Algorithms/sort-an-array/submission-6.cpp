class Solution {
public:

int partition(vector<int>& nums,int l,int r){
    int ele=nums[r];
    int piv=l;
    for(int i=l;i<=r;i++){
        if(nums[i]<ele){
           swap(nums[i],nums[piv]);
           piv++; 
        }
    }
    swap(nums[piv],nums[r]);
    return piv;
}

  void quicksort(vector<int>& nums,int l,int r){
    if(l<r){
        int pivot=partition(nums,l,r);
        quicksort(nums,l,pivot-1);
        quicksort(nums,pivot+1,r);
    }
  }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        quicksort(nums,0,n-1);
        return nums;
    }
};