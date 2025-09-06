class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int k = 0; k<=31; k++){
            int countOnes = 0; // int countZeros = 0; since result is initialized with zeros, so all bits of result is zeros initially, so no need to set any bit to zero(if required), because it's already set
            for(auto &num: nums){
                if((num & (1 << k)) != 0){ // check kth bit of num is one or not
                    countOnes++;
                }
            }

            if(countOnes % 3 == 1){
                result = (result | (1 << k)); // make kth bit of result is one
            }
        }

        return result;
    }
};