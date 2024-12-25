class Solution {
public:
//using buttom-up approach with constant space complexity
    int fib(int n) {
        if(n <= 1) return n;

        int a = 0; 
        int b = 1;

        int c;

        //total number of iteration equal to (n-1)
        for(int i = 1; i<n; i++){
            c = a+b;
            a = b;
            b = c;
        }

        return c;
    }
};