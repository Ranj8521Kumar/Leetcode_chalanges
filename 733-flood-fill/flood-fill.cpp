class Solution {
public:
    void dfs(int row, int col,  vector<vector<int>>& ans, int color, vector<vector<int>> &image, int initColor,
    const int drow[],   const int dcol[]){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i<4; i++){
            int  nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && ncol<m && nrow<n && ncol>=0 && image[nrow][ncol] == initColor && 
            ans[nrow][ncol] != color){
                dfs(nrow, ncol, ans, color, image, initColor, drow, dcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        dfs(sr, sc, ans, color, image, initColor, drow, dcol);

        return ans;
    }
};