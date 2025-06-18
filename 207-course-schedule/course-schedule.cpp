class Solution {
public:
    bool DFSForCycle(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recVisited){
        visited[u] = true;
        recVisited[u] = true;

        for(auto &v: adj[u]){
            if(visited[v] && recVisited[v]){
                return true;
            }

            if(!visited[v]){
                if(DFSForCycle(adj, v, visited, recVisited)){
                    return true;
                }
            }
        }

        recVisited[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;

        vector<vector<int>> adj(v, vector<int> ());
        for(auto &vec: prerequisites){
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }
        
        vector<bool> visited(v, false);
        vector<bool> recVisited(v, false);

        for(int u = 0; u<v; u++){
            if(!visited[u]){
                if(DFSForCycle(adj, u, visited, recVisited)){
                    return false;
                }
            }
        }

        return true;
    }
};