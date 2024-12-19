class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> suffixMin(n, INT_MAX);
        int minValue = INT_MAX;

        for(int i = n-1; i>=0;  i--){
            minValue = min(minValue, arr[i]);
            suffixMin[i] =  minValue;
        }

        int maxValue;
        int count = 0;
        
        for(int i = 0; i<n; i++){
            maxValue = (i == 0)?-1:max(maxValue, arr[i-1]);
            if(maxValue  <= suffixMin[i]){
                count++;
            }
        }

        return count;
    }
};