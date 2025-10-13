class Solution {
public:
    // bool validPalindrome(string s) {
    //     int n = s.size();
    //     //Skip from right Side:
    //     int i = 0;
    //     int j = n-1;
    //     int cnt = 0;

    //     while(i<=j){
    //         if(s[i] != s[j]){
    //             cnt++;
    //             j--;
    //         }else{
    //             i++;
    //             j--;
    //         }
    //     }

    //     if(cnt <= 1) return true;

    //     // or

    //     //Skip from right Side:
    //     i = 0;
    //     j = n-1;
    //     cnt = 0;

    //     while(i<=j){
    //         if(s[i] != s[j]){
    //             cnt++;
    //             i++;
    //         }else{
    //             i++;
    //             j--;
    //         }
    //     }

    //     if(cnt <= 1) return true;

        
    //     return false;
    // }





// -------------------------------------------------------- //
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }

        return true;
    }


    bool validPalindrome(string s) {
        int n = s.size();
        
        int i = 0; 
        int j = n-1;

        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                return (isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1));
            }
        }

        return true;
    }
};