class Solution {
public:
    int m, n;
    bool isSafe(int x, int y){
        if(x < m && x >= 0 && y < n && y >= 0){
            return true;
        }

        return false;
    }

    void traverse(int &dir, int i, int j, vector<int> &result, vector<vector<int>> &mat){
        queue<pair<int, int>> que;

        que.push({i, j});
        vector<int> temp;

        while(!que.empty()){
            auto it = que.front(); que.pop();
            int x = it.first;
            int y = it.second;

            temp.push_back(mat[x][y]);
            int newX = x + (1);
            int newY = y + (-1);

            if(isSafe(newX, newY)){
                que.push({newX, newY});
            } 
        }

        if(dir == 0){
            reverse(temp.begin(), temp.end());
            result.insert(result.end(), temp.begin(), temp.end());
            }else{
                result.insert(result.end(), temp.begin(), temp.end());
            }

        dir = 1 - dir;

}

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<int> result;

        int dir = 0; //up and 1 => down

        for(int j = 0; j<n; j++){
            traverse(dir, 0, j, result, mat);
        }

        for(int i = 1; i<m; i++){
            traverse(dir, i, (n-1), result, mat);
        }

        return result;

    }
};