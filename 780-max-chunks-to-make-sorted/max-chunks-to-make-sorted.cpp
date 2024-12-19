class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxLeft = arr[0];
        int count = 0;

        for(int i = 0; i<n; i++){
            maxLeft = max(maxLeft, arr[i]);
            if(maxLeft == i){
                count++;
            }
        }

        return count;
    }
};