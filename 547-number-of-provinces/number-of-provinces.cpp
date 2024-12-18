class Solution {
public:
    int v;

    void DFS(vector<vector<int>>& isConnected, int u, vector<bool>& visited){
        visited[u] = true;

        for(int j = 0; j<v; j++){
            if(!visited[j] && isConnected[u][j] == 1){
                DFS(isConnected, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        v = isConnected.size();

        vector<bool> visited(v, 0);

        int count = 0;
        for(int u = 0; u<v; u++){
            if(!visited[u]){
                DFS(isConnected, u, visited);
                count++;
            }
        }

        return count;
    }
};