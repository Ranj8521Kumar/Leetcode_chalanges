class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;

        vector<vector<int>> adj(v, vector<int> ());
        for(auto &vec: prerequisites){
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }
        
        vector<int> indegree(v, 0);
        for(int u = 0; u<v; u++){
            for(auto &v: adj[u]){
                indegree[v]++;
            }
        }

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
            que.pop();

            for(auto &v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    que.push(v);
                    count++;
                }
            }
        }

        if(count == v){
            return true;//topological sort possible
        }
        
        return false;
    }
};