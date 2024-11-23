class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> result(n, vector<char>(m, '.'));

        // Simulate gravity for each row
        for (auto &row : box) {
            int emptyPos = n - 1; // Start at the last position in the row
            for (int i = n - 1; i >= 0; i--) {
                if (row[i] == '*') {
                    // Obstacle encountered, reset emptyPos
                    emptyPos = i - 1;
                } else if (row[i] == '#') {
                    // Move stone to the nearest empty position
                    swap(row[i], row[emptyPos]);
                    emptyPos--;
                }
            }
        }

        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = box[i][j];
            }
        }

        return result;
    }
};
