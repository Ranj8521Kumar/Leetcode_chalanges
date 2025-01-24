class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> outDegree(v, 0);
        vector<vector<int>> reverseGraph(v);

        // Build the reverse graph and calculate the out-degree of each node
        for (int i = 0; i < v; i++) {
            for (auto &u : graph[i]) {
                reverseGraph[u].push_back(i);
                outDegree[i]++;
            }
        }

        // Start with nodes that have out-degree 0
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (outDegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the graph using a queue
        vector<int> safeNodes(v, 0); // 0 = unsafe, 1 = safe
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes[node] = 1;

            for (auto &neighbor : reverseGraph[node]) {
                outDegree[neighbor]--;
                if (outDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Collect all safe nodes
        vector<int> result;
        for (int i = 0; i < v; i++) {
            if (safeNodes[i] == 1) {
                result.push_back(i);
            }
        }

        return result;
    }
};
