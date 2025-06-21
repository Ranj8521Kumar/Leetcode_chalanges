class Solution {
public:
    void dfsBacktrack(int i, int target, vector<int>& candidates, int n, vector<int>& current, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(current);
            return;
        }

        if(i >= n || target < 0){
            return;
        }

        //include current element
        current.push_back(candidates[i]);
        dfsBacktrack(i, target - candidates[i], candidates, n, current, result);
        current.pop_back();

        // exclude current element
        dfsBacktrack(i+1, target, candidates, n, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<int> current;
        vector<vector<int>> result;

        int i = 0;

        dfsBacktrack(i, target, candidates, n, current, result);

        return result;
    }
};