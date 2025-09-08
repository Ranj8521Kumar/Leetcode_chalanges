class Solution {
public:
    bool isPowerOfTwo(int n) {
        // for(int i = 0; i<=log2(n); i++){
        //     if(pow(2, i) == n){
        //         return true;
        //     }
        // }

        // return false;





        // Second Approach:
        if(n <= 0) return false;

        for(int k = 0;  k<=31; k++){
            if((n ^ (1 << k)) == 0){
                return true;
            }
        }

        return false;
    }
};