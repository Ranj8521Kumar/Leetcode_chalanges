class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(v, 0);

        for(auto &vec:  prerequisites){
            int u =  vec[1];
            int v = vec[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        int count = 0;
        vector<int> result;
        for(int u = 0; u<v; u++){
            if(indegree[u] == 0){
                que.push(u);
                count++;
                result.push_back(u);
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
                    result.push_back(v);
                }
            }
        }

        if(count != v){
            return {};
        }

        return result;
    }
};