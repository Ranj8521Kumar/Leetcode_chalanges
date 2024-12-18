class Solution {
public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;

        for(auto &v: adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();

        vector<vector<int>> adj(v+1);

        for(int i =  0; i<v; i++){
            for(int j =  0; j<v; j++){
                int u = isConnected[i][j];
                if(u == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<bool> visited(v+1, 0);

        int count = 0;
        for(int u = 1; u<=v; u++){
            if(!visited[u]){
                DFS(adj, u, visited);
                count++;
            }
        }

        return count;
    }
};