class Solution {
public:
    int getSum(int a, int b) {
        int ua = a;
        int ub = b;
        int result = 0;
        int carry = 0;
        for(int k = 0; k<=31; k++){
            int ra = (ua & 1);
            int rb = (ub & 1);

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

            ua >>= 1;
            ub >>= 1;
        }

        return result;
    }
};