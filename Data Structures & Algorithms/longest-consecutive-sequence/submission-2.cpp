class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st;
       for(int i=0;i<nums.size();i++){
             st.insert(nums[i]);
       }
       int res=0;
        for(int num:nums){
            if(st.find(num-1)==st.end()){
                int len=0;
                while(st.find(num+len)!=st.end()){
                    len++;
                }
                res=max(res,len);
            }
        }
        return res;
    }
};
