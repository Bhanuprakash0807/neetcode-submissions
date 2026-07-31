class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n=intervals.size();
	sort(intervals.begin(),intervals.end());
	int index=0;
    vector<vector<int>> result;	
    while(index<n){
            int newstart=intervals[index][0];
            int newend=intervals[index][1];
            index++;
            while(index<n){
                int StartofCurInterval=intervals[index][0];
                int EndofCurInterval=intervals[index][1];
                if(newend<StartofCurInterval){
                    break;
                }
                newstart=min(newstart,StartofCurInterval);
                newend=max(newend,EndofCurInterval);
                index++;
            }
            result.push_back({newstart,newend});
        }
	return result;
   
    }
};
