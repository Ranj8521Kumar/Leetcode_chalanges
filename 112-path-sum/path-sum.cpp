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
    // First Approach(sum is passed by Reference, so need to rescusive undo/backtrack, for each recursive call, it has It's changes to original value of sum, so, when the function calls end, we have to explicitly undo/backtrack)
    bool solve(TreeNode* node, int targetSum, int &sum){

        if(node == nullptr) return false;

        sum = sum + node->val; // Add current node value(do)

        if(!node->left && !node->right){
            if(targetSum == sum) return true;
        }

        bool found = (solve(node->left, targetSum, sum) || solve(node->right, targetSum, sum)); // explore
        
        sum -= node->val; // Backtrack(undo)
        return found;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root, targetSum, sum);
    }



    // Another Approach(sum is passed by value, so no need to rescusive undo/backtrack, for each recursive call, it has It's own local copy, that resets automatically, when the function calls end):
    // bool solve(TreeNode* node, int targetSum, int sum){

    //     if(node == nullptr) return false;

    //     sum = sum + node->val; // Add current node value(do)

    //     if(!node->left && !node->right){
    //         if(targetSum == sum) return true;
    //     }

    //     return (solve(node->left, targetSum, sum) || solve(node->right, targetSum, sum)); // explore
    // }

    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     int sum = 0;
    //     return solve(root, targetSum, sum);
    // } 
};