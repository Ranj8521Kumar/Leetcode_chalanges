class Solution {
public:
    long long flowerGame(int n, int m) {
        // Brute Force Approach that may be give TLE:
        // long long result = 0;
        // for(int i = 1; i <= m; i++){
        //     for(int j = 1; j <= n; j++){
        //         if((i + j) % 2 != 0){
        //             result++;
        //         }
        //     }
        // }

        // return result;


        // Second Approach:
        // int o1 = (n % 2 == 0) ? n/2 : (n + 1)/2;
        // int e1 = (n % 2 == 0) ? n/2 : (n)/2;


        // int o2 = (m % 2 == 0) ? m/2 : (m + 1)/2;
        // int e2 = (m % 2 == 0) ? m/2 : (m)/2;

        // long long result = ((long long)o1 * (long long)e2) + ((long long)e1 * (long long)o2);

        // return result;


        // Thrird Approach ---> copy of the second:
        return 1LL * ((n + 1)/2) * (m / 2) + 1LL * (n / 2) * ((m + 1) / 2);
    }
};