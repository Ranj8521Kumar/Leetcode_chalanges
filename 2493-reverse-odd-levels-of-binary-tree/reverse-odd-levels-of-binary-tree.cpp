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
    void solve(TreeNode* Left, TreeNode* Right, int level){
        if(Left == nullptr){
            return;
        }

        if(Right == nullptr){
            return;
        }

        if(level % 2 != 0){
            swap(Left->val, Right->val);
        }

        solve(Left->left, Right->right, level+1);
        solve(Left->right, Right->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left, root->right, 1);

        return root;
    }
};