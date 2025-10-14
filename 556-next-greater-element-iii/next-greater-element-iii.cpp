class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int num = n;
        
        while(num > 0){
            int digit = num % 10;
            digits.push_back(digit);
            num /= 10;
        }

        reverse(digits.begin(), digits.end());

        int m = digits.size();
        int i = m-2;

        while(i >= 0 && digits[i] >= digits[i+1]) i--;

        if(i<0) return -1;

        int j = m-1;
        while(digits[j] <= digits[i]){
            j--;
        }

        swap(digits[i], digits[j]);

        reverse(digits.begin() + i + 1, digits.end());        

        long long gNum = 0;
        for(int i = 0; i<m; i++){
            gNum = gNum * 10 + 1LL*digits[i];

            if(gNum > INT_MAX) return -1;
        }

        return gNum;
    }
};