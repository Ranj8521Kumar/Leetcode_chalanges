class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool isNeg = false;
        int i;
        for(i = 0; i<n; i++){
            if(s[i] == ' '){
                continue;
            }else{
                break;
            }
        }

        if(i < n){
            if(s[i] == '-'){
                isNeg = true;
                i++;
            }else if(s[i] == '+'){
                i++;
            }
        }

        long long num = 0;
        while(i < n && isdigit(s[i])){
            num = num*10 + (s[i] - '0');

            if(!isNeg && num > INT_MAX){
                return INT_MAX;
            }

            if(isNeg && -num < INT_MIN){
                return INT_MIN;
            }
            i++;
        }

        if(isNeg){
            return -num;
        }

        return num;
    }
};