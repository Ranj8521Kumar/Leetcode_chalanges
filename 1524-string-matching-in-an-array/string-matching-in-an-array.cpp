class Solution {
public:
    static bool cmp(const string &a, const string &b){
        return a.size() < b.size();
    }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        sort(words.begin(), words.end(), cmp);

        for(int i = 0; i < n; i++){
            for(int j = n - 1; j > i; j--){
                if(words[j].find(words[i]) != string::npos){
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};