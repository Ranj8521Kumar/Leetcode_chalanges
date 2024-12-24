class Solution {
public:
    int find(int u, vector<int>& parent){
        if(u == parent[u]){
            return u;
        }

        return parent[u] = find(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int>& parent){
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        if(parent_u != parent_v){
            parent[parent_u] = parent_v;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();

        int result = 0;

        vector<vector<int>> adj;
        for(int i = 0; i<v; i++){
            for(int j = i+1; j<v; j++){
                auto point1 = points[i];
                auto point2 = points[j];

                int wt = abs(point2[0] - point1[0]) + abs(point2[1] - point1[1]);

                adj.push_back({i, j, wt});
            }
        }

        sort(adj.begin(), adj.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });

        int len = adj.size();

        vector<int> parent(v);
        for(int u = 0; u<v; u++){
            parent[u] = u;
        }

        for(auto &edge: adj){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(find(u, parent) != find(v, parent)){
                result += wt;
                unionSet(u, v, parent);
            }
        }

        return result;
    }
};