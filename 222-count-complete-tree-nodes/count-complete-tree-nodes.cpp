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
    int getDepth(TreeNode* root){
        int depth = 0;
        while(root){
            root = root->left;
            depth++;
        }

        return depth;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);

        if(leftDepth == rightDepth){
            return (1 << leftDepth) + countNodes(root->right);
        }else{
            return (1 << rightDepth) + countNodes(root->left);
        }
    }
};