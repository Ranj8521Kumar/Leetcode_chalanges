class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // This Approach through TLE:

        // long long l = (long long)left;
        // long long r = (long long)right;

        // long long result = 0;
        // result |= (long long)l;

        // l = l + 1;
        // long long mid = (l + r) / 2;
        // long long m = mid;

        // while(l <= mid && r >= m){
        //     if(result == 0) return 0;
        //     result &= l;
        //     result &= r;
        //     result &= m;
        //     m++;
            
        //     l++;
        //     r--;
        // }

        // return (int)result;



        // Optimized Approach:
        int shift = 0;
        while(left < right){ // shift untill left = right or till same prefix for left and right
            left >>= 1;
            right >>= 1;

            shift++;
        }

        return left << shift;
    }
};