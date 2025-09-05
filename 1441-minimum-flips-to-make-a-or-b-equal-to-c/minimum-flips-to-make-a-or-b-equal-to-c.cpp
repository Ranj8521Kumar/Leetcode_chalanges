class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while( a != 0 ||  b != 0 || c != 0){
            int rightMostBitOfa = (a & 1);
            int rightMostBitOfb = (b & 1);
            int rightMostBitOfc = (c & 1);

            if(rightMostBitOfc == 1){
                if(rightMostBitOfa == 0 && rightMostBitOfb == 0){
                    flips++;
                }
            }else if(rightMostBitOfc == 0){
                if(rightMostBitOfa == 1 && rightMostBitOfb == 1){
                    flips += 2;
                }else if(rightMostBitOfa == 1 || rightMostBitOfb == 1){
                    flips++;
                }
            }

            // Right Shift of a, b and c
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};