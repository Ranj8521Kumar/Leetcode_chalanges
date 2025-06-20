class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //Using backTrack approach
        int n = digits.size();

        if(n == 0){
            return {};
        }

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

        string path;

        function<void(int)> backtrack = [&](int idx){
            if(idx == n){
                result.push_back(path);
                return;
            }

            for(auto &ch: mpp[digits[idx]]){
                path.push_back(ch);
                backtrack(idx + 1);
                path.pop_back();
            }
        };
        
        backtrack(0);
        return result;
    }
};