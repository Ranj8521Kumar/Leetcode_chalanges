class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        //Brute Force Approach
        int n = nums.size();
        vector<int> result;
        vector<pair<int, int>> vec;

        for(int i = 0; i<n; i++){
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end(), [&](auto a, auto b){
            return a.first > b.first;
        });

        sort(vec.begin(), vec.begin() + k, [&](auto a, auto b){
            return a.second < b.second;
        });

        for(int i = 0; i<k; i++){
            result.push_back(vec[i].first);
        }

        return result; 
    }
};