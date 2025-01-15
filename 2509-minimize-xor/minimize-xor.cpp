class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0;

        int requiredSetBits = __builtin_popcount(num2);

        for(int i = 31; i>=0 && requiredSetBits > 0; i--){
            if((num1 & (1<<i)) > 0){
                x |= ((1<<i));
                requiredSetBits--;
            }
        }

        for(int i = 0; i<=31 && requiredSetBits > 0; i++){
            if((num1 & (1<<i)) == 0){
                x |= ((1<<i));
                requiredSetBits--;
            }
        }

        return x;
    }
};