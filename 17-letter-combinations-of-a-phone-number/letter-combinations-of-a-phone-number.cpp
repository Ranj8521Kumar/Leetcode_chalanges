class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> result;
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";


        string comb = "";

        for(int i = 0; i<n; i++){
            comb += mpp[digits[i]];
        }

        if(n == 1){
            int m = mpp[digits[0]].size();
            for(int i = 0; i<m; i++){
                result.push_back(string(1, comb[i]));
            }
        }else if(n == 2){
            int m = mpp[digits[0]].size();
            int p = mpp[digits[1]].size();

            for(int i = 0; i<m; i++){
                for(int j = m; j<p+m; j++){
                    result.push_back(string(1, comb[i]) + string(1, comb[j]));
                }
            }
        }else if(n == 3){
            int m = mpp[digits[0]].size();
            int p = mpp[digits[1]].size();
            int q = mpp[digits[2]].size();

            for(int i = 0; i<m; i++){
                for(int j = m; j<p+m; j++){
                    for(int k = p + m; k<q+p+m; k++){
                        result.push_back(string(1, comb[i]) + string(1, comb[j]) + string(1, comb[k]));
                    }
                }
            }
        }else{
            int m = mpp[digits[0]].size();
            int p = mpp[digits[1]].size();
            int q = mpp[digits[2]].size();
            int r = mpp[digits[3]].size();
            

            for(int i = 0; i<m; i++){
                for(int j = m; j<p+m; j++){
                    for(int k = p + m; k<q+m+p; k++){
                        for(int l = p + m + q; l<r+p+m+q; l++){
                            result.push_back(string(1, comb[i]) + string(1, comb[j]) + string(1, comb[k]) + string(1, comb[l]));
                        }
                    }
                }
            }
        }

        return result;
    }
};