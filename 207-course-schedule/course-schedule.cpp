class Solution {
public:
    bool DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recVisited){
        visited[u] = true;
        recVisited[u] = true;

        for(auto &v: adj[u]){
            if(visited[v] && recVisited[v]){
                return true;
            }else{
                if(!visited[v]){
                    if(DFS(adj, v, visited, recVisited)){
                        return true;
                    }
                }
            }
        }

        recVisited[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        int n = prerequisites.size();

        vector<bool> visited(v, false);
        vector<bool> recVisited(v, false);

        //Making Adjancy List
        vector<vector<int>> adj(v, vector<int> ());

        for(auto &vec: prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
        }

        for(int u = 0; u<v; u++){
            if(!visited[u]){
                if(DFS(adj, u, visited, recVisited)){
                    return false;//for cycle detected then return false
                }
            }
        }

        return true;//cycle is not detected

    }
};