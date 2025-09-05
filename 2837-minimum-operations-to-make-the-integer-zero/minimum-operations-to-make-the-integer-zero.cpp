class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;

        while(true){
            long long val = (long long)num1 - (long long)k * num2;
            if(val <= 0) return -1;

            int setBits = __builtin_popcountll(val);
            if(setBits <= k && k <= val){
                return k;
            }

            k++;
        }

        return -1;
    }
};