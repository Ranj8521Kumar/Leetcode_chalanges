class Solution {
public:
    int getSetBits(int n){
        return __builtin_popcount(n);
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int &a, int &b){
            int x = getSetBits(a);
            int y = getSetBits(b);

            return (x == y) ? a <= b : x < y;
        });

        return arr;
    }
};