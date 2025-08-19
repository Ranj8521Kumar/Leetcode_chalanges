class Solution {
public:
    int find(int u, vector<int> &parent){
        if(u == parent[u]){
            return u;
        }

        return parent[u] = find(parent[u], parent);
    }

    void Union(int u, int v, vector<int>& parent){
        if(u != v){
            parent[u] = v;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        int V = equations.size();

        vector<int> parent(26, 0);
        for(int i = 0; i<26; i++){
            parent[i] = i;
        }

        for(auto &str: equations){
            if(str[1] == '='){
                int firstParent = find(str[0] - 'a', parent);
                int secondParent = find(str[3] -'a', parent);

                Union(firstParent, secondParent, parent);
            }
        }

        for(auto &str: equations){
            if(str[1] == '!'){
                int firstParent = find(str[0] - 'a', parent);
                int secondParent = find(str[3] -'a', parent);

                if(firstParent == secondParent){
                    return false;
                }
            }
        }

        return true;
    }
};