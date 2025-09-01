class Solution {
public:
    int catalan(int n){
        if(n <= 1) return 1;

        int res = 0;
        for(int i = 0; i<n; i++){
            res += catalan(i) * catalan(n - i - 1);
        }

        return res;

    }

    int numTrees(int n) {
        return catalan(n);
    }
};