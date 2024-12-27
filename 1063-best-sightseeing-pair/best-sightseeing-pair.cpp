class Solution {
public:
//Optimal Approach
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> maxScoreTill(n);
        maxScoreTill[0] = values[0];
        int temp = maxScoreTill[0];

        for(int i = 1; i<n; i++){
            int value = values[i] + i;
            temp = max(temp, value);
            maxScoreTill[i] = temp;
        }

        int maxScore = maxScoreTill[0];

        for(int j = 1; j<n; j++){
            int value = values[j] - j;
            maxScore = max(maxScore, value + maxScoreTill[j-1]);
        }

        return maxScore;
    }
};