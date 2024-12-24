class Solution {
public:
    pair<int, int> DFS(vector<vector<int>>& adj, int u, int parent) {
        int maxDist = 0;
        int farthestNode = u;

        for (auto &v : adj[u]) {
            if (v != parent) {
                auto temp = DFS(adj, v, u);
                if (temp.first + 1 > maxDist) {
                    maxDist = temp.first + 1;
                    farthestNode = temp.second;
                }
            }
        }

        return {maxDist, farthestNode};
    }

    int treeDiameter(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto temp1 = DFS(adj, 0, -1); // Get farthest node from 0
        auto temp2 = DFS(adj, temp1.second, -1); // Get farthest node from temp1
        return temp2.first; // Diameter of the tree
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1; // Nodes in tree 1
        int m = edges2.size() + 1; // Nodes in tree 2

        int diameter1 = treeDiameter(edges1, n);
        int diameter2 = treeDiameter(edges2, m);

        // Merging increases the diameter minimally by connecting the trees
        int half1 = (diameter1 + 1) / 2; // Half of tree 1's diameter
        int half2 = (diameter2 + 1) / 2; // Half of tree 2's diameter

        return max({diameter1, diameter2, half1 + half2 + 1});
    }
};
