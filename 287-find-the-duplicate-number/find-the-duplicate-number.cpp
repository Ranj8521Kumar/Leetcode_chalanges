class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result = 0;
        int n = nums.size() - 1; // because constraints says like nums has n+1 intergers and range [1, n]

        for(int k = 0; k<=31; k++){
            int countRange = 0;
            for(int i = 1; i<=n; i++){
                if((i & (1 << k)) != 0){
                    countRange++;
                }
            }

            int countNums = 0;
            for(auto &it: nums){
                if((it & (1 << k)) != 0){
                    countNums++;
                }
            }

            if(countNums > countRange){
                result |= (1 << k);
            }
        }

        return result;
    }
};