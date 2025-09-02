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
    // void solve(TreeNode* node, int targetSum, vector<vector<int>>& result, vector<int> temp){
    //     if(node == nullptr) return;

    //     temp.push_back(node->val);

    //     if(!node->left && !node->right){
    //         if(targetSum == node->val){
    //             result.push_back(temp);
    //         }
    //     }

    //     solve(node->left, targetSum - node->val, result, temp);
    //     solve(node->right, targetSum - node->val, result, temp);
    // }

    // vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    //     vector<vector<int>> result;
    //     vector<int> temp;

    //     solve(root, targetSum, result, temp);

    //     return result;
    // }










    // Passing temp by value into the recursion, meaning at each recursive call, a copy of the vector is made. That works but is inefficient in terms of memory and runtime.

    // Instead, pass temp by reference and then backtrack (pop the last element after recursion).

    void solve(TreeNode* node, int targetSum, vector<vector<int>>& result, vector<int> &temp){
        if(node == nullptr) return;

        temp.push_back(node->val);

        if(!node->left && !node->right){
            if(targetSum == node->val){
                result.push_back(temp);
            }
        }

        solve(node->left, targetSum - node->val, result, temp);
        solve(node->right, targetSum - node->val, result, temp);

        temp.pop_back(); // Undo
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;

        solve(root, targetSum, result, temp);

        return result;
    }

};