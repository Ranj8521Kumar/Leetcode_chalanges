class Solution {
public:
// using buttom up approach
    int solve(int n, vector<int>& arr){
        if(n < 0){
            return 0;
        }

        if(n <= 2){
            return n;
        }

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for(int i = 3; i<=n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];
    }

    int climbStairs(int n) {
        vector<int> arr(n+1, -1);
    
        return solve(n, arr);
    }
};