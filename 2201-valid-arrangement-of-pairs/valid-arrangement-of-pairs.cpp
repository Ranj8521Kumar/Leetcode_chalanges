class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();

        vector<vector<int>> result;
        
        // logic to build the arrangement
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> inDegree, outDegree;

        // Build adjacency list and track in-degrees and out-degrees
        for (auto &vec : pairs) {
            adjList[vec[0]].push_back(vec[1]);
            outDegree[vec[0]]++;
            inDegree[vec[1]]++;
        }

        // Find the starting node for the arrangement
        int start = pairs[0][0];
        for (auto &p : outDegree) {
            if (p.second > inDegree[p.first]) {
                start = p.first;
                break;
            }
        }

        // Perform Eulerian path traversal
        vector<int> path;
        stack<int> stk;
        stk.push(start);

        while (!stk.empty()) {
            int node = stk.top();
            if (!adjList[node].empty()) {
                int next = adjList[node].back();
                adjList[node].pop_back();
                stk.push(next);
            } else {
                path.push_back(node);
                stk.pop();
            }
        }

        reverse(path.begin(), path.end());

        // Convert path into pairs
        for (int i = 0; i < path.size() - 1; i++) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }
};
