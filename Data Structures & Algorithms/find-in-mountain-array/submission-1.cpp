/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();
        int i=0;
        int j=len-1;
        int res=-1;
        int val=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int valatmid=mountainArr.get(mid);
            int valatleft=INT_MIN;
            if(mid>0){
                valatleft=mountainArr.get(mid-1);
            }
            if(valatleft<valatmid){
                res=mid;
                val=valatmid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        if(val==target){
            return res;
        }
        
            int l1=res+1;
            int r1=len-1;
            int ans1=-1;
            while(l1<=r1){
                int mid=l1+(r1-l1)/2;
                int vam=mountainArr.get(mid);
                if(vam==target){
                    ans1=mid;
                    break;
                }
                else if(vam<target){
                    r1=mid-1;
                }
                else{
                    l1=mid+1;
                }
            }
            int l2=0;
            int r2=res-1;
            int ans2=-1;
            while(l2<=r2){
                int mid=l2+(r2-l2)/2;
                int vam=mountainArr.get(mid);
                if(vam==target){
                    ans2=mid;
                    break;
                }
                else if(vam<target){
                    l2=mid+1;
                }
                else{
                    r2=mid-1;
                }
            }
            
            if(ans2!=-1){
                return ans2;
            }
            else if(ans1!=-1){
                return ans1;
            }
            return -1;
    }
};