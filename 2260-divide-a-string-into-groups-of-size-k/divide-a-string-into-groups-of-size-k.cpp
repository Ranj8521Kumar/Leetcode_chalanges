class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
    //     int n = s.size();
    //     vector<string> result;

    //     int cnt = 0;
    //     while(cnt < n){
    //         result.push_back(s.substr(cnt, k));
    //         cnt += k;
    //     }

    //     if(cnt == n) return result;

    //     cnt -= k;
    //     result.pop_back(); //remove last incomplete pushed string

    //     string lastString = "";
    //     while(cnt < n){
    //         lastString += s[cnt];
    //         cnt++;
    //     }

    //     while(lastString.size() < k){
    //         lastString += fill;
    //     }

    //     result.push_back(lastString);

    //     return result;


    //minimize space and time complexity
    vector<string> result;
    int n = s.size();
    for(int i = 0; i<n; i+=k){
        result.push_back(s.substr(i, min(n - i, k)));
    }

    int m = result.back().size();

    if(m < k){
        result.back().append((k - m), fill);
    }

    return result;
    }
};