class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>> pq(nums.begin(), nums.end());

        // int cnt = 0;
        // int ans = INT_MIN;
        // while(!pq.empty()){
        //     int x = pq.top();
        //     pq.pop();

        //     cnt++;
        //     if(cnt == k){
        //         ans = x;
        //         break;
        //     }
        // }

        // return ans;



        // Another more Optimized Approach: using mean heap that contains only k largest Number
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &it: nums){
            pq.push(it);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};