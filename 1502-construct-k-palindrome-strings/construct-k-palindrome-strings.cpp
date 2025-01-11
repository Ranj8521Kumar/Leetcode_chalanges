class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();

        if(n < k){
            return false;
        }

        unordered_map<char, int> mpp;
        for(auto &ch: s){
            mpp[ch]++;
        }

        int oddCount = 0;
        for(auto &it: mpp){
            if(it.second % 2 != 0){
                oddCount++;
            }
        }

        if(oddCount > k){
            return false;
        }

        return true;
    }
};