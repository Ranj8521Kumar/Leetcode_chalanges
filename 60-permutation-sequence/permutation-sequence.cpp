class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for(int i = 1; i<=n; i++){
            str += to_string(i);
        }

       

        int cnt = 1;
        while(next_permutation(str.begin(), str.end())){
            cnt++;

            if(cnt == k){
                break;
            }
        }

        return str;
    }
};