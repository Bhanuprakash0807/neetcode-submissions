class Solution {
public:

    void merge(vector<int>& arr,int l,int mid,int r){
        int lsz=mid-l+1;
        int rsz=r-mid;
        vector<int> left(lsz);
        vector<int> right(rsz);
        for(int i=l;i<=mid;i++){
            left[i-l]=arr[i];
        }
        for(int i=mid+1;i<=r;i++){
            right[i-mid-1]=arr[i];
        }
        int i=0;
        int j=0;
        int k=l;
        while(i<lsz && j<rsz){
            if(left[i]<=right[j]){
                arr[k++]=left[i];
                i++;
            }
            else{
                arr[k++]=right[j];
                j++;
            }
        }
        while(i<lsz) arr[k++]=left[i++];
        while(j<rsz) arr[k++]=right[j++];
    }

    void mergesort(vector<int>& nums,int l,int r){
        if(l<r){
            int mid=l+(r-l)/2;
            mergesort(nums,l,mid);
            mergesort(nums,mid+1,r);
            merge(nums,l,mid,r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};