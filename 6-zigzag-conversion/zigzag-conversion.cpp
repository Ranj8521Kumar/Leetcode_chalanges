class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }


        vector<vector<char>> temp(numRows);
        int idx = 0; int d = 1; // 1 for down and -1 for up
        for(auto ch: s){
            temp[idx].push_back(ch);

            if(idx == 0){
                d = 1;
            }if(idx == numRows - 1){
                d = -1;
            }

            idx += d;
        }

        string result;
        for(auto &vec: temp){
            for(auto &ch: vec){
                result.push_back(ch);
            }
        }

        return result;
    }
};