class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Hash Map + Sliding Window Approach:
        unordered_map<char, int> mpp;
        int n = s.size();

        int result = 0;
        int i = 0;
        int j;
        for(j = 0; j<n; j++){
            mpp[s[j]]++;

            if(mpp[s[j]] > 1){
                result = max(result, j - i);
                while(mpp[s[j]] > 1){
                    mpp[s[i]]--;
                    i++;
                }
            }
        }

        result = max(result, j - i); // for last substring

        return result;
    }
};