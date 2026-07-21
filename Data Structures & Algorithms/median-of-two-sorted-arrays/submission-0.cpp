class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int m=n1;
        int n=n2;
        int left=(m+n)/2;
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0;
        int r=n1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int l1=mid-1;
            int l2=left-mid-1;
            int r1=mid;
            int r2=l2+1;
            if(l1<0){
                l1=INT_MIN; 
            }
            else{
                l1=nums1[l1];
            }
            if(l2<0){
                l2=INT_MIN;
            }
            else{
                l2=nums2[l2];
            }
            if(r1>=n1){
                r1=INT_MAX;
            }
            else{
                r1=nums1[r1];
            }
            if(r2>=n2){
                r2=INT_MAX;
            }
            else{
                r2=nums2[r2];
            }
            if(l1<=r2 && l2<=r1){
                if((m+n)%2==1){
                    return min(r1,r2);
                }
                else{
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1<=r2){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};
