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
    int DFS(TreeNode* root){
        if(root ==  nullptr){
            return 0;
        }

        int left = DFS(root->left);
        int right = DFS(root->right);

        return max(right, left) + 1;
    }

    int maxDepth(TreeNode* root) {
        return DFS(root);
    }
};