class Solution {
public:
//thought process:
    //since for (a, b) => if I want to complete course a then first we have to complete b, means b->a, that is the meaninig of topological sort, 

    //let's take an example that (a, b) and (b, a) => there is a cycle in the graph for this, means completion of cource a is dependent of cource b and completion of course b is dependent on course a, so if cycle detected then we  can not finish all the course,

    //ApProach: Khan's Algorithm(cycle detection using BFS)

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        int n = prerequisites.size();

        vector<vector<int>> adj(v, vector<int> ());

        for(auto &vec: prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
        }

        vector<int> indegree(v, 0);
        for(int u = 0; u<v; u++){
            for(auto &v: adj[u]){
                indegree[v]++;
            }
        }

        queue<int> que;
        for(int u = 0; u<v; u++){
            if(indegree[u] == 0){
                que.push(u);
            }
        }

        int count = 0;

        while(!que.empty()){
            int u  = que.front();
            que.pop();
            count++;

            for(auto &v: adj[u]){
                indegree[v]--;
                
                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }

        if(count != v){
            return false;
        }

        return true;
    }
};