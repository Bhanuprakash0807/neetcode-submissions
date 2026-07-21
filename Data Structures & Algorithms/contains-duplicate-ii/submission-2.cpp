class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_set<int> st;
       int l=0;
       int r=0;
        int n=nums.size();
       while(r<n){
        if(r-l>k){
            st.erase(nums[l]);
            l++;
        }
        if(st.find(nums[r])!=st.end()){
            return true;
        }
        st.insert(nums[r]);
        r++;
       }
       return false;
    }
};