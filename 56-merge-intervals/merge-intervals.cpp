class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        //sort by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        int k = 0;
        for(int i = 0; i<n-1; i++){
            int end = intervals[i][1];
            int start = intervals[i+1][0];

            if(end < start){
                result.push_back({intervals[k][0], intervals[i][1]});
                k  = i + 1;
            }else{
                intervals[i+1][0] = min(intervals[i][0], intervals[i+1][0]);
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
        }

        result.push_back({intervals[k][0], intervals[n-1][1]});

        return result;
    }
};