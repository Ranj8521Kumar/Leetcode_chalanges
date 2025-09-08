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

    // vector<int> getNoZeroIntegers(int n) { // nlog(n) Complexity
    //     for(int i = 1; i<=n/2; i++){
    //         if(noZero(i) && noZero(n - i)){
    //             return {i, n-i};
    //         }
    //     }

    //     return {};
    // }



    vector<int> getNoZeroIntegers(int n) { // log(n) Complexity
        int a = 1; int b = n-1;
        while(true){
            if(noZero(a) && noZero(b)){
                return {a, b};
            }
            a++;
            b--;
        }

        return {};
    }
};