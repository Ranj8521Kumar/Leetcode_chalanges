class Solution {
public:
    int find(int u, vector<int>& parent){
        if(u  == parent[u]){
            return u;
        }

        return parent[u] = find(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, int &components){
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        if(parent_u != parent_v){
            parent[parent_v] = parent[u];
            components--;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int v = n;

        int edges = connections.size();

        if(edges < v-1) return -1;

        vector<int> parent(v);

        for(int u = 0; u<v; u++){
            parent[u] = u;
        }

        int components = v;

        for(auto &edge: connections){
            int u = edge[0];
            int v = edge[1];

            unionSet(u, v, parent, components);
        }

        return components - 1;
    }
};