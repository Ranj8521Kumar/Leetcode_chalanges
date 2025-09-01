class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mpp;

        int n = s.size();
        if(n <= 10) return {};

        for(int i = 0; i<=(n-10); i++){ // making window of 10
            string str = s.substr(i, 10);
            mpp[str]++;
        }

        vector<string> result;
        for(auto &it: mpp){
            if(it.second >= 2){
                result.push_back(it.first);
            }
        }

        return result;
    }
};