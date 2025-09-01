class Solution {
public:
    int t[20];
    int catalan(int n){
        if(n <= 1) return 1;

        if(t[n] != -1) return t[n];

        int res = 0;
        for(int i = 0; i<n; i++){
            res += catalan(i) * catalan(n - i - 1);
        }

        return t[n] = res;

    }

    int numTrees(int n) {
        memset(t, -1, sizeof(t));

        return catalan(n);
    }
};