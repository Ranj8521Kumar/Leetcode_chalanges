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
    bool solve(TreeNode* node, int targetSum, int sum){

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



    // Another Approach:
    // bool solve(TreeNode* node, int targetSum, int &sum){

    //     if(node == nullptr) return false;

    //     sum = sum + node->val; // Add current node value(do)

    //     if(!node->left && !node->right){
    //         if(targetSum == sum) return true;
    //     }

    //     bool found = (solve(node->left, targetSum, sum) || solve(node->right, targetSum, sum)); // explore
        
    //     sum -= node->val; // Backtrack(undo)
    //     return found;
    // }

    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     int sum = 0;
    //     return solve(root, targetSum, sum);
    // }
    
};