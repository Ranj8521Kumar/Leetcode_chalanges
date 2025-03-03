class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        unordered_map<int, int> temp;

        // Store values from nums1 in the map
        for (const auto& pair : nums1) {
            temp[pair[0]] = pair[1];
        }

        // Merge values from nums2 into the map
        for (const auto& pair : nums2) {
            temp[pair[0]] += pair[1];
        }

        // Convert the map back to a sorted 2D vector
        for (const auto& pair : temp) {
            result.push_back({pair.first, pair.second});
        }

        sort(result.begin(), result.end());
        return result;
    }
};