class Solution {
public:
    void solve(vector<int>& nums, int i, set<vector<int>> &st, vector<int>& temp){
        if(i >= nums.size()){
            st.insert(temp);
            return;
        }

        //take current element
        temp.push_back(nums[i]);
        solve(nums, i+1, st, temp);

        //backtrack
        temp.pop_back();
        solve(nums, i+1, st, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Using backtracking:
        int n = nums.size();
        vector<int> temp;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());

        solve(nums, 0, st, temp);

        vector<vector<int>> result(st.begin(), st.end());

        return result;
    }
};