class Solution {
public:
    vector<int> countBits(int n) {
        // vector<int> result;
        
        // for(int i = 0; i<=n; i++){
        //     result.push_back(__builtin_popcount(i));
        // }

        // return result;


        // Another Approach:
        vector<int> result;

        for(int i = 0; i<=n; i++){
            int countOne = 0;
            int num = i;
            while(num != 0){
                if((num&1) == 1){
                    countOne++;
                }

                num >>= 1;
            }

            result.push_back(countOne);
        }

        return result;
    }
};