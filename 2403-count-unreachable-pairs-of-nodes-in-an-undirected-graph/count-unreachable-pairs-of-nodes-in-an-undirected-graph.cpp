class Solution {
public:
    int find(int u, vector<int>& parent){
        if(u == parent[u]){
            return u;
        }

        return parent[u] = find(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        if(parent_u != parent_v){
            if(rank[parent_u] == rank[parent_v]){
                parent[parent_u] = parent_v;
                rank[parent_u]++;
            }else if(rank[parent_u] > rank[parent_v]){
                parent[parent_v] = parent_u;
            }else{
                parent[parent_u] = parent_v;
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {   
        //using DSU
        int v = n;

        vector<int> parent(v);
        vector<int> rank(v, 0);

        for(int u = 0; u<v; u++){
            parent[u] = u;
        }
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            unionSet(u, v, parent, rank);
        }

        //count number of nodes in a component
        unordered_map<int, int> count;
        for(int u  = 0; u<v; u++){
            count[find(u, parent)]++;
        }

        long long remainingNode = v;
        long long result = 0;

        for(auto &it: count){
            remainingNode -= it.second;
            result += it.second*remainingNode;
        }

        return result;
    }
};