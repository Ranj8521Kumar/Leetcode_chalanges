class Solution {
public:
// If cycle detected then not possible to finish all the Courses
// Here detecting cycle using khan's Algorithm
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        unordered_map<int, vector<int>> adj;
        vector<int> indgree(v, 0);

        for(auto &vec: prerequisites){
            int u =  vec[1];
            int v =  vec[0];

            adj[u].push_back(v);
            indgree[v]++;
        }

        int count = 0;
        queue<int> que;
        for(int u = 0; u<v; u++){
            if(indgree[u] == 0){
                que.push(u);
                count++;
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(auto &v: adj[u]){
                indgree[v]--;

                if(indgree[v] == 0){
                    que.push(v);
                    count++;
                }
            }
        }

        if(count != v){
            return false;
        }

        return true;
    }
};