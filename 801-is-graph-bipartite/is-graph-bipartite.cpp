class Solution {
public:
    bool BFS(vector<vector<int>>& adj, int u, vector<int>& color, int currColor){
        queue<int> que;
        que.push(u);

        color[u] = currColor;

        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(auto &v: adj[u]){
                if(color[v] == color[u]){
                    return false;
                }
        
                if(color[v] == -1){
                    que.push(v);
                    if(color[u] == 1){
                        color[v] = 0;
                    }else{
                        color[v] = 1; 
                    }
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        //using bfs
        int v  = graph.size();

        vector<int> color(v, -1);

        for(int u = 0; u<v; u++){
            if(color[u] == -1){
                int currColor = 1;
                if(!BFS(graph, u, color, currColor)){
                    return false;
                }
            }
        }

        return true;
    }
};