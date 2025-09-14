class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // Apply Mathematics:
        int n = grid.size();
        n *= n;
        int gridSum = 0;
        long long gridSquareSum = 0;
        for(auto &row: grid){
            for(auto &it: row){
                gridSum += it;
                gridSquareSum += (it*it);
            }
        }

        int totalSum = (n*(n + 1)) / 2;
        long long totalSquareSum = (int)((1LL*n*(n + 1)*(2*n + 1)) / 6);

        int x = totalSum - gridSum; // a-b
        int y = totalSquareSum - gridSquareSum; // a^2 - b^2

        int a = (x + (y/x))/2;
        int b = a - x;

        return {b, a};

    }
};