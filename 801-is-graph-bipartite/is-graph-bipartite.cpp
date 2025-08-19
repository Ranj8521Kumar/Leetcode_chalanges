class Solution {
public:
    bool BFS(vector<vector<int>>& graph, vector<int>& color, int currNode, int currColor){
        queue<int> que;
        que.push(currNode);
        color[currNode] = currColor;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(auto &v: graph[u]){
                if(color[v] == -1){
                    // if(BFS(graph, color, v, currColor) == false){
                    //     return false;
                    // }

                    color[v] = 1 - color[u];
                    que.push(v);
                }else{
                    if(color[v] == color[u]){
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int u = 0; u<V; u++){
            if(color[u] == -1 && BFS(graph, color, u, 0) == false){
                return false;
            }
        }

        return true;
    }
};