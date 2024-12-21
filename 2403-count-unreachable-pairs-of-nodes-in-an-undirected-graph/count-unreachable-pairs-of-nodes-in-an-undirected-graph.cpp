class Solution {
public:
    void BFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& nodeCount){
        queue<int> que;
        que.push(u);
        visited[u] = true;

        int count = 0;

        while(!que.empty()){
            int u = que.front();
            count++;
            que.pop();

            for(auto &v: adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }

        nodeCount.push_back(count);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        int v = n;
        vector<vector<int>> adj(v, vector<int> ());

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(v, false);
        vector<int> nodeCount;

        for(int u = 0; u<v; u++){
            if(!visited[u]){
                BFS(adj, u, visited, nodeCount);
            }
        }

        long long result = 0;
        long long nodeSum = 0;

        for(auto &count: nodeCount){
            result += count*nodeSum;
            nodeSum += count;
        }

        return result;
    }
};