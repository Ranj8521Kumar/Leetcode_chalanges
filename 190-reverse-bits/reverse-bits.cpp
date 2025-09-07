class Solution {
public:
    int reverseBits(int n) {
        // int result = 0;

        // for(int k = 0; k<=31; k++){
        //     if((n & 1) == 1){
        //         result += (1 << (31 - k));
        //     }

        //     n >>= 1;
        // }

        // return result;





        // Another Method:
        // int result = 0;

        // for(int k = 0; k<=31; k++){
        //     result <<= 1;
        //     result |= (n & 1);
        //     n >>= 1;
        // }

        // return result;



//  Why unsigned int?


/* Bitwise operations don’t care about sign
        But if you use int result, the sign bit (MSB) could     cause confusion when shifting.
        Example: If result becomes something like 1000...000 in binary, an int would treat it as negative, while unsigned int keeps it as a large positive number. */

/*Left shifts (<<) are safer with unsigned:
    In C++, left-shifting a signed integer into the sign bit is undefined behavior.
    With unsigned int, shifting is always well-defined because it just rotates bits and doesn’t care about sign.*/

/*We only want raw bit patterns:
    When reversing bits, we don’t actually want to interpret them as negative/positive until the very end.
    Using unsigned int means result is just a bucket of 32 raw bits.
    At the end, you cast back to int, so the caller gets the correct signed interpretation.*/

        unsigned int result = 0;

        for(int k = 0; k<=31; k++){
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }

        return (int)result;
    }
};