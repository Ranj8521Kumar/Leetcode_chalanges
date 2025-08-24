class Solution {
public:
    void makeSameLengthString(string &str, int n1, int n2){
        int diff = abs(n1 - n2);
        str = string(diff, '0') + str;
    }

    string addBinary(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();

        string result;
        int carry = 0;

        if(n1 > n2){
            makeSameLengthString(b, n1, n2);
            n2 = b.size();
        }else if(n2 > n1){
            makeSameLengthString(a, n2, n1);
            n1 = a.size();
        }

        for(int i = n1 - 1; i>=0; i--){
            int firsDigit = (a[i] - '0');
            int secondDigit = (b[i] - '0');

            int digit = (firsDigit + secondDigit + carry) % 2;
            result.push_back((digit + '0'));
            carry = (firsDigit + secondDigit + carry) / 2;
        }

        if(carry == 1){
            result.push_back((carry + '0'));
        }

        reverse(result.begin(), result.end());

        return result;
    }
};