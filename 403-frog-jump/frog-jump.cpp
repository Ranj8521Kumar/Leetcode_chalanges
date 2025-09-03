class Solution {
public:
    // Let's Memoize it:
    int n;
    int t[2001][2001];
    bool solve(vector<int>& stones, int lastStone, int k, int currStone, unordered_map<int, int> &mpp){
        if(k <= 0) return false;

        if(mpp.find(currStone) == mpp.end()) return false;
        if(currStone == lastStone) return true;

        int i = mpp[currStone];

        int nextStone = k + currStone;
        if(currStone == nextStone) return false;

        if(t[i][k] != -1) return t[i][k];

        return t[i][k] = solve(stones, lastStone, k-1, nextStone, mpp) ||
                solve(stones, lastStone, k, nextStone, mpp) || 
                solve(stones, lastStone, k+1, nextStone, mpp);

    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        memset(t, -1, sizeof(t));
        int lastStone = stones[n-1];
        unordered_map<int, int> mpp;

        for(int i = 0; i<n; i++){
            mpp[stones[i]] = i;
        }

        return solve(stones, lastStone, 1, 0, mpp);
    }
};