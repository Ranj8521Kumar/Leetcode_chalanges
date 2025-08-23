class Solution {
public:
    vector<int> shiftKEleToLeft(vector<int> &arr, int k){
        int len = arr.size();
        k = k%len;

        vector<int> shiftedArray;
        for(int i = k; i<arr.size(); i++){
            shiftedArray.push_back(arr[i]);
        }

        for(int i = 0;  i < k; i++){
            shiftedArray.push_back(arr[i]);
        }

        return shiftedArray;
    }

    void reAssign(vector<int> &arr, vector<vector<int>> &grid,  int top, int buttom, int left, int right){
        top--;
        buttom++;
        left--;
        right++;
        int k = 0;

            //top row
            for(int j = left; j<=right; j++){
                grid[top][j] = arr[k++];
            }
            top++;

            //right col
            for(int i = top; i<=buttom; i++){
                grid[i][right] = arr[k++];
            }
            right--;

            //buttom row
            for(int j = right; j>=left; j--){
                grid[buttom][j] = arr[k++];
            }
            buttom--;

            //left col
            for(int i = buttom; i>=top; i--){
                grid[i][left] = arr[k++];
            }
            left++;

    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int top = 0;
        int buttom = m-1;
        int left = 0;
        int right = n-1;

        while(top < buttom && left < right){
            vector<int> currentLayer;
            //top row
            for(int j = left; j<=right; j++){
                currentLayer.push_back(grid[top][j]);
            }
            top++;

            //right col
            for(int i = top; i<=buttom; i++){
                currentLayer.push_back(grid[i][right]);
            }
            right--;

            //buttom row
            for(int j = right; j>=left; j--){
                currentLayer.push_back(grid[buttom][j]);
            }
            buttom--;

            //left col
            for(int i = buttom; i>=top; i--){
                currentLayer.push_back(grid[i][left]);
            }
            left++;

            vector<int> shiftedArray = shiftKEleToLeft(currentLayer, k);
            reAssign(shiftedArray,  grid, top, buttom, left, right);
        }

        return grid;

    }
};