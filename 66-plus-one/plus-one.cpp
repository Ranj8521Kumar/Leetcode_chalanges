class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // vector<int> result;
        // int carry = 0;
        // int n = digits.size();

        // result.push_back((digits[n-1] + 1) % 10);
        // carry = (digits[n-1] + 1) / 10;

        // for(int i = n-2; i>=0; i--){
        //     result.push_back((digits[i] + carry) % 10);
        //     carry = (digits[i] + carry) / 10;
        // }

        // if(carry != 0){
        //     result.push_back(carry);
        // }

        // reverse(result.begin(), result.end());

        // return result;


        

        // Without taking an extra space:
        int carry = 0;
        int n = digits.size();

        for(int i = n-1; i>=0; i--){
            if(digits[i] < 9){
                digits[i] = digits[i] + 1;
                return digits;
            }

            digits[i] = 0;
            carry = 1;
        }

        if(carry != 0){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};