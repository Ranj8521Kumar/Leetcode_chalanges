/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int row, int col, map<int, vector<pair<int, int>>> &mpp){
        if(!root) return;

        mpp[col].push_back({row, root->val});
        solve(root->left, row+1, col-1, mpp);
        solve(root->right, row+1, col+1, mpp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mpp;
        vector<vector<int>> result;

        solve(root, 0, 0, mpp);

        for(auto &it: mpp){
            auto &vec = it.second;
            sort(vec.begin(), vec.end());

            vector<int> temp;
            for(auto &pair: vec){
                temp.push_back(pair.second);
            }

            result.push_back(temp);
        }

        return result;
    }
};