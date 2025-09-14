class Solution {
public:
    long makePalindrome(long half, bool isEven){
        long result = half;

        if(isEven == false){
            half = half / 10;
        }

        while(half > 0){
            long digit = half % 10;
            result = (result * 10) + digit;

            half = half/10;
        }

        return result;
    }

    string nearestPalindromic(string n) {
        int L = n.size();
        int mid = L/2;

        int firstHalfLength = (L%2 == 0) ? mid: (mid + 1); // take half of the string

        vector<long> possibePalindrome;
        long half = stol(n.substr(0, firstHalfLength));
        possibePalindrome.push_back(makePalindrome(half, L%2 == 0));
        possibePalindrome.push_back(makePalindrome(half + 1, L%2 == 0));
        possibePalindrome.push_back(makePalindrome(half - 1, L%2 == 0));
        possibePalindrome.push_back((long)pow(10, L) + 1);
        possibePalindrome.push_back((long)pow(10, L-1) - 1);


        long result = LONG_MAX;
        long diff = LONG_MAX;
        long originalNum = stol(n);

        for(auto &it: possibePalindrome){
            if(it == originalNum) continue;
            if(abs(it - originalNum) < diff){
                diff = abs(it - originalNum);
                result = it;
            }else if(abs(it - originalNum) == diff){
                result = min(result, it);
            }
        }

        return to_string(result);

    }
};