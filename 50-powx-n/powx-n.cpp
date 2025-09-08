class Solution {
public:
    double fastPow(double x, long long N){
        if(N == 0) return 1;

        double half = myPow(x, N/2);
        if(N % 2 == 0){
            return half*half;
        }else{
            return half * half * x;
        }
    }

    // double myPow(double x, int n) {
    //     if(n == 0) return 1;

    //     // take negative n(power) to the positive, because INT_MIN overflow when negated(In long long data type)
        
    //     long long N = n;
    //     if(N < 0){
    //         x = 1 / x;
    //         N = -N;
    //     }

    //     return fastPow(x, N);
    // }





    // Another Approach: Without stack space/ recursion space
    double myPow(double x, int n) {
        if(n == 0) return 1;

        // take negative n(power) to the positive, because INT_MIN overflow when negated(In long long data type)
        
        long long N = n;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }

        double result = 1;
        while(N > 0){
            if(N % 2 == 1){ // N is Odd
                result *= x;
            }
            x *= x;
            N /= 2;
        }

        return result;
    }
};