class Solution {
public:
    // Recursive Approach:
    // string makeString(string str){
    //     string result;

    //     int n = str.size();
    //     int cnt = 1;
    //     for(int i = 1; i<n; i++){
    //         if(str[i] == str[i-1]){
    //             cnt++;
    //         }else{
    //             result.push_back(cnt + '0');
    //             result.push_back(str[i-1]);

    //             cnt = 1;
    //         }
    //     }

    //     result.push_back(cnt + '0');
    //     result.push_back(str[n-1]);

    //     return result;
    // } 

    // string countAndSay(int n) {
    //     if(n == 1) return "1";
    //     return makeString(countAndSay(n-1));
    // }







    // Iterative Approach:

    string makeString(string str){
        string result = "";

        int n = str.size();
        int cnt = 1;
        for(int i = 1; i<n; i++){
            if(str[i] == str[i-1]){
                cnt++;
            }else{
                result += to_string(cnt);
                result.push_back(str[i-1]);

                cnt = 1;
            }
        }

        result += to_string(cnt);
        result.push_back(str[n-1]);

        return result;
    } 

    string countAndSay(int n) {
        if(n == 1) return "1";
        string initialString = "1";

        for(int i = 2; i<=n; i++){
            initialString = makeString(initialString);
        }

        return initialString;
    }
};