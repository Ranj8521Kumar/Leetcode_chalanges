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
    bool solve(TreeNode* node, int targetSum){

        if(node == nullptr) return false;

        if(!node->left && !node->right){
            if(targetSum == node->val) return true;
        }
        
        targetSum = targetSum - node->val;

        return (solve(node->left, targetSum) || solve(node->right, targetSum));
        
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};