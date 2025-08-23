class Solution {
public:
    // Function  to find minimun Area of a matrix containing all one's
    int minArea(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd){
        int m = grid.size();
        int n = grid[0].size();

        int maxColumn = -1;
        int minColumn = n;
        int maxRow = -1;
        int minRow = m;
        bool NotfoundOne = true;

        for(int i = rowStart; i<rowEnd; i++){
            for(int j = colStart; j<colEnd; j++){
                if(grid[i][j] == 1){
                    NotfoundOne = false;
                    maxColumn = max(maxColumn, j);
                    minColumn = min(minColumn, j);

                    maxRow = max(maxRow, i);
                    minRow = min(minRow, i);
                }
            }
        }

        if(NotfoundOne) return 0;

        return ((maxColumn - minColumn + 1)*(maxRow - minRow + 1));
    }

    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = INT_MAX;

        // 3 - Non-Overlapping rectangle -> 2 spilit lines
        // 6 cases

        // first case:
        for(int rowSpilit = 1; rowSpilit < m; rowSpilit++){
            for(int colSpilit = 1; colSpilit < n; colSpilit++){
                int topLeft = minArea(grid, 0, rowSpilit, 0, colSpilit);
                int topRight = minArea(grid, 0, rowSpilit, colSpilit, n);
                int down = minArea(grid, rowSpilit, m, 0, n);

                result = min(result, (topLeft + topRight + down));
            }
        }

        // Fourth Case:
        for(int rowSpilit = 1; rowSpilit < m; rowSpilit++){
            for(int colSpilit = 1; colSpilit < n; colSpilit++){
                int buttomLeft = minArea(grid, rowSpilit, m, 0, colSpilit);
                int buttomRight = minArea(grid, rowSpilit, m, colSpilit, n);
                int top = minArea(grid, 0, rowSpilit, 0, n);

                result = min(result, (buttomLeft + buttomRight + top));
            }
        }

        // Second Case:
        for(int rowSpilit1 = 1; rowSpilit1 < m; rowSpilit1++){
            for(int rowSpilit2 = rowSpilit1 + 1; rowSpilit2 < m; rowSpilit2++){
                int top = minArea(grid, 0, rowSpilit1, 0, n);
                int middle = minArea(grid, rowSpilit1, rowSpilit2, 0, n);
                int down = minArea(grid, rowSpilit2, m, 0, n);

                result = min(result, (top + middle + down));
            }
        }

        // Third Case:
        for(int colSpilit1 = 1; colSpilit1 < n; colSpilit1++){
            for(int colSpilit2 = colSpilit1 + 1; colSpilit2 < n; colSpilit2++){
                int left = minArea(grid, 0, m, 0, colSpilit1);
                int middle = minArea(grid, 0, m, colSpilit1, colSpilit2);
                int right = minArea(grid, 0, m, colSpilit2, n);

                result = min(result, (left + middle + right));
            }
        }

        // Case Five:
        for(int rowSpilit = 1; rowSpilit < m; rowSpilit++){
            for(int colSpilit = 1; colSpilit < n; colSpilit++){
                int left = minArea(grid, 0, m, 0, colSpilit);
                int rightTop = minArea(grid, 0, rowSpilit, colSpilit, n);
                int rightDown = minArea(grid, rowSpilit, m, colSpilit, n);

                result = min(result, (left + rightTop + rightDown));
            }
        }

        // Case Six:
        for(int rowSpilit = 1; rowSpilit < m; rowSpilit++){
            for(int colSpilit = 1; colSpilit < n; colSpilit++){
                int leftTop = minArea(grid, 0, rowSpilit, 0, colSpilit);
                int leftDown = minArea(grid, rowSpilit, m, 0, colSpilit);
                int right = minArea(grid, 0, m, colSpilit, n);

                result = min(result, (leftTop + leftDown + right));
            }
        }

        return result;
    }
};