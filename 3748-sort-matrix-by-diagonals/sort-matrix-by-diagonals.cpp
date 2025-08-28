class Solution {
public:
    int m, n;
    void sortDiagonal(int r, int c, vector<vector<int>> &grid, bool asc){
        int i = r;
        int j = c;

        vector<int> temp;

        // There is one noted point is that idf I stay on a element and If I want to move in diagonal then increase x and y both by one at same time

        while(i<m && j < n){
            temp.push_back(grid[i++][j++]);
        }

        if(!asc){
            sort(temp.begin(), temp.end(), greater<int>());
        }else{
            sort(temp.begin(), temp.end());
        }

        i = r;
        j = c;
        int k = 0;

        while(i<m && j<n){
            grid[i++][j++] = temp[k++];
        }
    };

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // Let's try out [i - j] approach:
        // int m = grid.size();
        // int n = grid[0].size();
        // unordered_map<int, vector<int>> mpp;

        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         mpp[(i - j)].push_back(grid[i][j]);
        //     }
        // }

        // for(auto &it: mpp){
        //     auto &vec = it.second;
        //     if(it.first < 0){
        //         sort(vec.rbegin(), vec.rend());
        //     }else{
        //         sort(vec.begin(), vec.end());
        //     }
        // }

        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         grid[i][j] = mpp[(i-j)].back();
        //          mpp[(i-j)].pop_back();
        //     }
        // }

        // return grid;




        // Lets try a different approach for resucing the space complexity(without taking the unordered_map):
        m = grid.size();
        n = grid[0].size();

        // For Buttom-Left Diagonal:
        for(int r = 0; r<m; r++){
            sortDiagonal(r, 0, grid, false); // false is used for tracking the descending order and true for the ascending order
        }

        //  For Upper-Right Diagonal:
        for(int c = 1; c<n; c++){
            sortDiagonal(0, c, grid, true);
        }

        return grid;
    }
};