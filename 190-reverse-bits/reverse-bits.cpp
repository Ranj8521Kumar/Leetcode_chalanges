class Solution {
public:
    int reverseBits(int n) {
        int result = 0;

        for(int k = 0; k<=31; k++){
            if((n & 1) == 1){
                result += (1 << (31 - k));
            }

            n >>= 1;
        }

        return result;
    }
};