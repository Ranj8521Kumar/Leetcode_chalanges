class Solution {
public:
    int find(int u, vector<int> &parent){
        if(u == parent[u]){
            return u;
        }

        return parent[u] =  find(parent[u], parent);
    }

    void Union(int u, int v, vector<int> &parent){
        if(u != v){
            parent[u] = v;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n, 0);

        if(connections.size() < n - 1) return -1;

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        int components = n;

        for(auto &edge: connections){
            int u = edge[0];
            int v = edge[1];

            int parentU = find(u, parent);
            int parentV = find(v, parent);

            if(parentU != parentV){
                components--;
                Union(parentU, parentV, parent);
            }
        }

        return components - 1;
    }
};