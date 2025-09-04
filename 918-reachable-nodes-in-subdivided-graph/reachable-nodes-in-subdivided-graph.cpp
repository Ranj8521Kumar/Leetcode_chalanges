class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // Build weighted graph (adj list)
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Max heap on remaining moves
        priority_queue<pair<int,int>> pq; // {remainingMoves, node}
        pq.push({maxMoves, 0});

        vector<bool> visited(n, false);
        int ans = 0;

        while (!pq.empty()) {
            auto [maxRemainingMoves, u] = pq.top();
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;
            ans++;

            // Traverse neighbors
            for (auto &p : adj[u]) {
                int v = p.first;
                int &w = p.second; // reference to update weight directly

                if (!visited[v] && maxRemainingMoves >= w + 1) {
                    pq.push({maxRemainingMoves - w - 1, v});
                }

                int moveCost = min(maxRemainingMoves, w);
                w -= moveCost; // update u->v
                for (auto &q : adj[v]) {
                    if (q.first == u) {
                        q.second -= moveCost; // update v->u
                        break;
                    }
                }
                ans += moveCost;
            }
        }

        return ans;
    }
};
