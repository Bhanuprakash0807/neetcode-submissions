class Solution {
public:

    vector<int> temp;
    void ksum(int k,int start,vector<int>& nums,long long int target,vector<vector<int>>& res){
        if(k==2){
            int l=start;
            int r=nums.size()-1;
            while(l<r){
                long long int sum=(long long int)nums[l]+nums[r];
                if(sum==target){
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                    while(l<r && nums[r]==nums[r+1]){
                        r--;
                    }
                }
                else if(sum>target){
                    r--;
                }
                else{
                    l++;
                }
            }
            return;
        }
        for(int i=start;i<nums.size()-1;i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            ksum(k-1,i+1,nums,target-nums[i],res);
            temp.pop_back();
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    int k=4;
    ksum(k,0,nums,(long long int)target,res);
     return res;
    }
};