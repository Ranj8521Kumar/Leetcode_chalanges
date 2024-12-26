class Solution {
public:
//Buttom - Up Approach
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end());

        int longest = 1;
        vector<int>  dp(n+1, 1);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            longest = max(longest, dp[i]);
        }

        return longest;
    }
};