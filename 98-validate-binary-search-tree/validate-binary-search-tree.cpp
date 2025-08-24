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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        queue<tuple<TreeNode*, long, long>> que;
        que.push({root, LONG_MIN, LONG_MAX});

        while(!que.empty()){
            auto [node, minValue, maxValue] = que.front();
            que.pop();

            if(node->val <= minValue || node->val >= maxValue) return false;

            if(node->left){
                que.push({node->left, minValue, node->val});
            }

            if(node->right){
                que.push({node->right, node->val, maxValue});
            }
        }

        return true;
    }
};