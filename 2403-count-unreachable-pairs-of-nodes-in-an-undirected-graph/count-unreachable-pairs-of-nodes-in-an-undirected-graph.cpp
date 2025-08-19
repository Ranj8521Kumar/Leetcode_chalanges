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

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            int u_parent = find(u, parent);
            int v_parent = find(v, parent);

            Union(u_parent, v_parent, parent);
        }


        unordered_map<int, int> mpp;
        for(int u = 0; u<n; u++){
            mpp[find(u, parent)]++;
        }

        long long result = 0;
        long long remainingNodes = n;

        for(auto &it: mpp){
            remainingNodes -= it.second;

            result += it.second*remainingNodes;
        }

        return result;
    }
};