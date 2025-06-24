class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        // vector<int> result;
        // int n = nums.size();

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(nums[j] == key){
        //             if(abs(i - j) <= k){
        //                 result.push_back(i);
        //                 break;
        //             }
        //         }
        //     }
        // }

        // return result;


        //Optimized Code //Second Method
        int n = nums.size();
        vector<int> result;
        vector<int> keyIndex;

        for(int i = 0; i<n; i++){
            if(nums[i] == key){
                keyIndex.push_back(i);
            }
        }

        int m = keyIndex.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(abs(i - keyIndex[j]) <= k){
                    result.push_back(i);
                    break;
                }
            }
        }

        return result;
    }
};