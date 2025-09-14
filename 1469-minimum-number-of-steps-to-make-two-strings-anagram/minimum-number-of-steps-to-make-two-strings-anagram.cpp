class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mppS;
        unordered_map<char, int> mppT;

        int count = 0;
        for(auto &ch: s){
            mppS[ch]++;
        }

        for(auto &ch: t){
            mppT[ch]++;
        }

        for(auto &it: mppT){
            if(mppS[it.first] < it.second){
                count += (it.second - mppS[it.first]);
            }
        }

        return count;
    }
};