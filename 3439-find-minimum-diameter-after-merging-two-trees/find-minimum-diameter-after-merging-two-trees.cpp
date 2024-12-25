class Solution {
public:
    pair<int, int> DFS(unordered_map<int, vector<int>>& adj, int u, unordered_map<int, bool>& visited){
        int maxDist = 0;
        int farthestNode = u;
        
        visited[u] = true;
        for(auto &v: adj[u]){
            if(!visited[v]){
                auto temp = DFS(adj, v, visited);

                if(temp.first + 1 > maxDist){
                    maxDist = temp.first + 1;
                    farthestNode = temp.second;
                }
            }
        }

        return {maxDist, farthestNode};
    }


    int treeDiameter(vector<vector<int>>& edges){
        unordered_map<int, vector<int>> adj;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;

        auto [maxDist, farthestNode] = DFS(adj, 0, visited);//find one end of the diameter

        visited = unordered_map<int, bool> (false);
        auto [diameter, secondEnd] = DFS(adj, farthestNode, visited);//find length of the diameter or second length of  the diameter

        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = treeDiameter(edges1);
        int d2 = treeDiameter(edges2);

        int half1 = (d1+1)/2;
        int half2 = (d2+1)/2;

        return max({d1, d2, half1 + half2 + 1});
    }
};