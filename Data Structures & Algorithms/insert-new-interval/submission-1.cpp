class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(newInterval.empty()){
            return intervals;
        }
	vector<vector<int>> result;
        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }
        int noOfIntervals=intervals.size();
	int startOfnewInterval=newInterval[0];
	int endOfnewInterval=newInterval[1];
	int index=0;
	while(index<noOfIntervals){
		int startOfCurrentInterval=intervals[index][0];
		int endOfCurrentInterval=intervals[index][1];
		if(endOfCurrentInterval<startOfnewInterval){
			result.push_back(intervals[index]);
			index++;
		}
		else{
			startOfnewInterval=min(startOfCurrentInterval,startOfnewInterval);
			break;
        }	
	}
	while(index<noOfIntervals){
		int startOfCurrentInterval=intervals[index][0];
		int endOfCurrentInterval=intervals[index][1];
		if(endOfnewInterval<startOfCurrentInterval){
			break;
        }
        else{
            endOfnewInterval=max(endOfnewInterval,endOfCurrentInterval);  
            index++;
        }
	}
            result.push_back({startOfnewInterval,endOfnewInterval});
	while(index<noOfIntervals){
		result.push_back(intervals[index]);
        index++;
	}
        return result;
    }
};
