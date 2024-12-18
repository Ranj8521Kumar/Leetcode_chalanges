class Solution {
public:
    bool DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recVisited, stack<int>& st){
        visited[u] = true;
        recVisited[u] = true;

        for(auto &v: adj[u]){
            if(visited[v] && recVisited[v]){
                return true;
            }else{
                if(!visited[v]){
                    if(DFS(adj, v, visited, recVisited, st)){
                        return true;
                    }
                }
            }
        }
        st.push(u);
        recVisited[u] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //using dfs
        int v = numCourses;
        int n = prerequisites.size();

        vector<int> result;

        vector<bool> visited(v, false);
        vector<bool> recVisited(v, false);

        vector<vector<int>> adj(v, vector<int> ());

        for(auto &vec: prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
        }

        stack<int> st;
        for(int u = 0; u<v; u++){
            if(!visited[u]){
                if(DFS(adj, u, visited, recVisited, st)){
                    return {};
                };
            }
        }

        while(!st.empty()){
            int u = st.top();
            st.pop();

            result.push_back(u);
        }

        return result;
    }
};