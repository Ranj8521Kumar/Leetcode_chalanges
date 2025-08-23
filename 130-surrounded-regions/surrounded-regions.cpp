class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n  = board[0].size();

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<pair<int, int>> que;

        // mark all boubarys cell containing 'O'
        for(int i = 0; i<m;  i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(board[i][j] == 'O'){
                        que.push({i,  j});
                        board[i][j] = '#'; //safe
                    }
                }
            }
        }

        // BFS to mark all 'O's connected to boundary
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;

            que.pop();

            for(auto &dir: directions){
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && board[newX][newY] == 'O'){
                    que.push({newX, newY});
                    board[newX][newY] = '#'; 
                }
            }
        }

        // Mark all rest 'O' to 'X' and convert '#' to 'O'
        for(int i = 0; i<m;  i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};