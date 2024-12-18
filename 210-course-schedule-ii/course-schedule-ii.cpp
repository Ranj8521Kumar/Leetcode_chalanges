class Solution {
public:
    void BFS(unordered_map<int, vector<int>>& adj, vector<int>& indegree, vector<int>& result, int v){
        queue<int> que;
        int count = 0;

        for(int u = 0; u<v; u++){
            if(indegree[u] == 0){
                que.push(u);
                count++;
            }
        }

        while(!que.empty()){
            int u = que.front();
            result.push_back(u);
            que.pop();

            for(auto &v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    que.push(v);
                    count++;
                }
            }
        }

        if(count != v){
            result  = {};
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        int n = prerequisites.size();

        vector<int> result;

        vector<int> indegree(v, 0);
        unordered_map<int, vector<int>> adj;

        for(auto &vec: prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);

            indegree[v]++;
        }

        BFS(adj, indegree, result, v);

        return result;
    }
};