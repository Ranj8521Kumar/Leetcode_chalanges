class Solution {
public:
    int t[100001];
    int countOnes(int i){
        if(i == 0) return 0;

        if(t[i] != -1) return t[i];

        return t[i] = countOnes(i/2) + i%2;
    }


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


    // // DP Approach(O(n)) Complexity:
        // vector<int> resultDP(n+1, 0);

        // for(int i = 1; i<=n; i++){
        //     resultDP[i] = resultDP[i/2] + (i % 2);
        // }

        // return resultDP;



    

    // Recursive Approach:
        vector<int> result;
        memset(t, -1, sizeof(t));

        for(int i = 0; i<=n; i++){
            result.push_back(countOnes(i));
        }

        return result;
    }
};