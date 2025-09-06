class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    //     int xorSum = 0;

    //     for(auto &num: nums){
    //         xorSum ^= num;
    //     } // xorSum contains only those numbers that appears only single times

    //     // Calculate Mask(number with first rightmost set bit of XOR is one)
    //     int mask;
    //     for(int k = 0; k<=31; k++){
    //         if(xorSum & 1){//get rightmost bit of xorSum
    //             mask = (1 << k);//create mask, where rightMost setBit of xorSum
    //             break;
    //         }
    //         xorSum >>= 1;
    //     }

    //     // Divide whole nums in two groups, such that both  numbers that appears exactly one is come under one another group
    //     int a = 0;
    //     int b = 0;
    //     for(auto &num: nums){
    //         if(num & mask){
    //             a ^= num;
    //         }else{
    //             b ^= num;
    //         }
    //     }

    //     return {a,  b};
    // }





    // We can directly find the setRightMost bit of xorSum:
        long long xorSum = 0;

        for(auto &num: nums){
            xorSum ^= num;
        } // xorSum contains only those numbers that appears only single times

        // Calculate Mask(number with first rightmost set bit of XOR is one)
        int mask;
        // for(int k = 0; k<=31; k++){
        //     if(xorSum & 1){//get rightmost bit of xorSum
        //         mask = (1 << k);//create mask, where rightMost setBit of xorSum
        //         break;
        //     }
        //     xorSum >>= 1;
        // }


        mask = (xorSum & (-xorSum)); // Get number with first rightmost set bit of a number

        // Divide whole nums in two groups, such that both  numbers that appears exactly one is come under one another group
        int a = 0;
        int b = 0;
        for(auto &num: nums){
            if(num & mask){
                a ^= num;
            }else{
                b ^= num;
            }
        }

        return {a,  b};
    }
};