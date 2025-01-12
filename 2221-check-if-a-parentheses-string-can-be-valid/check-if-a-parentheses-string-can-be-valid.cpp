class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n%2 != 0) return false;

        stack<int> openIndices;
        stack<int> unlockedIndices;

        for(int i = 0; i<n; i++){
            if(locked[i] == '0'){
                unlockedIndices.push(i);
            }else if(s[i] == '('){
                openIndices.push(i);
            }else{
                if(!openIndices.empty()){
                    openIndices.pop();
                }else if(!unlockedIndices.empty()){
                    unlockedIndices.pop();
                }else{
                    return false;
                }
            }
        }

        while(!openIndices.empty() && !unlockedIndices.empty() && openIndices.top() < unlockedIndices.top()){
            openIndices.pop();
            unlockedIndices.pop();
        }

        if(openIndices.empty() && !unlockedIndices.empty()){
            if(unlockedIndices.size() % 2 != 0){
                return false;
            }else{
                return true;
            }
        }

        return openIndices.empty();
    }
};