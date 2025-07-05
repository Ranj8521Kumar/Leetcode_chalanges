class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mpp;

        for(auto it: arr){
            mpp[it]++;
        }

        int luckyInteger = -1;

        for(auto it: mpp){
            if(it.first == it.second){
                luckyInteger = max(luckyInteger, it.first);
            }
        }

        return luckyInteger;
    }
};