class Solution {
public:
    long DFS(vector<vector<int>>& adj, int u, int parentNode, int k, vector<int>& values, int &componentsCount){
        long sum = 0;
        for(auto &v: adj[u]){
            if(v != parentNode){
                sum += DFS(adj, v, u, k, values, componentsCount);
            }
        }

        sum += values[u];
        if(sum % k == 0){
            componentsCount++;
            sum = 0;
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int v =  n;
        vector<vector<int>> adj(v);
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int componenetsCount = 0;
        DFS(adj, 0, -1, k, values, componenetsCount);

        return componenetsCount;
    }
};