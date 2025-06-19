//With implementation of next permutation with manual way
class Solution {
public:
    bool nextPermutation(string &str, int n){
        int i = n-2;

        //find out the first decreasing element from right
        while(i >= 0 && str[i] >= str[i+1]){
            i--;
        }

        //check out the next permutation is possible or not
        if(i < 0){
            reverse(str.begin(), str.end());
            return false;
        }

        //find out the an elment that just greater than str[i] from right side
        int j = n-1;
        while(j >= 0 && str[j] < str[i]){
            j--;
        }

        //swap with str[i] with str[j]
        swap(str[j], str[i]);

        //reverse from i+1 to the end
        reverse(str.begin() + i + 1, str.end());
        return true;
    }

    string getPermutation(int n, int k) {
        string str = "";
        for(int i = 1; i<=n; i++){
            str += to_string(i);
        }



        int cnt = 1;
        while(nextPermutation(str, n)){
            cnt++;

            if(cnt == k){
                break;
            }
        }

        return str;
    }
};