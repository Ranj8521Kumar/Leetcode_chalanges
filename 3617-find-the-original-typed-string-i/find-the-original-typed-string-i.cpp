class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int result = 0;

        int i = 0;
        int j;
        for(j = 0; j<n; j++){
            if(word[i] != word[j]){
                result += (j - i - 1);
                i = j;
            }
        }

        result += (j - i - 1);

        return result + 1;
    }
};