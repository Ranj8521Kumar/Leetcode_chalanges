class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        int zeroCount = 0;

        vector<int> output(n , 0);

        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                product *= nums[i];
            }else{
                zeroCount++;
            }
        }

        if(zeroCount >= 2){
            
        }else if(zeroCount == 1){
            for(int i = 0; i<n; i++){
                if(nums[i] == 0){
                    output[i] = product;
                }
            }
        }else{
            for(int i = 0; i<n; i++){
                output[i] = product/nums[i];
            }
        }

        return output;
    }
};