class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        
        // Calculate indegree for each node
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            indegree[v]++;
        }
        
        // Find nodes with indegree 0
        int champion = -1; // Store potential champion
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                if (champion != -1) {
                    // More than one node has indegree 0, no unique champion
                    return -1;
                }
                champion = i;
            }
        }
        
        // Check if a unique champion exists
        return champion;
    }
};
