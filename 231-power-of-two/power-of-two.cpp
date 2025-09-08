class Solution {
public:
    bool isPowerOfTwo(int n) {
        // for(int i = 0; i<=log2(n); i++){
        //     if(pow(2, i) == n){
        //         return true;
        //     }
        // }

        // return false;

        // Notes for first Approach:
        /* Case: n < 0

log2(n) is undefined for negative inputs.

In C++ <cmath>, calling log2 with a negative value is domain error → it returns NaN (Not a Number).

Now, check your loop condition:

i <= log2(n)


log2(n) = NaN.

Any comparison with NaN (i <= NaN) is always false.

So the loop body never executes.

Thus, no error is thrown — the function just skips the loop and returns false. */


// Second Notes:
/* case: n == 0 => Step 1: Evaluate log2(0)

Mathematically, log2(0) = −∞.

In C++ <cmath>, log2(0) produces negative infinity (-inf).

Step 2: Loop condition

Loop condition is i <= log2(0) → i <= -inf.

For i = 0, this becomes 0 <= -inf, which is false.

So the loop never executes.

Step 3: Return

Since loop body is skipped, function goes straight to return false;. */





        // // Second Approach:
        // if(n <= 0) return false;

        // for(int k = 0;  k<=31; k++){
        //     if(((1 << k)) == n){
        //         return true;
        //     }
        // }

        // return false;


        // Third Approach: More Optimized
        if(n <= 0) return false;

        return (n & (n - 1)) == 0;
    }
};