class Solution {
public:
//Optimal Approach
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxScore = INT_MIN;

        int maxScoreTill = values[0];//store the maximum value till of valuse[i] + i till ith index
        for(int i = 1; i<n; i++){
            maxScoreTill = max(maxScoreTill, values[i-1] + (i-1));
            int value = values[i] - i;
            
            maxScore = max(maxScore, maxScoreTill + value);
        }

        return maxScore;
    }
};