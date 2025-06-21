class Solution {
public:
//Slightly optimized
    int minimumDeletions(string word, int k) {
        int n = word.size();

        unordered_map<char, int> mpp;
        for(auto &ch: word){
            mpp[ch]++;
        }

        vector<int> freq;
        for(auto &it: mpp){
            freq.push_back(it.second);
        }

        sort(freq.begin(), freq.end());

        int result = INT_MAX;
        int m = freq.size();
        int cummulativeFreq = 0;

        for(int i = 0; i<m; i++){
            int deletion = cummulativeFreq;

            for(int j = m-1; j>i; j--){
                if(abs(freq[j] - freq[i]) > k){
                    deletion += abs(freq[j] - freq[i] - k);
                }
            }

            result = min(result, deletion);
            cummulativeFreq += freq[i];
        }

        return result;
    }
};