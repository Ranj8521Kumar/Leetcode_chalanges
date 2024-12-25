class Solution {
public:
// using buttom up approach with constant space complexity
    int solve(int n, vector<int>& arr){
        if(n < 0){
            return 0;
        }

        if(n <= 2){
            return n;
        }

        int a = 1; // i - 2
        int b = 2; // i - 1
        int c;
        for(int i = 3; i<=n; i++){
            c = a + b;

            a = b;
            b = c;
        }

        return c;
    }

    int climbStairs(int n) {
        vector<int> arr(n+1, -1);
    
        return solve(n, arr);
    }
};