class Solution {
public:
//Brute force Solution //time limit error
    // string generateBaseK(long long num, int k){
    //     string baseKNum = "";

    //     while(num != 0){
    //         int digit = num % k;
    //         baseKNum += to_string(digit);

    //         num /= k;
    //     }

    //     return baseKNum;

    // }

    // bool palindrome(const string &str){

    //     int i = 0; 
    //     int j = str.size() - 1;

    //     while(i <= j){
    //         if(str[i] != str[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }

    //     return true;
    // }

    // long long kMirror(int k, int n) {
    //     int count = 0;
    //     long long sum = 0;
    //     long long currNum = 1;
    //     while(count != n){
    //         if(palindrome(to_string(currNum)) && palindrome(generateBaseK(currNum, k))){
    //             count++;
    //             sum += currNum;
    //         }

    //         currNum++;
    //     }

    //     return sum;
    // }


//Optimized Solution
    string generateBaseK(long long num, int k){
        string baseKNum = "";

        while(num != 0){
            int digit = num % k;
            baseKNum += to_string(digit);

            num /= k;
        }

        return baseKNum;

    }

    bool palindrome(const string &str){

        int i = 0; 
        int j = str.size() - 1;

        while(i <= j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1;

        while(n > 0){
            int halfLength = (L+1)/2;
            int minHalfNum = pow(10, (halfLength - 1));
            int maxHalfNum = pow(10, halfLength) - 1;

            for(int i = minHalfNum; i<=maxHalfNum; i++){
                string pal;
                string firstHalf = to_string(i);
                string secondHalf = firstHalf;
                reverse(secondHalf.begin(), secondHalf.end());

                if(L % 2 == 0){
                    pal = firstHalf + secondHalf;
                }else{
                    pal = firstHalf + secondHalf.substr(1);
                }

                long long num = stoll(pal);
                string baseK = generateBaseK(num, k);

                if(palindrome(baseK)){
                    sum += num;
                    n--;

                    if(n == 0){
                        break;
                    }
                }
            }

            L++;
        }

        return sum;
    }
};