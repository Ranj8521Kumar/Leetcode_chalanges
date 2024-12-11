class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<pair<int, int>> intervals;

        for(auto num: nums){
            intervals.push_back({num - k, num + k});
        }

        sort(intervals.begin(), intervals.end());

        queue<int> q;

        int maxBeauty = 0;

        for(auto &pair: intervals){
            while(!q.empty() && q.front()<pair.first){
                q.pop();
            }

            q.push(pair.second);
            maxBeauty = max(maxBeauty, (int)q.size());
        }

        return maxBeauty;
    }
};