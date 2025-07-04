class Solution {
public:
    char kthCharacter(int k) {
        string result = "a";

        while(result.size() <= k){
            int n = result.size();
            for(int i = 0; i<n; i++){
                char ch = result[i];
                if(ch == 'z'){
                    result += 'a';
                }else{
                    result += (ch + 1);
                }
            }

        }

        return result[k-1];

    }

};