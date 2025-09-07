class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        
        for(int k = 0; k<=31; k++){
            if((n & 1) == 1){
                result++;
            }

            n >>= 1;
        }

        return result;
    }
};