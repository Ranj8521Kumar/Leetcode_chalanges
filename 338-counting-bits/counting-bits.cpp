class Solution {
public:
    vector<int> countBits(int n) {
        // vector<int> result;
        
        // for(int i = 0; i<=n; i++){
        //     result.push_back(__builtin_popcount(i));
        // }

        // return result;


    //     // Another Approach:
    //     vector<int> result;

    //     for(int i = 0; i<=n; i++){
    //         int countOne = 0;
    //         int num = i;
    //         while(num != 0){
    //             if((num&1) == 1){
    //                 countOne++;
    //             }

    //             num >>= 1;
    //         }

    //         result.push_back(countOne);
    //     }

    //     return result;
    // }


    // DP Approach(O(n)) Complexity:

        if(n == 0) return {0};
        vector<int> resultDP(n+1, 0);
        resultDP[0] = 0;
        resultDP[1] = 1;

        for(int i = 2; i<=n; i++){
            resultDP[i] = resultDP[i/2] + (i % 2);
        }

        return resultDP;
    }
};