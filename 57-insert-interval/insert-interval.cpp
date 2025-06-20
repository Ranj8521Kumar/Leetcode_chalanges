class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i;

        for(i = 0; i<n; i++){
            auto interval = intervals[i];

            int start = interval[0];
            if(start > newInterval[0]){
                break;
            }
        }

        vector<vector<int>> temp;
        temp.insert(temp.end(), intervals.begin(), intervals.begin() + i);
        temp.push_back(newInterval);
        temp.insert(temp.end(), intervals.begin() + i, intervals.end());

        intervals.clear();

        int k = 0;
        int m = temp.size();
        for(int j = 0; j<m - 1; j++){
            int end = temp[j][1];
            int start = temp[j+1][0];

            if(end < start){
                intervals.push_back({temp[k][0], temp[j][1]});
                k = j + 1;
            }else{
                temp[j+1][1] = max(temp[j][1], temp[j+1][1]);
            }
        }

        intervals.push_back({temp[k][0], temp[m-1][1]});


        return intervals;
    }
};