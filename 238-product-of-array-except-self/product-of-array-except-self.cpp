class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        
        // int prod = 1;
        // vector<int> prefix(n, 1);
        // for(int i = 1; i<n; i++){
        //     prod = prod * nums[i-1];
        //     prefix[i] =  prod;
        // }

        // prod = 1;
        // vector<int> suffix(n, 1);
        // for(int  i = n-2; i>=0; i--){
        //     prod = prod * nums[i+1];
        //     suffix[i] =  prod;
        // }

        // for(int i = 0; i<n; i++){
        //     nums[i] = prefix[i]*suffix[i];
        // }

        // return nums;


        // Let's try to solve this question in  O(1) space complexity, according to the question:
        int n = nums.size();
        int prod = 1;
        vector<int> result(n, 1);
        
        for(int i = 0; i<n; i++){
            result[i] = prod;
            prod *= nums[i];
        }

        prod = 1;
        for(int i = n-1; i>=0; i--){
            result[i] = result[i] * prod;
            prod = prod * nums[i];

        }

        return result;
    }
};