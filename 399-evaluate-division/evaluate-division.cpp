class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>>& adj, string src, string dest, double prod, unordered_set<string>& visited, double &ans){
        visited.insert(src);

        if(src == dest){
            ans = prod;
            return;
        }

        for(auto &v: adj[src]){
            string src = v.first;
            double value = v.second;

            if(visited.find(src) == visited.end()){
                dfs(adj, src, dest, prod*value, visited, ans);
            }
        }

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = equations.size();
        
        for(int i = 0; i<n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double value = values[i];

            adj[u].push_back({v, value});
            adj[v].push_back({u, 1.0/value});
        }

        vector<double> result;

        for(auto &query: queries){
            string src = query[0];
            string dest = query[1];

            double ans = -1.0;

            if(adj.find(src) != adj.end()){
                unordered_set<string> visited;
                dfs(adj, src, dest, 1.0, visited, ans);
            }

            result.push_back(ans);
        }


        return result;

    }
};