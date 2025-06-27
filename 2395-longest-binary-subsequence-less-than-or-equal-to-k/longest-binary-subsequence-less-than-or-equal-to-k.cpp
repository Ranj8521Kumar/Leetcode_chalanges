class Solution {
public:
    //Simple recursion but memory limit exceed error
    // int solve(string s, int k, int i){
    //     if(i < 0){
    //         return 0;
    //     }

    //     int bit = s[i] - '0';

    //     int val = bit * pow(2, (s.size()-i-1));

    //     int take = 0;
    //     int notTake = solve(s, k, i-1);

    //     if(val <= k){
    //         take = 1 + solve(s, k - val, i-1);
    //     }

    //     return max(take, notTake);
        
    // }

    // int longestSubsequence(string s, int k) {
    //     int n = s.size();
    //     int length = solve(s, k, n-1);
       

    //     return length;
    // }


    

    //Optimized approach
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int length = 0;
        int powerValue = 1; //pow(2, 0)

        for(int i = n-1; i>=0; i--){
            if(s[i] == '0'){
                length++;
            }else{
                if(powerValue <= k){
                    k -= powerValue;
                    length++;
                }
            }

            if(powerValue <= k){
                powerValue *= 2;
            }
        }
       
        return length;
    }
};