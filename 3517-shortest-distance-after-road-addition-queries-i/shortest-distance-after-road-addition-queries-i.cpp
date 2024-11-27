
class Solution {
    void createAdjList(vector<vector<int>>& adj, int n) {
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
    }

    void DFS(int src, vector<int>& topo, vector<int>& vis, const vector<vector<int>>& adj) {
        vis[src] = 1;
        for (int node : adj[src]) { 
            if (!vis[node]) DFS(node, topo, vis, adj);
        }
        topo.push_back(src); 
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n); 
        createAdjList(adj, n); 
        vector<int> ans;
        for (auto& edge : queries) { 
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); 

            vector<int> topo;
            vector<int> vis(n, 0);
            for (int i = 0; i < n; ++i) {
                if (!vis[i]) DFS(i, topo, vis, adj); 
            }
            reverse(topo.begin(), topo.end()); 

            vector<int> dist(n, 1e9);
            dist[0] = 0; 

            for (int node : topo) {
                if (dist[node] != 1e9) { 
                    for (int neighbor : adj[node]) { 
                        if (dist[neighbor] > dist[node] + 1) {
                            dist[neighbor] = dist[node] + 1;
                        }
                    }
                }
            }

            ans.push_back(dist[n - 1]); 
        }
        return ans; 
    }
};