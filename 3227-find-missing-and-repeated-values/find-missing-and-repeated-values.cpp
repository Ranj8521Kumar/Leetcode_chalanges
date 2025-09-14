class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // Apply Mathematics:
        // int n = grid.size();
        // n *= n;
        // int gridSum = 0;
        // long long gridSquareSum = 0;
        // for(auto &row: grid){
        //     for(auto &it: row){
        //         gridSum += it;
        //         gridSquareSum += (it*it);
        //     }
        // }

        // int totalSum = (n*(n + 1)) / 2;
        // long long totalSquareSum = (int)((1LL*n*(n + 1)*(2*n + 1)) / 6);

        // int x = totalSum - gridSum; // a-b
        // int y = totalSquareSum - gridSquareSum; // a^2 - b^2

        // int a = (x + (y/x))/2;
        // int b = a - x;

        // return {b, a};




        // Another Method Using Xor
        int n = grid.size();
        n *= n;
        int Xor = 0;
        for(auto &row: grid){
            for(auto &it: row){
                Xor ^= it;
            } 
        }

        for(int i = 1; i<=n; i++){
            Xor ^= i;
        }


        // find rightMost set bit of Xor
        int mask = 1; // for spiliting numbers into two groups
        for(int k = 0; k<=31; k++){
            if((Xor & 1) == 1){
                mask = (1 << k);
                break;
            }

            Xor >>= 1;
        }

        int x = 0; int y = 0;
        for(auto &row: grid){
            for(auto &it: row){
                if(it & mask){
                    x ^= it;
                }else{
                    y ^= it;
                }
            } 
        }

        for(int i = 1; i<=n; i++){
            if(i & mask){
                x ^= i;
            }else{
                y ^= i;
            }
        }

        int repetating = 0; int missing = 0;
        for(auto &row: grid){
            for(auto &it: row){
                if(x == it){
                    repetating = x;
                    missing = y;
                    break;
                }

                if(y == it){
                    repetating = y;
                    missing = x;
                    break;
                }
            } 
        }

        return {repetating, missing};
    }
};