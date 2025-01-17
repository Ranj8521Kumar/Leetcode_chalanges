class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> inDegree, outDegree;
        for(auto &pair: pairs){
            int u = pair[0];
            int v = pair[1];

            adj[u].push_back(v);
            inDegree[v]++;
            outDegree[u]++;
        }

        int startingNode = pairs[0][0];

        for(auto &v: adj){
            int node = v.first;

            if((outDegree[node] - inDegree[node]) == 1){
                startingNode = node;
                break;
            }
        }

        vector<int> eulerPath; // for store path
        stack<int> st; // for perfomminf dfs

        st.push(startingNode);
        while(!st.empty()){
            int curr = st.top();

            if(!adj[curr].empty()){
                int neighbour = adj[curr].back();
                adj[curr].pop_back();
                st.push(neighbour);
            }else{
                eulerPath.push_back(curr);
                st.pop();
            }
        }

        reverse(eulerPath.begin(),  eulerPath.end());

        // for finding correct pairs from euler path
        vector<vector<int>> result;
        for(int i = 0; i<eulerPath.size() - 1; i++){
            result.push_back({eulerPath[i], eulerPath[i+1]});
        }

        return result;
    }
};