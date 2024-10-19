class Solution {
public:
    string invert(string str) {
        for (auto &ch : str) {
            if (ch == '0') {
                ch = '1';
            } else {
                ch = '0';
            }
        }
        return str;
    }

    string Sn(int n) {
        if (n == 1) {
            return "0";
        } else {
            string prev = Sn(n - 1);
            return prev + "1" + reverse(invert(prev));
        }
    }

    string reverse(string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }

    char findKthBit(int n, int k) {
        string str = Sn(n);
        return str[k - 1];
    }
};
