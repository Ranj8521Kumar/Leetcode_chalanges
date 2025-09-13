class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // This Method throw the TLE:
        // vector<int> result;
        // for(auto &query: queries){
        //     int left = query[0];
        //     int right = query[1];

        //     int Xor = 0;
        //     for(int i = left; i<=right; i++){
        //         Xor ^= arr[i];
        //     }

        //     result.push_back(Xor);
        // }

        // return result;





        // Optimized Approach:
        // Using Prefix-Sum Approach
        vector<int> result;
        vector<int> prefixXor;
        int Xor = 0;
        for(auto &it: arr){
            Xor ^= it;
            prefixXor.push_back(Xor);
        }

        for(auto &query: queries){
            int left = query[0];
            int right = query[1];

            int ans;
            if(left != 0){
                ans = prefixXor[right]^prefixXor[left - 1];
            }else{
                ans = prefixXor[right];
            }

            result.push_back(ans);
        }

        return result;
    }
};