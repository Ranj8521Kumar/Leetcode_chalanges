class Solution {
public:
    int binarySearch(int low, int high, vector<int> &prefix, int target){
        int ans = -1;
        int base = (low == 0) ? 0 : (prefix[low - 1]);

        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(prefix[mid] - base >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        // int n = nums.size();
        // int i = 0;
        // int ans = INT_MAX;
        // int sum = 0;

        // for(int j = 0; j<n; j++){
        //     sum += nums[j];

        //     while(sum >= target){
        //         ans = min(ans, j - i + 1);
        //         sum -= nums[i];
        //         i++;
        //     }
        // }

        // return ans == INT_MAX ? 0 : ans;




        // Let's try to solve this question for O(nlogn) time complexity as mention in the question:
        int n = nums.size();
        vector<int> prefix;

        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            prefix.push_back(sum);
        }

        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            int idx = binarySearch(i, n-1, prefix, target);

            if(idx != -1){
                 ans = min(ans, idx - i + 1);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};