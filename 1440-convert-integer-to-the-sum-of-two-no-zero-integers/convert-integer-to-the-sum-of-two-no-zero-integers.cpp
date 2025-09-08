class Solution {
public:
    bool noZero(int n){
        while(n > 0){
            int digit = n%10;
            if(digit == 0){
                return false;
            }

            n /= 10;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i<=n/2; i++){
            if(noZero(i) && noZero(n - i)){
                return {i, n-i};
            }
        }

        return {};
    }
};