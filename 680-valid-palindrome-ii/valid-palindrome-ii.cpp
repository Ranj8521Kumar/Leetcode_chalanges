class Solution {
public:
    bool validPalindrome(string s) {
        unordered_map<char, int> mpp;

        for(auto &ch: s){
            mpp[ch]++;
        }

        int oddCount = 0;
        for(auto &it: mpp){
            if(it.second % 2 != 0){
                oddCount++;
                if(oddCount > 2){
                    return false;
                }
            }
        }

        int n = s.size();
        //Skip from right Side:
        int i = 0;
        int j = n-1;
        int cnt = 0;

        while(i<=j){
            if(s[i] != s[j]){
                cnt++;
                j--;
            }else{
                i++;
                j--;
            }
        }

        if(cnt <= 1) return true;

        //Skip from right Side:
        i = 0;
        j = n-1;
        cnt = 0;

        while(i<=j){
            if(s[i] != s[j]){
                cnt++;
                i++;
            }else{
                i++;
                j--;
            }
        }

        if(cnt <= 1) return true;

        
        return false;
    }
};