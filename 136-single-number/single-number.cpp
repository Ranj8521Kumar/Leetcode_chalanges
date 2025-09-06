class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int k = 0; k<=31; k++){
            int countOnes = 0;
            int mask = (1<<k);

            for(auto &num: nums){
                if((num & mask) != 0){//check  kth bit of nums is one or not
                    countOnes += 1;
                }
            }

            if(countOnes % 2 == 1){
                result = (result | (mask)); // set kth bit of resut to one
            }
        }

        return result;
    }
};