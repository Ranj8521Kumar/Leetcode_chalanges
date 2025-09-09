class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        int carry = 0;
        for(int k = 0; k<=31; k++){
            int ra = (a & 1);
            int rb = (b & 1);

            if(carry == 0){
                if(ra == 0 && rb == 0){
                   
                }else if((ra == 0 && rb == 1) || (ra == 1 && rb == 0)){
                    result |= (1 << k);
                }else{
                    carry = 1;
                }
            }else{
                if(ra == 0 && rb == 0){
                   result |= (1 << k);
                   carry = 0;
                }else if((ra == 0 && rb == 1) || (ra == 1 && rb == 0)){
                    carry = 1;
                }else{
                    result |= (1 << k);
                    carry = 1;
                }
            }

            a >>= 1;
            b >>= 1;
        }

        return result;
    }
};