class Solution {
public:
    long DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& values, int k, int& count){
        visited[u] =  true;
        long sum = 0;

        for(auto &v: adj[u]){
            if(!visited[v]){
                sum += DFS(adj, v, visited, values, k, count);
                visited[v] = true;
            }
        }

        sum += values[u];

        if(sum % k == 0){
            count++;
            sum = 0;
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for(int u = 0; u<n; u++){
            if(!visited[u]){
                DFS(adj, u, visited, values, k, count);
            }
        }

        return count;
    }
};