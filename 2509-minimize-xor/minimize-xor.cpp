class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int setBitX = __builtin_popcount(x);
        int setBitNum2 = __builtin_popcount(num2);

        if(setBitX == setBitNum2){//case1: setBitX = setBitNum2
            return x;
        }else if(setBitX < setBitNum2){//case2: setBitX < setBitNum2
            int count = setBitNum2 - setBitX;
            for(int i = 0; i<=31; i++){
                if((x & (1<<i)) == 0){
                    x |= (1<<i);
                    count--;
                }

                if(count == 0){
                    return x;
                }
            }
        }else{//case3: setBitX > setBitNum2
            int count = setBitX - setBitNum2;
            for(int i = 0; i<=31; i++){
                if((x & (1<<i)) > 0){
                    x ^= (1<<i);
                    count--;
                }

                if(count == 0){
                    return x;
                }
            }
        }
        
        return -1;
    }
};