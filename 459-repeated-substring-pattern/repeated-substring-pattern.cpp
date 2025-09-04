class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string temp = s + s;

        if(temp.substr(1, 2*n - 2).find(s) != string::npos){
            return true;
        }

        return false;
    }
};