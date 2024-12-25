class Solution {
public:
    pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int u){
        unordered_map<int, bool> visited;
        int maxDist = 0;
        int farthestNode = u;
        queue<int> que;

        que.push(u);
        visited[u] = true;

        while(!que.empty()){
            int len = que.size(); //size of current level

            while(len--){
                int u = que.front();
                que.pop();
                farthestNode = u;

                //adding node of next level
                for(auto &v: adj[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        que.push(v);
                    }
                }
            }

            if(!que.empty()){// if que empty then there is no any level
                maxDist++;
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

        auto [maxDist, farthestNode] = BFS(adj, 0);//find one end of the diameter
        auto [diameter, _] = BFS(adj, farthestNode);//find length of the diameter or second length of  the diameter

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