// class Solution {
// public:
//     void solve(vector<int>& nums, int i, set<vector<int>> &st, vector<int>& temp){
//         if(i >= nums.size()){
//             st.insert(temp);
//             return;
//         }

//         //take current element
//         temp.push_back(nums[i]);
//         solve(nums, i+1, st, temp);

//         //backtrack
//         temp.pop_back();
//         solve(nums, i+1, st, temp);
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         // Using backtracking:
//         int n = nums.size();
//         vector<int> temp;
//         set<vector<int>> st;
//         sort(nums.begin(), nums.end());

//         solve(nums, 0, st, temp);

//         vector<vector<int>> result(st.begin(), st.end());

//         return result;
//     }
// };



// ----------------------------------------------- //

//Without using set
class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>> &result, vector<int>& temp){
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }

        //take current element
        temp.push_back(nums[i]);
        solve(nums, i+1, result, temp);

        //backtrack
        temp.pop_back();


        // Skip dublicates:
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;

        // Not take current element
        solve(nums, i+1, result, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Using backtracking:
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());

        solve(nums, 0, result, temp);

        return result;
    }
};