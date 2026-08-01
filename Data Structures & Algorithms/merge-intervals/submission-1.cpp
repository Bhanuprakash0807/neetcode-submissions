class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[intervals[i][0]]++;
            mpp[intervals[i][1]]--;
        }
        int numberActive=0;
        vector<int> interval;
        vector<vector<int>> result;
        for(auto& [key,val]:mpp){
            if(interval.empty()){
                interval.push_back(key);
            }
            numberActive+=val;
            if(numberActive==0){
                interval.push_back(key);
                result.push_back(interval);
                interval.clear();
            }
        }
        return result;
    }
};
