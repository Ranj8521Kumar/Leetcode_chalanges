class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 0;
        int n = digits.size();

        result.push_back((digits[n-1] + 1) % 10);
        carry = (digits[n-1] + 1) / 10;

        for(int i = n-2; i>=0; i--){
            result.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }

        if(carry != 0){
            result.push_back(carry);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};