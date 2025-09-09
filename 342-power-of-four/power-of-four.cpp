class Solution {
public:
    bool isPowerOfFour(int n) {
        // for(int i = 0; i<=(log2(n)/2); i++){
        //     if(pow(4, i) == n){
        //         return true;
        //     }
        // }

        // return false;




        // Another Method:
        // if(n <= 0) return false;
        // for(int k = 0; k<=31; k+=2){
        //     if((1<<k) == n){
        //         return true;
        //     }
        // }

        // return false;




        // Third Approach:
        if(n <= 0) return 0;
        if((n & (n - 1)) == 0){ // Power of 2
            if((n & (0x555555555)) != 0){ // power of 4(power of 2 has set bit at even position);
                return true;
            }
        }

        return false;
    }
};