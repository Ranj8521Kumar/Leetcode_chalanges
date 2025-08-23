class Solution {
public:
    int minArea(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd) {
        int maxColumn = -1, minColumn = colEnd;
        int maxRow = -1, minRow = rowEnd;

        for (int i = rowStart; i <= rowEnd; i++) {
            for (int j = colStart; j <= colEnd; j++) {
                if (grid[i][j] == 1) {
                    maxColumn = max(maxColumn, j);
                    minColumn = min(minColumn, j);
                    maxRow = max(maxRow, i);
                    minRow = min(minRow, i);
                }
            }
        }

        if (maxRow == -1) return 0; // no 1’s in this submatrix
        return (maxColumn - minColumn + 1) * (maxRow - minRow + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = INT_MAX;

        // Case 1: top-left, top-right, bottom
        for (int rowSplit = 1; rowSplit < m; rowSplit++) {
            for (int colSplit = 1; colSplit < n; colSplit++) {
                int topLeft = minArea(grid, 0, rowSplit - 1, 0, colSplit - 1);
                int topRight = minArea(grid, 0, rowSplit - 1, colSplit, n - 1);
                int down = minArea(grid, rowSplit, m - 1, 0, n - 1);
                result = min(result, topLeft + topRight + down);
            }
        }

        // Case 2: three horizontal strips
        for (int rowSplit1 = 1; rowSplit1 < m; rowSplit1++) {
            for (int rowSplit2 = rowSplit1 + 1; rowSplit2 < m; rowSplit2++) {
                int top = minArea(grid, 0, rowSplit1 - 1, 0, n - 1);
                int middle = minArea(grid, rowSplit1, rowSplit2 - 1, 0, n - 1);
                int down = minArea(grid, rowSplit2, m - 1, 0, n - 1);
                result = min(result, top + middle + down);
            }
        }

        // Case 3: three vertical strips
        for (int colSplit1 = 1; colSplit1 < n; colSplit1++) {
            for (int colSplit2 = colSplit1 + 1; colSplit2 < n; colSplit2++) {
                int left = minArea(grid, 0, m - 1, 0, colSplit1 - 1);
                int middle = minArea(grid, 0, m - 1, colSplit1, colSplit2 - 1);
                int right = minArea(grid, 0, m - 1, colSplit2, n - 1);
                result = min(result, left + middle + right);
            }
        }

        // Case 4: bottom-left, bottom-right, top
        for (int rowSplit = 1; rowSplit < m; rowSplit++) {
            for (int colSplit = 1; colSplit < n; colSplit++) {
                int bottomLeft = minArea(grid, rowSplit, m - 1, 0, colSplit - 1);
                int bottomRight = minArea(grid, rowSplit, m - 1, colSplit, n - 1);
                int top = minArea(grid, 0, rowSplit - 1, 0, n - 1);
                result = min(result, bottomLeft + bottomRight + top);
            }
        }

        // Case 5: left, right-top, right-bottom
        for (int rowSplit = 1; rowSplit < m; rowSplit++) {
            for (int colSplit = 1; colSplit < n; colSplit++) {
                int left = minArea(grid, 0, m - 1, 0, colSplit - 1);
                int rightTop = minArea(grid, 0, rowSplit - 1, colSplit, n - 1);
                int rightDown = minArea(grid, rowSplit, m - 1, colSplit, n - 1);
                result = min(result, left + rightTop + rightDown);
            }
        }

        // Case 6: left-top, left-bottom, right
        for (int rowSplit = 1; rowSplit < m; rowSplit++) {
            for (int colSplit = 1; colSplit < n; colSplit++) {
                int leftTop = minArea(grid, 0, rowSplit - 1, 0, colSplit - 1);
                int leftDown = minArea(grid, rowSplit, m - 1, 0, colSplit - 1);
                int right = minArea(grid, 0, m - 1, colSplit, n - 1);
                result = min(result, leftTop + leftDown + right);
            }
        }

        return result;
    }
};
