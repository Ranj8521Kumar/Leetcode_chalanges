class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        int xorSum = 0;
        vector<int> result;
        for(int i = 0; i<n; i++){
            result.push_back((xorSum ^ pref[i]));
            xorSum ^= result[i];
        }

        return result;
    }
};