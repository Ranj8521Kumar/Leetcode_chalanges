class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> suffixMin(n+1, INT_MAX);
        int minValue = INT_MAX;

        for(int i = n-1; i>=0;  i--){
            minValue = min(minValue, arr[i]);
            suffixMin[i] =  minValue;
        }

        int maxValue = arr[0];
        int count = 0;
        
        for(int i = 0; i<n; i++){
            maxValue = max(maxValue, arr[i]);
            if(maxValue  <= suffixMin[i+1]){
                count++;
            }
        }

        return count;
    }
};