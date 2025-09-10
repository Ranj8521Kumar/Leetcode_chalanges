class Solution {
public:
    int minOperations(vector<int>& nums, int K) {
    //     int minOper = 0;
    //     int Xor = 0;
        
    //     for(int k = 0; k <= 31; k++){
    //         for(auto &num: nums){
    //             Xor ^= ((num >> k) & 1);
    //         }

    //         if(Xor != ((K >> k) & 1)){
    //             minOper++;
    //         }

    //         Xor = 0;
    //     }

    //     return minOper;
    // }


    // Other Approach:
        int minOper = 0;
        int Xor = 0;

        for(auto &num: nums){
            Xor ^= num;
        }
        
        for(int k = 0; k <= 31; k++){
            if(((Xor >> k) & 1) != ((K >> k) & 1)){
                minOper++;
            }
        }

        return minOper;
    }
};