class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;

        for(auto &ch: t){
            mpt[ch]++;
        }

        for(auto &ch: s){
            mps[ch]++;
        }

        for(auto &ch: t){
            if(mpt[ch] > mps[ch]){
                return ch;
            }
        }

        return ' ';
    }
};