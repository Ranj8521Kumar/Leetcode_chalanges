class Solution {
public:
    // void DFS(unordered_map<int, vector<int>>& adj, vector<int> &temp, int u, vector<bool> &visited, int height){
    //     if(visited[u]) return;

    //     visited[u] = true;
    //     for(auto &v: adj[u]){
    //         if(!visited[v]){
    //             DFS(adj, temp, v, visited, height + 1);
    //         }
    //     }

    //     temp[u] = max(temp[u], height);
    //     height--;
    //     visited[u] = false;
    // }


    vector<int> BFS(unordered_map<int, vector<int>> &adj, vector<int> &indegree, int n){
        queue<int> que;
        vector<int> result;

        for(int u = 0; u<n; u++){
            if(indegree[u] == 1){
                que.push(u);
            }
        }

        while(!que.empty()){
            int len = que.size();
            result.clear();

            while(len--){
                int u = que.front(); que.pop();
                result.push_back(u);

                for(auto &v: adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 1){
                        que.push(v);
                    }
                }
            }
        }

        //return (!result.empty()) ? result : {0}; // This will throw the error like ternary operator(?:) requires both sides to be of the same type
        return (!result.empty()) ? result : vector<int> {0};
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // This approach will throw the timw limit exceed error and passed 67 test cases out of 71, that is a good number:
        // unordered_map<int, vector<int>> adj;
        // for(auto &edge: edges){
        //     int u = edge[0];
        //     int v = edge[1];

        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        // vector<int> temp(n, 0);
        // vector<bool> visited(n, false);
        // int height = 0;
        // for(int u = 0; u<n; u++){
        //     DFS(adj, temp, u, visited, height);
        // }

        // vector<int> result;
        // result.push_back(0);
        // int minValue = temp[0];
        // for(int i = 1; i<n; i++){
        //     if(temp[i] < minValue){
        //         minValue = temp[i];
        //         result.clear();
        //         result.push_back(i);
        //     }else if(temp[i] == temp[result.back()]){
        //         result.push_back(i);
        //     }
        // }

        // return result;




        // Let's Apply the BFS Approach with cutting the leaf nodes and going to the central nodes because leaf nodes have maximum height
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[v]++;
            indegree[u]++;
        }

        return BFS(adj, indegree, n);
    }
};