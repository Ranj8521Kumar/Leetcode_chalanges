class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //making the weighte graph
        int V = points.size();

        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i = 0; i<V; i++){
            for(int j = i+1; j<V; j++){
                auto p1 = points[i];
                auto p2 = points[j];

                int wt = abs(p2[0] - p1[0]) + abs(p2[1] - p1[1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }


        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int minCost = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int w = it.first;
            int node = it.second;

            if(visited[node] != true){
                visited[node] = true;
                minCost += w;

                for(auto &temp: adj[node]){
                    int v = temp.first;
                    int weight = temp.second;

                    pq.push({weight, v});
                }
            }
        }

        return minCost;
    }
};