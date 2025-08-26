class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxLen = DBL_MIN;
        int result = 0;

        for(auto &vec: dimensions){
            int l = vec[0];
            int w = vec[1];
            double diagonalLen = sqrt((l*l) + (w*w));

            if(diagonalLen > maxLen){
                result = (l*w);
                maxLen = diagonalLen;
            }else if(diagonalLen == maxLen){
                result = max(result, l*w);
            }
        }

        return result;
    }
};