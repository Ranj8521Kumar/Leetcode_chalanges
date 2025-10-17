class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;

        for(auto &ch: s){
            mpp[ch]++;
        }

        vector<pair<int, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), [&](auto &p1, auto &p2){
            return p1.second > p2.second;
        });

        string str = "";
        for(auto &it: vec){
            int len = it.second;
            while(len--){
                str.push_back(it.first);
            }
        }

        return str;
    }
};