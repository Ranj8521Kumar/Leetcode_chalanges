class Solution {
public:
    bool DFS(vector<vector<int>>& adj, int u, vector<int>& color, int currColor){
        color[u] = currColor;

        for(auto &v: adj[u]){
            if(color[v] == color[u]){// Same color on both ends of an edge
                return false;
            }else{
                if(color[v] == -1){
                    if(color[u] == 1){
                        color[v] = 0;
                    }else{
                        color[v] = 1;
                    }

                    //or, for assigning color
                    //color[v] = 1 - color[u]; // for opposite color

                    if(!DFS(adj, v, color, color[v])){
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        //red -> 1
        //blue -> 0
        //no-color -> -1
        vector<int> color(v, -1);

        for(int u = 0; u<v; u++){
            if(color[u] == -1){
                int currColor = 1; // Assign initial color
                if(!DFS(graph, u, color, currColor)){
                    return false;
                }
            }
        }

        return true;
    }
};