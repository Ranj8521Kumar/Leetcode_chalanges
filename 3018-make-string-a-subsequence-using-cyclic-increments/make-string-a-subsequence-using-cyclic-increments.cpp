class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0; // Two pointers

        while (i < str1.length() && j < str2.length()) {
            // Check if characters match or if incrementing str1[i] modulo 26 matches str2[j]
            if (str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 == (str2[j] - 'a')) {
                j++;
            }
            if (j == str2.length()) {
                return true;
            }
            i++;
        }

        return false;
    }
};
