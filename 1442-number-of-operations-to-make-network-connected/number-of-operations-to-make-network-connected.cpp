class Solution {
public:
    void BFS(vector<vector<int>>& adj, int u, vector<bool>& visited){
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(auto &v: adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int v = n;
        int edges = connections.size();

        if(edges < v-1) return -1;

        vector<vector<int>> adj(v, vector<int> ());

        int components = 0;

        for(auto &edge: connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(v, false);

        for(int u = 0; u<v; u++){
            if(!visited[u]){
                components++;
                BFS(adj, u, visited);
            }
        }

        return components - 1;
    }
};