class Solution {
private:
    void sortArray(vector<int>& gifts){
        sort(begin(gifts), end(gifts), [](int a, int b){
            return a>b;
        });
    }

public:
    long long pickGifts(vector<int>& gifts, int k) {
        while(k--){
            sortArray(gifts);
            gifts[0] = sqrt(gifts[0]);
        }

        long long result = 0;

        for(auto it: gifts){
            result += it;
        }

        return result;
    }
};