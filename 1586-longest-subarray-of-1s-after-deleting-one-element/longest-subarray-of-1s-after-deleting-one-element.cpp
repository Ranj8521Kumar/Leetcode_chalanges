class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        // Let's Apply Sliding Window Technique:
        int n = arr.size();
        int result = 0;
        int zeroCount = 0;
        int oneCount = 0;
        int i = 0;
        bool hasZero = false;
        for(int j = 0; j<n; j++){
            while(zeroCount > 1){
                if(arr[i] == 0){
                    zeroCount--;
                }else{
                    oneCount--;
                }

                i++;
            }

            

            if(arr[j] == 0){
                zeroCount++;
                hasZero = true;
            }else{
                oneCount++;
            }

            result = max(result, oneCount);
        }

        if(!hasZero) return n-1;

        return result;
    }
};