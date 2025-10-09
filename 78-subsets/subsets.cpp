class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        for(int i = 0; i<(pow(2, n)); i++){
            vector<int> temp;
            int x = i;
            for(int k=0; k<32; k++){
                if((x & 1) == 1){
                    temp.push_back(nums[k]);
                }

                x >>= 1;
            }

            result.push_back(temp);
        }

        return result;
    }
};