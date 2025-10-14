class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int result = 0;

        int maxElement = *max_element(piles.begin(), piles.end());

        if(n == h) return maxElement;

        int low = 1;
        int high = maxElement;

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long hours = 0;
            for(int i = 0; i<n; i++){
                if(piles[i] <= mid){
                    hours += 1LL*1;
                }else{
                    hours += ((piles[i] % mid == 0)?1LL*(piles[i] / mid):1LL*(piles[i] / mid) + 1);
                }
            }

            if(hours <= 1LL*h){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return result;
    }
};