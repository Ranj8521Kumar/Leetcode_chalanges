class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        function<long long(int)> dfs = [&](int node) {
            visited[node] = true;
            long long sum = values[node];

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    sum += dfs(neighbor);
                }
            }

            if (sum % k == 0) {
                ++count;
                return 0LL;
            }

            return sum;
        };

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        return count;
    }
};