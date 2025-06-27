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

    bool backtrack(string s, vector<bool> &canUse, vector<int> &reqFreq, string &result, string &curr, int maxLen, int k){
        if(curr.size() == maxLen){
            if(isSubsequence(s, curr, k)){
                result = curr;
                return true;
            }

            return false;
        }

        for(int i = 25; i>=0; i--){
            if(canUse[i] == false || reqFreq[i] == 0){
                continue;
            }

            //Do
            char ch = i + 'a';
            curr.push_back(ch);
            reqFreq[i]--;

            //Explore
            if(backtrack(s, canUse, reqFreq, result, curr, maxLen, k)){
                return true;
            }

            //Undo
            curr.pop_back();
            reqFreq[i]++;
        }

        return false;
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

        for(int len = maxLen; len>=0; len--){
            vector<int> tempReqFreq = reqFreq;
            if(backtrack(s, canUse, tempReqFreq, result, curr, len, k) == true){
                return result;
            }
        }

        return result;

    }
};