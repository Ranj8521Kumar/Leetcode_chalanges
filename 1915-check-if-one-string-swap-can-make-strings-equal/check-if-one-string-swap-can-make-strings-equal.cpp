class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n != m){
            return false;
        }

        unordered_map<char, int> mpp;

        for(auto &ch: s1){
            mpp[ch]++;
        }

        for(auto &ch: s2){
            mpp[ch]--;
        }

        for(auto &it: mpp){
            if(it.second != 0){
                return false;
            }
        }

        int numberSwap = 0;
        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]){
                numberSwap++;
            }

            if(numberSwap > 2){
                return false;
            }
        }

        return true;
    }
};