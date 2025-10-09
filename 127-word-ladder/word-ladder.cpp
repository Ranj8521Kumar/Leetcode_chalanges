class Solution {
public:
    int compareStr(string &str1, string &str2){
        int diff = 0;
        for(int i = 0; i<str1.size(); i++){
            if(str1[i] != str2[i]){
                diff++;
            }
        }

        return diff;
    }

    int n;
    int bfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u, int endIdx){
        queue<int> que;
        que.push(u);
        visited[u] = true;
        int level = 0;

        while(!que.empty()){

            int len = que.size();
            level += 1;

            while(len--){
                int u = que.front();
                que.pop();

                if(u == endIdx){
                    return level;
                }

                for(auto &v: adj[u]){
                    if(!visited[v]){
                        que.push(v);
                        visited[v] = true;
                    }
                }
            }
        }

        return 0; // Not reachable
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();
        unordered_map<int, vector<int>> adj;

        // checxk the endWord and brginWord are in the list or not?
        bool isEndWord = false;
        int endIdx = -1;

        for(int i = 0; i<n; i++){
            if(endWord == wordList[i]){
                endIdx = i+1;
                isEndWord = true;
            }
        }

        if(!isEndWord){
            return 0;
        }
        
        // beginword --> 0
        for(int i = 0; i<n; i++){
            string str = wordList[i];
            int diff = compareStr(beginWord, str);
            if(diff == 1){
                adj[0].push_back(i+1);
                adj[i+1].push_back(0);
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j){
                    continue;
                }else{
                    int diff = compareStr(wordList[i], wordList[j]);
                    if(diff == 1){
                        adj[i+1].push_back(j+1);
                        adj[j+1].push_back(i+1);
                    }
                }
            }
        }

        int v = adj.size();
        vector<bool> visited(n+1, false);

        if(v == 0) return 0;

        return bfs(adj, visited, 0, endIdx);
    }
};