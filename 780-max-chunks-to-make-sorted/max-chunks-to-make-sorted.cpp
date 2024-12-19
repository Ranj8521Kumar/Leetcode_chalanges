class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int chunk = 0;
        int cummulativeSum = 0;
        int sum = 0;

        for(int i = 0; i<n; i++){
            cummulativeSum += i;

            sum += arr[i];

            if(cummulativeSum == sum){
                chunk++;
            }
        }

        return chunk;
    }
};