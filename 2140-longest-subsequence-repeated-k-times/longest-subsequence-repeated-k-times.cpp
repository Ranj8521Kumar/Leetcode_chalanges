class Solution {
public:
    bool isSubsequence(string &s, string &curr, int k){
        int i = 0;
        int j = 0;
        int n = s.size();
        int l = curr.size();

        while(i < n && j < k*l){
            if(s[i] == curr[j%l]){
                j++;
            }

            i++;
        }

        if(j == k*l){
            return true;
        }

        return false;
    }

    void backtrack(string s, vector<bool> &canUse, vector<int> &reqFreq, string &result, string &curr, int maxLen, int k){
        if(curr.size() > maxLen){
            return;
        }

        if((curr.length() > result.length() ||
            (curr.length() == result.length() && curr > result)) &&
            isSubsequence(s, curr, k)){
            result = curr;
        }

        for(int i = 0; i<26; i++){
            if(canUse[i] == false || reqFreq[i] == 0){
                continue;
            }

            //Do
            char ch = i + 'a';
            curr.push_back(ch);
            reqFreq[i]--;

            //Explore
            backtrack(s, canUse, reqFreq, result, curr, maxLen, k);

            //Undo
            curr.pop_back();
            reqFreq[i]++;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        int maxLen = n / k;

        vector<int> freq(26, 0);
        for(int i = 0; i<n; i++){
            freq[s[i] - 'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> reqFreq(26, 0);
        for(int i = 0; i<26; i++){
            if(freq[i] >= k){
                canUse[i] = true;
                reqFreq[i] = freq[i]/k;
            }
        }

        string curr;
        string result = "";

        backtrack(s, canUse, reqFreq, result, curr, maxLen, k);

        return result;

    }
};