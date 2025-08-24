class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        // Let's Apply Sliding Window Technique:
        int n = arr.size();
        int result = 0;
        int zeroCount = 0;
        int i = 0;
        bool hasZero = false;
        for(int j = 0; j<n; j++){
            if(arr[j] == 0){
                zeroCount++;
                hasZero = true;
            }
            
            while(zeroCount > 1){
                if(arr[i] == 0){
                    zeroCount--;
                }
                i++;
            }

            result = max(result, (j - i));
        }

        if(!hasZero) return n-1;

        return result;
    }
};