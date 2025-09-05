class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
    //     int k = 0;

    //     while(true){
    //         long long val = (long long)num1 - (long long)k * num2;
    //         if(val <= 0) return -1;

    //         int setBits = __builtin_popcountll(val);
    //         if(setBits <= k && k <= val){
    //             return k;
    //         }

    //         k++;
    //     }

    //     return -1;
    // }


    // Another Approach:

    //     for(int k = 0; k<=35; k++){
    //         long long val = (long long)num1 - (long long)k * num2;
    //         if(val <= 0) return -1;

    //         int setBits = __builtin_popcountll(val);
    //         if(setBits <= k && k <= val){
    //             return k;
    //         }
    //     }

    //     return -1;
    // }



    // Or set limit for k is according to the constraint:

        for(int k = 0; k<=60; k++){
            long long val = (long long)num1 - (long long)k * num2;
            if(val <= 0) return -1;

            int setBits = __builtin_popcountll(val);
            if(setBits <= k && k <= val){
                return k;
            }
        }

        return -1;
    }
};