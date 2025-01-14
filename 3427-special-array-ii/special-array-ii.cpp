class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parityChecks(n-1, 0);

        //for parity checks
        for(int i = 0; i<n-1; i++){
            parityChecks[i] = (nums[i]%2 != nums[i+1]%2);
        }

        //prefix sum for parity checks
        vector<int> prefix(n, 0);
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + parityChecks[i-1];
        }


        vector<bool> result;
        for(const auto &q: queries){
            int from = q[0];
            int to = q[1];

            int totalPairs = to - from;
            int validPairs = prefix[to] - prefix[from];

            result.push_back(totalPairs == validPairs);
        }

        return result;
    }
};