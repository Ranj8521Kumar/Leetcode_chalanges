class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;
        int n = candidates.size();

        for(int i = 0; i<31; i++){
            int count = 0;
            for(auto it: candidates){
                if(it & (1<<i)){
                    count++;
                }
            }
            result = max(result, count);
        }
        return result;
    }
};