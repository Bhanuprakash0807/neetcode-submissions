class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int ind=0;
        int i=0;
        int j=0;
        int ind1=(m+n)/2-1;
        int ind2=(m+n)/2;
        int median1=-1;
        int median2=-1;
        while(i<m && j<n){
            if(median2!=-1){
                break;
            }
            if(nums1[i]<=nums2[j]){
                if(ind==ind1){
                    median1=nums1[i];
                }
                if(ind==ind2){
                    median2=nums1[i];
                }
                i++;
                ind++;
            }
            else{
                  if(ind==ind1){
                    median1=nums2[j];
                }
                if(ind==ind2){
                    median2=nums2[j];
                }
                j++;
                ind++;
            }
        }
        while(i<m){
            if(median2!=-1){
                break;
            }
             if(ind==ind1){
                    median1=nums1[i];
                }
                if(ind==ind2){
                    median2=nums1[i];
                }
                i++;
                ind++;
        }
        while(j<n){
            if(median2!=-1){
                break;
            }
               if(ind==ind1){
                    median1=nums2[j];
                }
                if(ind==ind2){
                    median2=nums2[j];
                }
                j++;
                ind++;
        }
        if((m+n)%2==0){
            return (median1+median2)/2.0;
        }
        return median2;
    }
};
