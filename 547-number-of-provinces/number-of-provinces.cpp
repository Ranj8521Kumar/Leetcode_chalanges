class Solution {
public:
    void DFS(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u){
        visited[u] = true;

        for(auto &v: adj[u]){
            if(!visited[v]){
                DFS(adj, visited, v);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        unordered_map<int, vector<int>> adj;

        for(int i  = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(isConnected[i][j] == 1 && (i != j)){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(v, false);
        int count = 0;

        for(int u = 0; u<v; u++){
            if(!visited[u]){
                count++;
                DFS(adj, visited, u);
            }
        }

        return count;
    }
};