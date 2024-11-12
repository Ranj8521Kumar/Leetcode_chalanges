class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        vector<int> maxBeautyUpToPrice, prices;
        int maxBeauty = 0;
        
        for (auto& item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            prices.push_back(item[0]);
            maxBeautyUpToPrice.push_back(maxBeauty);
        }
        
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i)
            sortedQueries.push_back({queries[i], i});
        
        sort(sortedQueries.begin(), sortedQueries.end());
        
        vector<int> result(queries.size());
        for (auto& query : sortedQueries) {
            int q = query.first, index = query.second;
            auto it = upper_bound(prices.begin(), prices.end(), q);
            result[index] = (it == prices.begin()) ? 0 : maxBeautyUpToPrice[it - prices.begin() - 1];
        }
        
        return result;
    }
};