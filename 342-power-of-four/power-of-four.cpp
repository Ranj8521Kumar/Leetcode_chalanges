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
        if(n <= 0) return false;
        for(int k = 0; k<=31; k+=2){
            if((1<<k) == n){
                return true;
            }
        }

        return false;
    }
};