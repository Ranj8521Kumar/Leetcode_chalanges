class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i = 0; i<=(log2(n)/2); i++){
            if(pow(4, i) == n){
                return true;
            }
        }

        return false;
    }
};