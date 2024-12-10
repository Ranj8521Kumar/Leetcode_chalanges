class Solution {
private:
    bool check(string str){
        int n = str.size();
        for(int i = 1; i<n; i++){
            if(str[i-1] != str[i]){
                return 0;
            }
        }
        return 1;
    }

public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string, int> mpp;

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                mpp[s.substr(i, j - i + 1)]++;
            }
        }

        int maxSpecSubString  = -1;
        for(auto str: mpp){
            if(str.second >= 3 && check(str.first)){
                int n = str.first.size();
                maxSpecSubString = max(maxSpecSubString, n);
            }
        }

        return maxSpecSubString;
    }
};